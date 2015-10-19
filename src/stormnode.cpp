#include "stormnode.h"
#include "stormnodeman.h"
#include "sandstorm.h"
#include "core.h"
#include "main.h"
#include "util.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>


int CStormnode::minProtoVersion = MIN_SN_PROTO_VERSION;

CCriticalSection cs_stormnodes;

/** Object for who's going to get paid on which blocks */
CStormnodePayments stormnodePayments;
// keep track of stormnode votes I've seen
map<uint256, CStormnodePaymentWinner> mapSeenStormnodeVotes;
// keep track of the scanning errors I've seen
map<uint256, int> mapSeenStormnodeScanningErrors;
// cache block hashes as we calculate them
std::map<int64_t, uint256> mapCacheBlockHashes;

void ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{
    if(IsInitialBlockDownload()) return;
    if (strCommand == "snget") //Stormnode Payments Request Sync
    {
        if(fLiteMode) return; //disable all sandstorm/stormnode related functionality

        /*if(pfrom->HasFulfilledRequest("snget")) {
            LogPrintf("snget - peer already asked me for the list\n");
            Misbehaving(pfrom->GetId(), 20);
            return;
        }*/

        pfrom->FulfilledRequest("snget");
        stormnodePayments.Sync(pfrom);
        LogPrintf("snget - Sent stormnode winners to %s\n", pfrom->addr.ToString().c_str());
    }
    else if (strCommand == "snw") { //Stormnode Payments Declare Winner
        //this is required in litemode
        CStormnodePaymentWinner winner;
        int a = 0;
        vRecv >> winner >> a;

        if(pindexBest == NULL) return;

        uint256 hash = winner.GetHash();
        if(mapSeenStormnodeVotes.count(hash)) {
            if(fDebug) LogPrintf("snw - seen vote %s Height %d bestHeight %d\n", hash.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);
            return;
        }

        if(winner.nBlockHeight < pindexBest->nHeight - 10 || winner.nBlockHeight > pindexBest->nHeight+20){
            LogPrintf("snw - winner out of range %s Height %d bestHeight %d\n", winner.vin.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);
            return;
        }

        if(winner.vin.nSequence != std::numeric_limits<unsigned int>::max()){
            LogPrintf("snw - invalid nSequence\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        LogPrintf("snw - winning vote  %s Height %d bestHeight %d\n", winner.vin.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);

        if(!stormnodePayments.CheckSignature(winner)){
            LogPrintf("snw - invalid signature\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        mapSeenStormnodeVotes.insert(make_pair(hash, winner));

        if(stormnodePayments.AddWinningStormnode(winner)){
            stormnodePayments.Relay(winner);
        }
    }
}

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
    now = GetTime();
    lastSseep = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = MIN_PEER_PROTO_VERSION;
    nLastDsq = 0;
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
    now = other.now;
    lastSseep = other.lastSseep;
    lastTimeSeen = other.lastTimeSeen;
    cacheInputAge = other.cacheInputAge;
    cacheInputAgeBlock = other.cacheInputAgeBlock;
    unitTest = other.unitTest;
    allowFreeTx = other.allowFreeTx;
    protocolVersion = other.protocolVersion;
    nLastDsq = other.nLastDsq;
}

CStormnode::CStormnode(CService newAddr, CTxIn newVin, CPubKey newPubkey, std::vector<unsigned char> newSig, int64_t newNow, CPubKey newPubkey2, int protocolVersionIn)
{
    LOCK(cs);
    vin = newVin;
    addr = newAddr;
    pubkey = newPubkey;
    pubkey2 = newPubkey2;
    sig = newSig;
    activeState = STORMNODE_ENABLED;
    now = newNow;
    lastSseep = 0;
    lastTimeSeen = 0;
    cacheInputAge = 0;
    cacheInputAgeBlock = 0;
    unitTest = false;
    allowFreeTx = true;
    protocolVersion = protocolVersionIn;
    nLastDsq = 0;
}

//
// Deterministically calculate a given "score" for a stormnode depending on how close it's hash is to
// the proof of work for that block. The further away they are the better, the furthest will win the election
// and get paid this block
//
uint256 CStormnode::CalculateScore(int mod, int64_t nBlockHeight)
{
    if(pindexBest == NULL) return 0;

    uint256 hash = 0;
    uint256 aux = vin.prevout.hash + vin.prevout.n;

    if(!GetBlockHash(hash, nBlockHeight)) return 0;

    uint256 hash2 = Hash(BEGIN(hash), END(hash));
    uint256 hash3 = Hash(BEGIN(hash), END(aux));

    uint256 r = (hash3 > hash2 ? hash3 - hash2 : hash2 - hash3);

    return r;
}

void CStormnode::Check()
{
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
        CTransaction tx = CTransaction();
        CTxOut vout = CTxOut(STORMNODE_COLLATERAL*COIN, sandStormPool.collateralPubKey);
        tx.vin.push_back(vin);
        tx.vout.push_back(vout);

        //if(!AcceptableInputs(mempool, state, tx)){
        bool* pfMissingInputs = new bool;
        *pfMissingInputs = false;
	if(!AcceptableInputs(mempool, tx, false, pfMissingInputs)){
            activeState = STORMNODE_VIN_SPENT;
            return;
        }
    }

    activeState = STORMNODE_ENABLED; // OK
}

bool CStormnodePayments::CheckSignature(CStormnodePaymentWinner& winner)
{
    //note: need to investigate why this is failing
    std::string strMessage = winner.vin.ToString().c_str() + boost::lexical_cast<std::string>(winner.nBlockHeight) + winner.payee.ToString();
    std::string strPubKey = strMainPubKey ;
    CPubKey pubkey(ParseHex(strPubKey));

    std::string errorMessage = "";
    if(!sandStormSigner.VerifyMessage(pubkey, winner.vchSig, strMessage, errorMessage)){
        return false;
    }

    return true;
}

bool CStormnodePayments::Sign(CStormnodePaymentWinner& winner)
{
    std::string strMessage = winner.vin.ToString().c_str() + boost::lexical_cast<std::string>(winner.nBlockHeight) + winner.payee.ToString();

    CKey key2;
    CPubKey pubkey2;
    std::string errorMessage = "";

    if(!sandStormSigner.SetKey(strMasterPrivKey, errorMessage, key2, pubkey2))
    {
        LogPrintf("CStormnodePayments::Sign - ERROR: Invalid stormnodeprivkey: '%s'\n", errorMessage.c_str());
        return false;
    }

    if(!sandStormSigner.SignMessage(strMessage, errorMessage, winner.vchSig, key2)) {
        LogPrintf("CStormnodePayments::Sign - Sign message failed");
        return false;
    }

    if(!sandStormSigner.VerifyMessage(pubkey2, winner.vchSig, strMessage, errorMessage)) {
        LogPrintf("CStormnodePayments::Sign - Verify message failed");
        return false;
    }

    return true;
}

uint64_t CStormnodePayments::CalculateScore(uint256 blockHash, CTxIn& vin)
{
    uint256 n1 = blockHash;
    uint256 n2 = Hash(BEGIN(n1), END(n1));
    uint256 n3 = Hash(BEGIN(vin.prevout.hash), END(vin.prevout.hash));
    uint256 n4 = n3 > n2 ? (n3 - n2) : (n2 - n3);

    //printf(" -- CStormnodePayments CalculateScore() n2 = %d \n", n2.Get64());
    //printf(" -- CStormnodePayments CalculateScore() n3 = %d \n", n3.Get64());
    //printf(" -- CStormnodePayments CalculateScore() n4 = %d \n", n4.Get64());

    return n4.Get64();
}

bool CStormnodePayments::GetBlockPayee(int nBlockHeight, CScript& payee)
{
    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning){
        if(winner.nBlockHeight == nBlockHeight) {
            payee = winner.payee;
            return true;
        }
    }

    return false;
}

bool CStormnodePayments::GetWinningStormnode(int nBlockHeight, CTxIn& vinOut)
{
    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning){
        if(winner.nBlockHeight == nBlockHeight) {
            vinOut = winner.vin;
            return true;
        }
    }

    return false;
}

