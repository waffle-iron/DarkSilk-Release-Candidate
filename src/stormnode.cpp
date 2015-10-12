#include "stormnode.h"
#include "activestormnode.h"
#include "sandstorm.h"
//#include "primitives/transaction.h"
#include "main.h"
#include "util.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>


int CStormNode::minProtoVersion = MIN_SN_PROTO_VERSION;

CCriticalSection cs_stormnodes;

/** The list of active stormnodes */
std::vector<CStormNode> vecStormnodes;
/** Object for who's going to get paid on which blocks */
CStormnodePayments stormnodePayments;
// keep track of stormnode votes I've seen
map<uint256, CStormnodePaymentWinner> mapSeenStormnodeVotes;
// keep track of the scanning errors I've seen
map<uint256, int> mapSeenStormnodeScanningErrors;
// who's asked for the stormnode list and the last time
std::map<CNetAddr, int64_t> askedForStormnodeList;
// which stormnodes we've asked for
std::map<COutPoint, int64_t> askedForStormnodeListEntry;
// cache block hashes as we calculate them
std::map<int64_t, uint256> mapCacheBlockHashes;

// manage the stormnode connections
void ProcessStormnodeConnections(){
    LOCK(cs_vNodes);

    BOOST_FOREACH(CNode* pnode, vNodes)
    {
        //if it's our stormnode, let it be
        if(sandStormPool.submittedToStormnode == pnode->addr) continue;

        if(pnode->fSandStormMaster){
            LogPrintf("Closing stormnode connection %s \n", pnode->addr.ToString().c_str());
            pnode->CloseSocketDisconnect();
        }
    }
}

