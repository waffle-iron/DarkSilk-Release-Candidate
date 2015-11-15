#include "stormnode.h"
#include "stormnodeman.h"
#include "sandstorm.h"
#include "core.h"
#include "main.h"
#include "sync.h"
#include "util.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>


int CStormnode::minProtoVersion = MIN_SN_PROTO_VERSION;

CCriticalSection cs_stormnodes;
// keep track of the scanning errors I've seen
map<uint256, int> mapSeenStormnodeScanningErrors;
// cache block hashes as we calculate them
std::map<int64_t, uint256> mapCacheBlockHashes;



struct CompareValueOnly
{
    bool operator()(const pair<int64_t, CTxIn>& t1,
                    const pair<int64_t, CTxIn>& t2) const
    {
        return t1.first < t2.first;
    }
};

//Get the last hash that matches the modulus given. Processed in reverse order
bool GetBlockHash(uint256& hash, int nBlockHeight)
{
    if (pindexBest == NULL) return false;

    if(nBlockHeight == 0)
        nBlockHeight = pindexBest->nHeight;

    if(mapCacheBlockHashes.count(nBlockHeight)){
        hash = mapCacheBlockHashes[nBlockHeight];
        return true;
    }

    const CBlockIndex *BlockLastSolved = pindexBest;
    const CBlockIndex *BlockReading = pindexBest;

    if (BlockLastSolved == NULL || BlockLastSolved->nHeight == 0 || pindexBest->nHeight+1 < nBlockHeight) return false;

    int nBlocksAgo = 0;
    if(nBlockHeight > 0) nBlocksAgo = (pindexBest->nHeight+1)-nBlockHeight;
    assert(nBlocksAgo >= 0);

    int n = 0;
    for (unsigned int i = 1; BlockReading && BlockReading->nHeight > 0; i++) {
        if(n >= nBlocksAgo){
            hash = BlockReading->GetBlockHash();
            mapCacheBlockHashes[nBlockHeight] = hash;
            return true;
        }
        n++;

        if (BlockReading->pprev == NULL) { assert(BlockReading); break; }
        BlockReading = BlockReading->pprev;
    }

    return false;
}

CStormnode::CStormnode()
{
    LOCK(cs);
    vin = CTxIn();
    addr = CService();
    pubkey = CPubKey();
    pubkey2 = CPubKey();
    sig = std::vector<unsigned char>();
    activeState = STORMNODE_ENABLED;
    sigTime = GetAdjustedTime();
    lastSnping = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = MIN_PEER_PROTO_VERSION;
    nLastSsq = 0;
    donationAddress = CScript();
    donationPercentage = 0;
    nScanningErrorCount = 0;
    nLastScanningErrorBlockHeight = 0;
    nVotedTimes = 0;    
    nLastPaid = 0;
}

CStormnode::CStormnode(const CStormnode& other)
{
    LOCK(cs);
    vin = other.vin;
    addr = other.addr;
    pubkey = other.pubkey;
    pubkey2 = other.pubkey2;
    sig = other.sig;
    activeState = other.activeState;
    sigTime = other.sigTime;
    lastSnping = other.lastSnping;
    lastTimeSeen = other.lastTimeSeen;
    cacheInputAge = other.cacheInputAge;
    cacheInputAgeBlock = other.cacheInputAgeBlock;
    unitTest = other.unitTest;
    allowFreeTx = other.allowFreeTx;
    protocolVersion = other.protocolVersion;
    nLastSsq = other.nLastSsq;
    donationAddress = other.donationAddress;
    donationPercentage = other.donationPercentage;
    nScanningErrorCount = other.nScanningErrorCount;
    nLastScanningErrorBlockHeight = other.nLastScanningErrorBlockHeight;
    nLastPaid = other.nLastPaid;
    nVotedTimes = other.nVotedTimes;
}