bool CStormnodePayments::AddWinningStormnode(CStormnodePaymentWinner& winnerIn)
{
    uint256 blockHash = 0;
    if(!GetBlockHash(blockHash, winnerIn.nBlockHeight-576)) {
        return false;
    }

    winnerIn.score = CalculateScore(blockHash, winnerIn.vin);

    bool foundBlock = false;
    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning){
        if(winner.nBlockHeight == winnerIn.nBlockHeight) {
            foundBlock = true;
            if(winner.score < winnerIn.score){
                winner.score = winnerIn.score;
                winner.vin = winnerIn.vin;
                winner.payee = winnerIn.payee;
                winner.vchSig = winnerIn.vchSig;

                return true;
            }
        }
    }

    // if it's not in the vector
    if(!foundBlock){
        vWinning.push_back(winnerIn);
        mapSeenStormnodeVotes.insert(make_pair(winnerIn.GetHash(), winnerIn));

        return true;
    }

    return false;
}

void CStormnodePayments::CleanPaymentList()
{
    LOCK(cs_stormnodes);
    if(pindexBest == NULL) return;

    int nLimit = std::max(((int)snodeman.size())*2, 1000);

    vector<CStormnodePaymentWinner>::iterator it;
    for(it=vWinning.begin();it<vWinning.end();it++){
        if(pindexBest->nHeight - (*it).nBlockHeight > nLimit){
            if(fDebug) LogPrintf("CStormnodePayments::CleanPaymentList - Removing old stormnode payment - block %d\n", (*it).nBlockHeight);
            vWinning.erase(it);
            break;
        }
    }
}