void ProcessMessageStormnode(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{

    if (strCommand == "dsee") { //SandStorm Election Entry
        if(fLiteMode) return; //disable all sandstorm/stormnode related functionality

        bool fIsInitialDownload = IsInitialBlockDownload();
        if(fIsInitialDownload) return;

        CTxIn vin;
        CService addr;
        CPubKey pubkey;
        CPubKey pubkey2;
        vector<unsigned char> vchSig;
        int64_t sigTime;
        int count;
        int current;
        int64_t lastUpdated;
        int protocolVersion;
        std::string strMessage;

        // 70047 and greater
        vRecv >> vin >> addr >> vchSig >> sigTime >> pubkey >> pubkey2 >> count >> current >> lastUpdated >> protocolVersion;

        // make sure signature isn't in the future (past is OK)
        if (sigTime > GetAdjustedTime() + 60 * 60) {
            LogPrintf("dsee - Signature rejected, too far into the future %s\n", vin.ToString().c_str());
            return;
        }

        bool isLocal = addr.IsRFC1918() || addr.IsLocal();
        //if(Params().MineBlocksOnDemand()) isLocal = false;

        std::string vchPubKey(pubkey.begin(), pubkey.end());
        std::string vchPubKey2(pubkey2.begin(), pubkey2.end());

        strMessage = addr.ToString() + boost::lexical_cast<std::string>(sigTime) + vchPubKey + vchPubKey2 + boost::lexical_cast<std::string>(protocolVersion);

        if(protocolVersion < MIN_SN_PROTO_VERSION) {
            LogPrintf("dsee - ignoring outdated stormnode %s protocol version %d\n", vin.ToString().c_str(), protocolVersion);
            return;
        }

        CScript pubkeyScript;
        pubkeyScript =GetScriptForDestination(pubkey.GetID());

        if(pubkeyScript.size() != 25) {
            LogPrintf("dsee - pubkey the wrong size\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        CScript pubkeyScript2;
        pubkeyScript2 =GetScriptForDestination(pubkey2.GetID());

        if(pubkeyScript2.size() != 25) {
            LogPrintf("dsee - pubkey2 the wrong size\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        std::string errorMessage = "";
        if(!sandStormSigner.VerifyMessage(pubkey, vchSig, strMessage, errorMessage)){
            LogPrintf("dsee - Got bad stormnode address signature\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        

        //search existing stormnode list, this is where we update existing stormnodes with new dsee broadcasts
	LOCK(cs_stormnodes);
        BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
            if(sn.vin.prevout == vin.prevout) {
                // count == -1 when it's a new entry
                //   e.g. We don't want the entry relayed/time updated when we're syncing the list
                // sn.pubkey = pubkey, IsVinAssociatedWithPubkey is validated once below,
                //   after that they just need to match
                if(count == -1 && sn.pubkey == pubkey && !sn.UpdatedWithin(STORMNODE_MIN_DSEE_SECONDS)){
                    sn.UpdateLastSeen();

                    if(sn.now < sigTime){ //take the newest entry
                        LogPrintf("dsee - Got updated entry for %s\n", addr.ToString().c_str());
                        sn.pubkey2 = pubkey2;
                        sn.now = sigTime;
                        sn.sig = vchSig;
                        sn.protocolVersion = protocolVersion;
                        sn.addr = addr;

                        RelaySandStormElectionEntry(vin, addr, vchSig, sigTime, pubkey, pubkey2, count, current, lastUpdated, protocolVersion);
                    }
                }

                return;
            }
        }

        // make sure the vout that was signed is related to the transaction that spawned the stormnode
        //  - this is expensive, so it's only done once per stormnode
        if(!sandStormSigner.IsVinAssociatedWithPubkey(vin, pubkey)) {
            LogPrintf("dsee - Got mismatched pubkey and vin\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        if(fDebug) LogPrintf("dsee - Got NEW stormnode entry %s\n", addr.ToString().c_str());

        // make sure it's still unspent
        //  - this is checked later by .check() in many places and by ThreadCheckSandStormPool()

        CValidationState state;
        CTransaction tx = CTransaction();
        CTxOut vout = CTxOut(999.99*COIN, sandStormPool.collateralPubKey);
        tx.vin.push_back(vin);
        tx.vout.push_back(vout);
        //if(AcceptableInputs(mempool, state, tx)){
	bool* pfMissingInputs = false;
	if(AcceptableInputs(mempool, tx, false, pfMissingInputs)){
            if(fDebug) LogPrintf("dsee - Accepted stormnode entry %i %i\n", count, current);

            if(GetInputAge(vin) < STORMNODE_MIN_CONFIRMATIONS){
                LogPrintf("dsee - Input must have least %d confirmations\n", STORMNODE_MIN_CONFIRMATIONS);
                Misbehaving(pfrom->GetId(), 20);
                return;
            }

            // use this as a peer
            addrman.Add(CAddress(addr), pfrom->addr, 2*60*60);

            // add our stormnode
            CStormNode sn(addr, vin, pubkey, vchSig, sigTime, pubkey2, protocolVersion);
            sn.UpdateLastSeen(lastUpdated);
            vecStormnodes.push_back(sn);

            // if it matches our stormnodeprivkey, then we've been remotely activated
            if(pubkey2 == activeStormnode.pubKeyStormnode && protocolVersion == PROTOCOL_VERSION){
                activeStormnode.EnableHotColdStormNode(vin, addr);
            }

            if(count == -1 && !isLocal)
                RelaySandStormElectionEntry(vin, addr, vchSig, sigTime, pubkey, pubkey2, count, current, lastUpdated, protocolVersion);

        } else {
            LogPrintf("dsee - Rejected stormnode entry %s\n", addr.ToString().c_str());

            int nDoS = 0;
            if (state.IsInvalid(nDoS))
            {
                LogPrintf("dsee - %s from %s %s was not accepted into the memory pool\n", tx.GetHash().ToString().c_str(),
                    pfrom->addr.ToString().c_str(), pfrom->cleanSubVer.c_str());
                if (nDoS > 0)
                    Misbehaving(pfrom->GetId(), nDoS);
            }
        }
    }

    else if (strCommand == "dseep") { //SandStorm Election Entry Ping
        if(fLiteMode) return; //disable all sandstorm/stormnode related functionality
        bool fIsInitialDownload = IsInitialBlockDownload();
        if(fIsInitialDownload) return;

        CTxIn vin;
        vector<unsigned char> vchSig;
        int64_t sigTime;
        bool stop;
        vRecv >> vin >> vchSig >> sigTime >> stop;

        //LogPrintf("dseep - Received: vin: %s sigTime: %lld stop: %s\n", vin.ToString().c_str(), sigTime, stop ? "true" : "false");

        if (sigTime > GetAdjustedTime() + 60 * 60) {
            LogPrintf("dseep - Signature rejected, too far into the future %s\n", vin.ToString().c_str());
            return;
        }

        if (sigTime <= GetAdjustedTime() - 60 * 60) {
            LogPrintf("dseep - Signature rejected, too far into the past %s - %d %d \n", vin.ToString().c_str(), sigTime, GetAdjustedTime());
            return;
        }

        // see if we have this stormnode
	LOCK(cs_stormnodes);
        BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
            if(sn.vin.prevout == vin.prevout) {
            	// LogPrintf("dseep - Found corresponding sn for vin: %s\n", vin.ToString().c_str());
            	// take this only if it's newer
                if(sn.lastDseep < sigTime){
                    std::string strMessage = sn.addr.ToString() + boost::lexical_cast<std::string>(sigTime) + boost::lexical_cast<std::string>(stop);

                    std::string errorMessage = "";
                    if(!sandStormSigner.VerifyMessage(sn.pubkey2, vchSig, strMessage, errorMessage)){
                        LogPrintf("dseep - Got bad stormnode address signature %s \n", vin.ToString().c_str());
                        //Misbehaving(pfrom->GetId(), 100);
                        return;
                    }

                    sn.lastDseep = sigTime;

                    if(!sn.UpdatedWithin(STORMNODE_MIN_DSEEP_SECONDS)){
                        sn.UpdateLastSeen();
                        if(stop) {
                            sn.Disable();
                            sn.Check();
                        }
                        RelaySandStormElectionEntryPing(vin, vchSig, sigTime, stop);
                    }
                }
                return;
            }
        }

        if(fDebug) LogPrintf("dseep - Couldn't find stormnode entry %s\n", vin.ToString().c_str());

        std::map<COutPoint, int64_t>::iterator i = askedForStormnodeListEntry.find(vin.prevout);
        if (i != askedForStormnodeListEntry.end()){
            int64_t t = (*i).second;
            if (GetTime() < t) {
                // we've asked recently
                return;
            }
        }

        // ask for the dsee info once from the node that sent dseep

        LogPrintf("dseep - Asking source node for missing entry %s\n", vin.ToString().c_str());
        pfrom->PushMessage("dseg", vin);
        int64_t askAgain = GetTime()+(60*60*24);
        askedForStormnodeListEntry[vin.prevout] = askAgain;

    } else if (strCommand == "dseg") { //Get stormnode list or specific entry
        if(fLiteMode) return; //disable all sandstorm/stormnode related functionality
        CTxIn vin;
        vRecv >> vin;

        if(vin == CTxIn()) { //only should ask for this once
            //local network
            //Note tor peers show up as local proxied addrs //if(!pfrom->addr.IsRFC1918())//&& !Params().MineBlocksOnDemand())
            //{
                std::map<CNetAddr, int64_t>::iterator i = askedForStormnodeList.find(pfrom->addr);
                if (i != askedForStormnodeList.end())
                {
                    int64_t t = (*i).second;
                    if (GetTime() < t) {
                        //Misbehaving(pfrom->GetId(), 34);
                        //LogPrintf("dseg - peer already asked me for the list\n");
                        //return;
                    }
                }

                int64_t askAgain = GetTime()+(60*60*3);
                askedForStormnodeList[pfrom->addr] = askAgain;
            //}
        } //else, asking for a specific node which is ok

	LOCK(cs_stormnodes);
        int count = vecStormnodes.size();
        int i = 0;

        BOOST_FOREACH(CStormNode sn, vecStormnodes) {

            if(sn.addr.IsRFC1918()) continue; //local network

            if(vin == CTxIn()){
                sn.Check();
                if(sn.IsEnabled()) {
                    if(fDebug) LogPrintf("dseg - Sending stormnode entry - %s \n", sn.addr.ToString().c_str());
                    pfrom->PushMessage("dsee", sn.vin, sn.addr, sn.sig, sn.now, sn.pubkey, sn.pubkey2, count, i, sn.lastTimeSeen, sn.protocolVersion);
                }
            } else if (vin == sn.vin) {
                if(fDebug) LogPrintf("dseg - Sending stormnode entry - %s \n", sn.addr.ToString().c_str());
                pfrom->PushMessage("dsee", sn.vin, sn.addr, sn.sig, sn.now, sn.pubkey, sn.pubkey2, count, i, sn.lastTimeSeen, sn.protocolVersion);
                LogPrintf("dseg - Sent 1 stormnode entries to %s\n", pfrom->addr.ToString().c_str());
                return;
            }
            i++;
        }

        LogPrintf("dseg - Sent %d stormnode entries to %s\n", count, pfrom->addr.ToString().c_str());
    }

    else if (strCommand == "snget") { //Stormnode Payments Request Sync
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

struct CompareValueOnly
{
    bool operator()(const pair<int64_t, CTxIn>& t1,
                    const pair<int64_t, CTxIn>& t2) const
    {
        return t1.first < t2.first;
    }
};

struct CompareValueOnly2
{
    bool operator()(const pair<int64_t, int>& t1,
                    const pair<int64_t, int>& t2) const
    {
        return t1.first < t2.first;
    }
};

int CountStormnodesAboveProtocol(int protocolVersion)
{
    int i = 0;
    LOCK(cs_stormnodes);
    BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
        if(sn.protocolVersion < protocolVersion) continue;
        i++;
    }

    return i;

}


int GetStormnodeByVin(CTxIn& vin)
{
    int i = 0;
    LOCK(cs_stormnodes);
    BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
        if (sn.vin == vin) return i;
        i++;
    }

    return -1;
}

int GetCurrentStormNode(int mod, int64_t nBlockHeight, int minProtocol)
{
    int i = 0;
    unsigned int score = 0;
    int winner = -1;
    LOCK(cs_stormnodes);
    // scan for winner
    BOOST_FOREACH(CStormNode sn, vecStormnodes) {
        sn.Check();
        if(sn.protocolVersion < minProtocol) continue;
        if(!sn.IsEnabled()) {
            i++;
            continue;
        }

        // calculate the score for each stormnode
        uint256 n = sn.CalculateScore(mod, nBlockHeight);
        unsigned int n2 = 0;
        memcpy(&n2, &n, sizeof(n2));

        // determine the winner
        if(n2 > score){
            score = n2;
            winner = i;
        }
        i++;
    }

    return winner;
}

int GetStormnodeByRank(int findRank, int64_t nBlockHeight, int minProtocol)
{
    LOCK(cs_stormnodes);
    int i = 0;

    std::vector<pair<unsigned int, int> > vecStormnodeScores;

    i = 0;
    BOOST_FOREACH(CStormNode sn, vecStormnodes) {
        sn.Check();
        if(sn.protocolVersion < minProtocol) continue;
        if(!sn.IsEnabled()) {
            i++;
            continue;
        }

        uint256 n = sn.CalculateScore(1, nBlockHeight);
        unsigned int n2 = 0;
        memcpy(&n2, &n, sizeof(n2));

        vecStormnodeScores.push_back(make_pair(n2, i));
        i++;
    }

    sort(vecStormnodeScores.rbegin(), vecStormnodeScores.rend(), CompareValueOnly2());

    int rank = 0;
    BOOST_FOREACH (PAIRTYPE(unsigned int, int)& s, vecStormnodeScores){
        rank++;
        if(rank == findRank) return s.second;
    }

    return -1;
}

int GetStormnodeRank(CTxIn& vin, int64_t nBlockHeight, int minProtocol)
{
    LOCK(cs_stormnodes);
    std::vector<pair<unsigned int, CTxIn> > vecStormnodeScores;

    BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
        sn.Check();

        if(sn.protocolVersion < minProtocol) continue;
        if(!sn.IsEnabled()) {
            continue;
        }

        uint256 n = sn.CalculateScore(1, nBlockHeight);
        unsigned int n2 = 0;
        memcpy(&n2, &n, sizeof(n2));

        vecStormnodeScores.push_back(make_pair(n2, sn.vin));
    }

    sort(vecStormnodeScores.rbegin(), vecStormnodeScores.rend(), CompareValueOnly());

    unsigned int rank = 0;
    BOOST_FOREACH (PAIRTYPE(unsigned int, CTxIn)& s, vecStormnodeScores){
        rank++;
        if(s.second == vin) {
            return rank;
        }
    }

    return -1;
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

//
// Deterministically calculate a given "score" for a stormnode depending on how close it's hash is to
// the proof of work for that block. The further away they are the better, the furthest will win the election
// and get paid this block
//
uint256 CStormNode::CalculateScore(int mod, int64_t nBlockHeight)
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

void CStormNode::Check()
{
    //once spent, stop doing the checks
    if(enabled==3) return;


    if(!UpdatedWithin(STORMNODE_REMOVAL_SECONDS)){
        enabled = 4;
        return;
    }

    if(!UpdatedWithin(STORMNODE_EXPIRATION_SECONDS)){
        enabled = 2;
        return;
    }

    if(!unitTest){
        CValidationState state;
        CTransaction tx = CTransaction();
        CTxOut vout = CTxOut(999.99*COIN, sandStormPool.collateralPubKey);
        tx.vin.push_back(vin);
        tx.vout.push_back(vout);

        //if(!AcceptableInputs(mempool, state, tx)){
        bool* pfMissingInputs = false;
	if(!AcceptableInputs(mempool, tx, false, pfMissingInputs)){
            enabled = 3;
            return;
        }
    }

    enabled = 1; // OK
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

    int nLimit = std::max(((int)vecStormnodes.size())*2, 1000);

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
    CStormnodePaymentWinner winner;

    std::vector<CTxIn> vecLastPayments;
    int c = 0;
    BOOST_REVERSE_FOREACH(CStormnodePaymentWinner& winner, vWinning){
        vecLastPayments.push_back(winner.vin);
        //if we have one full payment cycle, break
        if(++c > (int)vecStormnodes.size()) break;
    }

    std::random_shuffle ( vecStormnodes.begin(), vecStormnodes.end() );
    BOOST_FOREACH(CStormNode& sn, vecStormnodes) {
        bool found = false;
        BOOST_FOREACH(CTxIn& vin, vecLastPayments)
            if(sn.vin == vin) found = true;

        if(found) continue;

        sn.Check();
        if(!sn.IsEnabled()) {
            continue;
        }

        winner.score = 0;
        winner.nBlockHeight = nBlockHeight;
        winner.vin = sn.vin;
        winner.payee =GetScriptForDestination(sn.pubkey.GetID());

        break;
    }

    //if we can't find someone to get paid, pick randomly
    if(winner.nBlockHeight == 0 && vecStormnodes.size() > 0) {
        winner.score = 0;
        winner.nBlockHeight = nBlockHeight;
        winner.vin = vecStormnodes[0].vin;
        winner.payee =GetScriptForDestination(vecStormnodes[0].pubkey.GetID());
    }

    if(Sign(winner)){
        if(AddWinningStormnode(winner)){
            Relay(winner);
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