CStormnode::CStormnode(CService newAddr, CTxIn newVin, CPubKey newPubkey, std::vector<unsigned char> newSig, int64_t newSigTime, CPubKey newPubkey2, int protocolVersionIn, CScript newDonationAddress, int newDonationPercentage)
{
    LOCK(cs);
    vin = newVin;
    addr = newAddr;
    pubkey = newPubkey;
    pubkey2 = newPubkey2;
    sig = newSig;
    activeState = STORMNODE_ENABLED;
    sigTime = newSigTime;
    lastSnping = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = protocolVersionIn;
    nLastSsq = 0;
    donationAddress = newDonationAddress;
    donationPercentage = newDonationPercentage;
    nScanningErrorCount = 0;
    nLastScanningErrorBlockHeight = 0;    
    nLastPaid = 0;
    nVotedTimes = 0;    
}

CStormnode::CStormnode(const CStormnodeBroadcast& snb)
{
    LOCK(cs);
    vin = snb.vin;
    addr = snb.addr;
    pubkey = snb.pubkey;
    pubkey2 = snb.pubkey2;
    sig = snb.sig;
    activeState = STORMNODE_ENABLED;
    sigTime = snb.sigTime;
    lastSnping = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = snb.protocolVersion;
    nLastSsq = 0;
    donationAddress = snb.donationAddress;
    donationPercentage = snb.donationPercentage;
    nScanningErrorCount = 0;
    nLastScanningErrorBlockHeight = 0;
    nLastPaid = snb.nLastPaid;
    nVotedTimes = 0;
}

//
// When a new stormnode broadcast is sent, update our information
//
void CStormnode::UpdateFromNewBroadcast(CStormnodeBroadcast& snb)
{
    pubkey2 = snb.pubkey2;
    sigTime = snb.sigTime;
    sig = snb.sig;
    protocolVersion = snb.protocolVersion;
    addr = snb.addr;
    donationAddress = snb.donationAddress;
    donationPercentage = snb.donationPercentage;
    nLastPaid = snb.nLastPaid;
}

//
// Deterministically calculate a given "score" for a Stormnode depending on how close it's hash is to
// the proof of work for that block. The further away they are the better, the furthest will win the election
// and get paid this block
//
uint256 CStormnode::CalculateScore(int mod, int64_t nBlockHeight)
{
    if(pindexBest == NULL) return 0;

    uint256 hash = 0;
    uint256 aux = vin.prevout.hash + vin.prevout.n;

    if(!GetBlockHash(hash, nBlockHeight)) {
        LogPrintf("CalculateScore ERROR - nHeight %d - Returned 0\n", nBlockHeight);
        return 0;
    }

    CHashWriter ss(SER_GETHASH, PROTOCOL_VERSION);
    ss << hash;
    uint256 hash2 = ss.GetHash();

    CHashWriter ss2(SER_GETHASH, PROTOCOL_VERSION);
    ss2 << hash;
    ss2 << aux;
    uint256 hash3 = ss2.GetHash();

    uint256 r = (hash3 > hash2 ? hash3 - hash2 : hash2 - hash3);

    return r;
}

void CStormnode::Check()
{
    //TODO: Random segfault with this line removed
    TRY_LOCK(cs_main, lockRecv);
    if(!lockRecv) return;

    if(nScanningErrorCount >= STORMNODE_SCANNING_ERROR_THESHOLD) 
    {
        activeState = STORMNODE_POS_ERROR;
        return;
    }

    //once spent, stop doing the checks
    if(activeState == STORMNODE_VIN_SPENT) return;


    if(!UpdatedWithin(STORMNODE_REMOVAL_SECONDS)){
        activeState = STORMNODE_REMOVE;
        return;
    }

    if(!UpdatedWithin(STORMNODE_EXPIRATION_SECONDS)){
        activeState = STORMNODE_EXPIRED;
        return;
    }

    if(!unitTest){
        CValidationState state;
        CMutableTransaction tx = CMutableTransaction();
        CTxOut vout = CTxOut(STORMNODE_COLLATERAL*COIN, sandStormPool.collateralPubKey);
        tx.vin.push_back(vin);
        tx.vout.push_back(vout);

        {   
            TRY_LOCK(cs_main, lockMain);
            if(!lockMain) return;
            CTransaction txNew = CTransaction(tx);
            if(!AcceptableInputs(mempool, txNew, false, true)){
                activeState = STORMNODE_VIN_SPENT;
                return;
            }
        }
    }

    activeState = STORMNODE_ENABLED; // OK
}