bool CStormnodePayments::ProcessBlock(int nBlockHeight)
{
    LOCK(cs_stormnodes);
    if(!enabled) return false;
    CStormnodePaymentWinner newWinner;

    std::vector<CTxIn> vecLastPayments;
    BOOST_REVERSE_FOREACH(CStormnodePaymentWinner& winner, vWinning)
    {
        //if we already have the same vin - we have one full payment cycle, break
        if(vecLastPayments.size() > 0
                && std::find(vecLastPayments.begin(), vecLastPayments.end(), winner.vin) != vecLastPayments.end()) break;
        vecLastPayments.push_back(winner.vin);
    }

    CStormnode* psn = snodeman.FindNotInVec(vecLastPayments);
    if(psn != NULL) 
    {
        newWinner.score = 0;
        newWinner.nBlockHeight = nBlockHeight;
        newWinner.vin = psn->vin;
        newWinner.payee.SetDestination(psn->pubkey.GetID());
    }

    //if we can't find new SN to get paid, pick the first active SN counting back from the end of vecLastPayments list
    if(newWinner.nBlockHeight == 0 && snodeman.CountEnabled() > 0)
    {
        BOOST_REVERSE_FOREACH(CTxIn& vinLP, vecLastPayments)
        {
            CStormnode* psn = snodeman.Find(vinLP);
            if(psn != NULL)
            {
                psn->Check();
                if(!psn->IsEnabled()) continue;

                newWinner.score = 0;
                newWinner.nBlockHeight = nBlockHeight;
                newWinner.vin = psn->vin;
                newWinner.payee.SetDestination(psn->pubkey.GetID());
                break; // we found active SN
            }
        }
    }

    if(newWinner.nBlockHeight == 0) return false;

    if(Sign(newWinner))
    {
        if(AddWinningStormnode(newWinner))
        {
            Relay(newWinner);
            return true;
        }
    }

    return false;
}

void CStormnodePayments::Relay(CStormnodePaymentWinner& winner)
{
    CInv inv(MSG_STORMNODE_WINNER, winner.GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }
}

void CStormnodePayments::Sync(CNode* node)
{
    int a = 0;
    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning)
        if(winner.nBlockHeight >= pindexBest->nHeight-10 && winner.nBlockHeight <= pindexBest->nHeight + 20)
            node->PushMessage("snw", winner, a);
}


bool CStormnodePayments::SetPrivKey(std::string strPrivKey)
{
    CStormnodePaymentWinner winner;

    // Test signing successful, proceed
    strMasterPrivKey = strPrivKey;

    Sign(winner);

    if(CheckSignature(winner)){
        LogPrintf("CStormnodePayments::SetPrivKey - Successfully initialized as stormnode payments master\n");
        enabled = true;
        return true;
    } else {
        return false;
    }
}