CStormnodeBroadcast::CStormnodeBroadcast()
{
    vin = CTxIn();
    addr = CService();
    pubkey = CPubKey();
    pubkey2 = CPubKey();
    sig = std::vector<unsigned char>();
    activeState = STORMNODE_ENABLED;
    sigTime = GetAdjustedTime();
    lastSnping = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = MIN_PEER_PROTO_VERSION;
    nLastSsq = 0;
    donationAddress = CScript();
    donationPercentage = 0;
    nScanningErrorCount = 0;
    nLastScanningErrorBlockHeight = 0;

    //mark last paid as current for new entries
    nLastPaid = 0;
}

CStormnodeBroadcast::CStormnodeBroadcast(CService newAddr, CTxIn newVin, CPubKey newPubkey, CPubKey newPubkey2, int protocolVersionIn, CScript newDonationAddress, int newDonationPercentage)
{
    vin = newVin;
    addr = newAddr;
    pubkey = newPubkey;
    pubkey2 = newPubkey2;
    sig = std::vector<unsigned char>();
    activeState = STORMNODE_ENABLED;
    sigTime = GetAdjustedTime();
    lastSnping = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = protocolVersionIn;
    nLastSsq = 0;
    donationAddress = newDonationAddress;
    donationPercentage = newDonationPercentage;
    nScanningErrorCount = 0;
    nLastScanningErrorBlockHeight = 0;
    nLastPaid = 0;  
}

CStormnodeBroadcast::CStormnodeBroadcast(const CStormnode& other)
{
    vin = other.vin;
    addr = other.addr;
    pubkey = other.pubkey;
    pubkey2 = other.pubkey2;
    sig = other.sig;
    activeState = other.activeState;
    sigTime = other.sigTime;
    lastSnping = other.lastSnping;
    lastTimeSeen = other.lastTimeSeen;
    cacheInputAge = other.cacheInputAge;
    cacheInputAgeBlock = other.cacheInputAgeBlock;
    unitTest = other.unitTest;
    allowFreeTx = other.allowFreeTx;
    protocolVersion = other.protocolVersion;
    nLastSsq = other.nLastSsq;
    donationAddress = other.donationAddress;
    donationPercentage = other.donationPercentage;
    nScanningErrorCount = other.nScanningErrorCount;
    nLastScanningErrorBlockHeight = other.nLastScanningErrorBlockHeight;
    nLastPaid = other.nLastPaid;
}

bool CStormnodeBroadcast::CheckAndUpdate(int& nDos, bool fRequested)
{
    // make sure signature isn't in the future (past is OK)
    if (sigTime > GetAdjustedTime() + 60 * 60) {
        LogPrintf("ssee - Signature rejected, too far into the future %s\n", vin.ToString().c_str());
        return false;
    }

    std::string vchPubKey(pubkey.begin(), pubkey.end());
    std::string vchPubKey2(pubkey2.begin(), pubkey2.end());
    std::string strMessage = addr.ToString() + boost::lexical_cast<std::string>(sigTime) + vchPubKey + vchPubKey2 + boost::lexical_cast<std::string>(protocolVersion)  + donationAddress.ToString() + boost::lexical_cast<std::string>(donationPercentage);

    if(donationPercentage < 0 || donationPercentage > 100){
        LogPrintf("ssee - donation percentage out of range %d\n", donationPercentage);
        return false;
    }

    if(protocolVersion < nStormnodeMinProtocol) {
        LogPrintf("ssee - ignoring outdated Stormnode %s protocol version %d\n", vin.ToString().c_str(), protocolVersion);
        return false;
    }

    CScript pubkeyScript;
    pubkeyScript = GetScriptForDestination(pubkey.GetID());

    if(pubkeyScript.size() != 25) {
        LogPrintf("ssee - pubkey the wrong size\n");
        nDos = 100;
        return false;
    }

    CScript pubkeyScript2;
    pubkeyScript2 = GetScriptForDestination(pubkey2.GetID());

    if(pubkeyScript2.size() != 25) {
        LogPrintf("ssee - pubkey2 the wrong size\n");
        nDos = 100;
        return false;
    }

    if(!vin.scriptSig.empty()) {
        LogPrintf("ssee - Ignore Not Empty ScriptSig %s\n",vin.ToString().c_str());
        return false;
    }

    std::string errorMessage = "";
    if(!sandStormSigner.VerifyMessage(pubkey, sig, strMessage, errorMessage)){
        LogPrintf("ssee - Got bad Stormnode address signature\n");
        nDos = 100;
        return false;
    }

    //search existing Stormnode list, this is where we update existing Stormnodes with new ssee broadcasts
    CStormnode* psn = snodeman.Find(vin);
    // if we are stormnode but with undefined vin and this ssee is ours (matches our Stormnode privkey) then just skip this part
    if(psn != NULL && !(fStormNode && activeStormnode.vin == CTxIn() && pubkey2 == activeStormnode.pubKeyStormnode))
    {
        // sn.pubkey = pubkey, IsVinAssociatedWithPubkey is validated once below,
        //   after that they just need to match
        if(!fRequested && psn->pubkey == pubkey && !psn->UpdatedWithin(STORMNODE_MIN_SSEE_SECONDS)){
            psn->UpdateLastSeen();

            if(psn->sigTime < sigTime){ //take the newest entry
                LogPrintf("ssee - Got updated entry for %s\n", addr.ToString().c_str());
                
                psn->UpdateFromNewBroadcast((*this));
                
                psn->Check();
                if(psn->IsEnabled()) {
                    Relay(fRequested);
                }
            }
        }
        return false;
    }

    return true;
}

bool CStormnodeBroadcast::CheckInputsAndAdd(int& nDoS, bool fRequested)
{
    CValidationState state;
    CMutableTransaction tx = CMutableTransaction();
    CTxOut vout = CTxOut(41999.99*COIN, sandStormPool.collateralPubKey);
    tx.vin.push_back(vin);
    tx.vout.push_back(vout);
    //if(AcceptableInputs(mempool, state, CTransaction(tx), false, NULL)){
    CTransaction txNew = CTransaction(tx);
    if(AcceptableInputs(mempool, txNew, false, NULL)){
        if(fDebug) LogPrintf("ssee - Accepted Stormnode entry\n");

        if(GetInputAge(vin) < STORMNODE_MIN_CONFIRMATIONS){
            LogPrintf("ssee - Input must have least %d confirmations\n", STORMNODE_MIN_CONFIRMATIONS);
            return false;
        }

        // verify that sig time is legit in past
        // should be at least not earlier than block when 42000 DRKSLK tx got STORMNODE_MIN_CONFIRMATIONS
        uint256 hashBlock = 0;
        CTransaction tx2;
        GetTransaction(vin.prevout.hash, tx2, hashBlock);
        //TODO (AA): Put this back.  BlockMap is undefined.
        /*BlockMap::iterator mi = mapBlockIndex.find(hashBlock);
        if (mi != mapBlockIndex.end() && (*mi).second)
        {
            CBlockIndex* pSNIndex = (*mi).second; // block for 1000 DRKSLK tx -> 1 confirmation

            //All other chainActives have been converted to either pindexBest or pindexBest->nHeight but need to work out the line below:
            CBlockIndex* pConfIndex = chainActive[pSNIndex->nHeight + STORMNODE_MIN_CONFIRMATIONS - 1]; // block where tx got STORMNODE_MIN_CONFIRMATIONS
            
            //if(pConfIndex->GetBlockTime() > sigTime)
            if(pSNIndex->GetBlockTime() > sigTime)
            {
                LogPrintf("ssee - Bad sigTime %d for Stormnode %20s %105s (%i conf block is at %d)\n",
                          sigTime, addr.ToString(), vin.ToString(), STORMNODE_MIN_CONFIRMATIONS, pSNIndex->GetBlockTime());
                return false;
            }
        }*/

        //doesn't support multisig addresses
        if(donationAddress.IsPayToScriptHash()){
            donationAddress = CScript();
            donationPercentage = 0;
        }

        // add our Stormnode
        CStormnode sn((*this));
        sn.UpdateLastSeen(lastTimeSeen);
        snodeman.Add(sn);

        // if it matches our Stormnode privkey, then we've been remotely activated
        if(pubkey2 == activeStormnode.pubKeyStormnode && protocolVersion == PROTOCOL_VERSION){
            activeStormnode.EnableHotColdStormNode(vin, addr);
        }

        bool isLocal = addr.IsRFC1918() || addr.IsLocal();

        if(!fRequested && !isLocal) Relay(fRequested);

        return true;
    } else {
        //set nDos
        state.IsInvalid(nDoS);
    }

    return false;
}

void CStormnodeBroadcast::Relay(bool fRequested)
{
    CInv inv(MSG_STORMNODE_ANNOUNCE, GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }
}

bool CStormnodeBroadcast::Sign(CKey& keyCollateralAddress)
{   
    std::string errorMessage;

    std::string vchPubKey(pubkey.begin(), pubkey.end());
    std::string vchPubKey2(pubkey2.begin(), pubkey2.end());

    sigTime = GetAdjustedTime();

    std::string strMessage = addr.ToString() + boost::lexical_cast<std::string>(sigTime) + vchPubKey + vchPubKey2 + boost::lexical_cast<std::string>(protocolVersion) + donationAddress.ToString() + boost::lexical_cast<std::string>(donationPercentage);

    if(!sandStormSigner.SignMessage(strMessage, errorMessage, sig, keyCollateralAddress)) {
        LogPrintf("CStormnodeBroadcast::Sign() - Error: %s\n", errorMessage.c_str());
        return false;
    }

    if(!sandStormSigner.VerifyMessage(pubkey, sig, strMessage, errorMessage)) {
        LogPrintf("CStormnodeBroadcast::Sign() - Error: %s\n", errorMessage.c_str());
        return false;
    }

    return true;
}

CStormnodePing::CStormnodePing()
{
    vin = CTxIn();
}

CStormnodePing::CStormnodePing(CTxIn& newVin)
{
    vin = newVin;
}


bool CStormnodePing::Sign(CKey& keyStormnode, CPubKey& pubKeyStormnode)
{
    std::string errorMessage;
    std::string strStormNodeSignMessage;

    sigTime = GetAdjustedTime();
    std::string strMessage =  boost::lexical_cast<std::string>(sigTime);

    if(!sandStormSigner.SignMessage(strMessage, errorMessage, vchSig, keyStormnode)) {
        LogPrintf("CStormnodePing::Sign() - Error: %s\n", errorMessage.c_str());
        return false;
    }

    if(!sandStormSigner.VerifyMessage(pubKeyStormnode, vchSig, strMessage, errorMessage)) {
        LogPrintf("CStormnodePing::Sign() - Error: %s\n", errorMessage.c_str());
        return false;
    }

    return true;
}

bool CStormnodePing::CheckAndUpdate(int& nDos)
{
    if (sigTime > GetAdjustedTime() + 60 * 60) {
        LogPrintf("snping - Signature rejected, too far into the future %s\n", vin.ToString().c_str());
        return false;
    }

    if (sigTime <= GetAdjustedTime() - 60 * 60) {
        LogPrintf("snping - Signature rejected, too far into the past %s - %d %d \n", vin.ToString().c_str(), sigTime, GetAdjustedTime());
        return false;
    }

    // see if we have this Stormnode
    CStormnode* psn = snodeman.Find(vin);
    if(psn != NULL && psn->protocolVersion >= nStormnodeMinProtocol)
    {
        // LogPrintf("snping - Found corresponding sn for vin: %s\n", vin.ToString().c_str());
        // take this only if it's newer
        if(psn->lastSnping < sigTime)
        {
            std::string strMessage = boost::lexical_cast<std::string>(sigTime);

            std::string errorMessage = "";
            if(!sandStormSigner.VerifyMessage(psn->pubkey2, vchSig, strMessage, errorMessage))
            {
                LogPrintf("snping - Got bad Stormnode address signature %s \n", vin.ToString().c_str());
                nDos = 33;
                return false;
            }

            psn->lastSnping = sigTime;

            if(!psn->UpdatedWithin(STORMNODE_MIN_SNP_SECONDS))
            {
                psn->UpdateLastSeen();
                psn->Check();
                if(!psn->IsEnabled()) return false;
                
                Relay();
                return true;
            }
        }
    }

    return false;
}

void CStormnodePing::Relay()
{
    CInv inv(MSG_STORMNODE_PING, GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }
}
