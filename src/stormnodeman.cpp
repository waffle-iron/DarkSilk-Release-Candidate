#include "stormnodeman.h"
#include "activestormnode.h"
#include "sandstorm.h"
#include "core.h"
#include "util.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>


/** Stormnode manager */
CStormnodeMan snodeman;
// who's asked for the stormnode list and the last time
std::map<CNetAddr, int64_t> askedForStormnodeList;
// which stormnodes we've asked for
std::map<COutPoint, int64_t> askedForStormnodeListEntry;

struct CompareValueOnly
{
    bool operator()(const pair<int64_t, CTxIn>& t1,
                    const pair<int64_t, CTxIn>& t2) const
    {
        return t1.first < t2.first;
    }
};

//
// CStormnodeDB
//

CStormnodeDB::CStormnodeDB()
{
    pathSN = GetDataDir() / "stormnodes.dat";
}

bool CStormnodeDB::Write(const CStormnodeMan& snodemanToSave)
{
    // serialize addresses, checksum data up to that point, then append csum
    CDataStream ssStormnodes(SER_DISK, CLIENT_VERSION);
    ssStormnodes << FLATDATA(Params().MessageStart());
    ssStormnodes << snodemanToSave;
    uint256 hash = Hash(ssStormnodes.begin(), ssStormnodes.end());
    ssStormnodes << hash;

    // open output file, and associate with CAutoFile
    FILE *file = fopen(pathSN.string().c_str(), "wb");
    CAutoFile fileout = CAutoFile(file, SER_DISK, CLIENT_VERSION);
    if (!fileout)
        return error("%s : Failed to open file %s", __func__, pathSN.string());

    // Write and commit header, data
    try {
        fileout << ssStormnodes;
    }
    catch (std::exception &e) {
        return error("%s : Serialize or I/O error - %s", __func__, e.what());
    }
    FileCommit(fileout);
    fileout.fclose();

    return true;
}

bool CStormnodeDB::Read(CStormnodeMan& snodemanToLoad)
{
    // open input file, and associate with CAutoFile
    FILE *file = fopen(pathSN.string().c_str(), "rb");
    CAutoFile filein = CAutoFile(file, SER_DISK, CLIENT_VERSION);
    if (!filein)
        return error("%s : Failed to open file %s", __func__, pathSN.string());

    // use file size to size memory buffer
    int fileSize = boost::filesystem::file_size(pathSN);
    int dataSize = fileSize - sizeof(uint256);
    // Don't try to resize to a negative number if file is small
    if (dataSize < 0)
        dataSize = 0;
    vector<unsigned char> vchData;
    vchData.resize(dataSize);
    uint256 hashIn;

    // read data and checksum from file
    try {
        filein.read((char *)&vchData[0], dataSize);
        filein >> hashIn;
    }
    catch (std::exception &e) {
        return error("%s : Deserialize or I/O error - %s", __func__, e.what());
    }
    filein.fclose();

    CDataStream ssStormnodes(vchData, SER_DISK, CLIENT_VERSION);

    // verify stored checksum matches input data
    uint256 hashTmp = Hash(ssStormnodes.begin(), ssStormnodes.end());
    if (hashIn != hashTmp)
        return error("%s : Checksum mismatch, data corrupted", __func__);

    unsigned char pchMsgTmp[4];
    try {
        // de-serialize file header (network specific magic number) and ..
        ssStormnodes >> FLATDATA(pchMsgTmp);

        // ... verify the network matches ours
        if (memcmp(pchMsgTmp, Params().MessageStart(), sizeof(pchMsgTmp)))
            return error("%s : Invalid network magic number", __func__);

        // de-serialize address data into one CMnList object
        ssStormnodes >> snodemanToLoad;
    }
    catch (std::exception &e) {
        return error("%s : Deserialize or I/O error - %s", __func__, e.what());
        snodemanToLoad.Clear();
    }

    return true;
}

void DumpStormnodes()
{
    int64_t nStart = GetTimeMillis();

    CStormnodeDB sndb;
    sndb.Write(snodeman);

    LogPrint("stormnode", "Flushed %d stormnodes to stormnodes.dat  %dms\n",
           snodeman.size(), GetTimeMillis() - nStart);
}

CStormnodeMan::CStormnodeMan() {}

CStormnode *CStormnodeMan::Find(const CTxIn &vin)
{
    LOCK(cs);

    BOOST_FOREACH(CStormnode& sn, vStormnodes)
    {
        if(sn.vin == vin)
            return &sn;
    }
    return NULL;
}

CStormnode *CStormnodeMan::FindRandom()
{
    LOCK(cs);

    if(size() == 0) return NULL;

    return &vStormnodes[GetRandInt(vStormnodes.size())];
}


CStormnode *CStormnodeMan::FindNotInVec(const std::vector<CTxIn> &vVins)
{
    LOCK(cs);

    BOOST_FOREACH(CStormnode &sn, vStormnodes)
    {
        sn.Check();
        if(!sn.IsEnabled()) continue;

        bool found = false;
        BOOST_FOREACH(const CTxIn& vin, vVins)
            if(sn.vin == vin)
            {
                found = true;
                break;
            }

        if(found) continue;

        return &sn;
    }

    return NULL;
}

bool CStormnodeMan::Add(CStormnode &sn)
{
    LOCK(cs);

    if (!sn.IsEnabled())
        return false;

    CStormnode *psn = Find(sn.vin);

    if (!psn)
    {
        vStormnodes.push_back(sn);
        return true;
    }

    return false;
}

void CStormnodeMan::Check()
{
    LOCK(cs);

    BOOST_FOREACH(CStormnode& sn, vStormnodes)
        sn.Check();
}

void CStormnodeMan::CheckAndRemove()
{
    LOCK(cs);

    vector<CStormnode>::iterator it = vStormnodes.begin();
    //check them separately
    while(it != vStormnodes.end()){
        (*it).Check();
        ++it;
    }

    //remove inactive
    it = vStormnodes.begin();
    while(it != vStormnodes.end()){
        if((*it).activeState == 4 || (*it).activeState == 3){
            LogPrintf("Removing inactive stormnode %s\n", (*it).addr.ToString().c_str());
            it = vStormnodes.erase(it);
        } else {
            ++it;
        }
    }
}

int CStormnodeMan::CountStormnodesAboveProtocol(int protocolVersion)
{
    int i = 0;

    BOOST_FOREACH(CStormnode& sn, vStormnodes) {
        if(sn.protocolVersion < protocolVersion || !sn.IsEnabled()) continue;
        i++;
    }

    return i;
}

int CStormnodeMan::CountEnabled()
{
    int i = 0;

    BOOST_FOREACH(CStormnode& sn, vStormnodes) {
        if(!sn.IsEnabled()) continue;
        i++;
    }

    return i;
}

CStormnode* CStormnodeMan::GetCurrentStormNode(int mod, int64_t nBlockHeight, int minProtocol)
{
    unsigned int score = 0;
    CStormnode* winner = NULL;

    // scan for winner
    BOOST_FOREACH(CStormnode& sn, vStormnodes) {
        sn.Check();
        if(sn.protocolVersion < minProtocol || !sn.IsEnabled()) continue;

        // calculate the score for each stormnode
        uint256 n = sn.CalculateScore(mod, nBlockHeight);
        unsigned int n2 = 0;
        memcpy(&n2, &n, sizeof(n2));

        // determine the winner
        if(n2 > score){
            score = n2;
            winner = &sn;
        }
    }

    return winner;
}

int CStormnodeMan::GetStormnodeRank(const CTxIn& vin, int64_t nBlockHeight, int minProtocol)
{
    std::vector<pair<unsigned int, CTxIn> > vecStormnodeScores;

    // scan for winner
    BOOST_FOREACH(CStormnode& sn, vStormnodes) {

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

void CStormnodeMan::ProcessMessage(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{

    if(fLiteMode) return; //disable all darksend/stormnode related functionality
    if(IsInitialBlockDownload()) return;

    LOCK(cs);

    if (strCommand == "dsee") { //DarkSend Election Entry

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
        //if(RegTest()) isLocal = false;

        std::string vchPubKey(pubkey.begin(), pubkey.end());
        std::string vchPubKey2(pubkey2.begin(), pubkey2.end());

        strMessage = addr.ToString() + boost::lexical_cast<std::string>(sigTime) + vchPubKey + vchPubKey2 + boost::lexical_cast<std::string>(protocolVersion);

        if(protocolVersion < MIN_SN_PROTO_VERSION) {
            LogPrintf("dsee - ignoring outdated stormnode %s protocol version %d\n", vin.ToString().c_str(), protocolVersion);
            return;
        }

        CScript pubkeyScript;
        pubkeyScript.SetDestination(pubkey.GetID());

        if(pubkeyScript.size() != 25) {
            LogPrintf("dsee - pubkey the wrong size\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        CScript pubkeyScript2;
        pubkeyScript2.SetDestination(pubkey2.GetID());

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
        CStormnode* sn = this->Find(vin);
        if(sn)
        {
            // count == -1 when it's a new entry
            //   e.g. We don't want the entry relayed/time updated when we're syncing the list
            // sn.pubkey = pubkey, IsVinAssociatedWithPubkey is validated once below,
            //   after that they just need to match
            if(count == -1 && sn->pubkey == pubkey && !sn->UpdatedWithin(STORMNODE_MIN_DSEE_SECONDS)){
                sn->UpdateLastSeen();

                if(sn->now < sigTime){ //take the newest entry
                    LogPrintf("dsee - Got updated entry for %s\n", addr.ToString().c_str());
                    sn->pubkey2 = pubkey2;
                    sn->now = sigTime;
                    sn->sig = vchSig;
                    sn->protocolVersion = protocolVersion;
                    sn->addr = addr;
                    sn->Check();
                    if(sn->IsEnabled())
                        RelaySandStormElectionEntry(vin, addr, vchSig, sigTime, pubkey, pubkey2, count, current, lastUpdated, protocolVersion);
                }
            }

            return;
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
        //  - this is checked later by .check() in many places and by ThreadCheckDarkSendPool()

        CValidationState state;
        CTransaction tx = CTransaction();
        CTxOut vout = CTxOut(STORMNODE_COLLATERAL*COIN, sandStormPool.collateralPubKey);
        tx.vin.push_back(vin);
        tx.vout.push_back(vout);
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
            CStormnode sn(addr, vin, pubkey, vchSig, sigTime, pubkey2, protocolVersion);
            sn.UpdateLastSeen(lastUpdated);
            this->Add(sn);

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

    else if (strCommand == "dseep") { //DarkSend Election Entry Ping

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
        CStormnode* sn = this->Find(vin);
        if(sn)
        {
            // LogPrintf("dseep - Found corresponding sn for vin: %s\n", vin.ToString().c_str());
            // take this only if it's newer
            if(sn->lastDseep < sigTime)
            {
                std::string strMessage = sn->addr.ToString() + boost::lexical_cast<std::string>(sigTime) + boost::lexical_cast<std::string>(stop);

                std::string errorMessage = "";
                if(!sandStormSigner.VerifyMessage(sn->pubkey2, vchSig, strMessage, errorMessage))
                {
                    LogPrintf("dseep - Got bad stormnode address signature %s \n", vin.ToString().c_str());
                    //Misbehaving(pfrom->GetId(), 100);
                    return;
                }

                sn->lastDseep = sigTime;

                if(!sn->UpdatedWithin(STORMNODE_MIN_DSEEP_SECONDS))
                {
                    if(stop) sn->Disable();
                    else
                    {
                        sn->UpdateLastSeen();
                        sn->Check();
                        if(!sn->IsEnabled()) return;
                    }
                    RelaySandStormElectionEntryPing(vin, vchSig, sigTime, stop);
                }
            }
            return;
        }

        if(fDebug) LogPrintf("dseep - Couldn't find stormnode entry %s\n", vin.ToString().c_str());

        std::map<COutPoint, int64_t>::iterator i = askedForStormnodeListEntry.find(vin.prevout);
        if (i != askedForStormnodeListEntry.end())
        {
            int64_t t = (*i).second;
            if (GetTime() < t) return; // we've asked recently
        }

        // ask for the dsee info once from the node that sent dseep

        LogPrintf("dseep - Asking source node for missing entry %s\n", vin.ToString().c_str());
        pfrom->PushMessage("dseg", vin);
        int64_t askAgain = GetTime()+(60*60*24);
        askedForStormnodeListEntry[vin.prevout] = askAgain;

    } else if (strCommand == "dseg") { //Get stormnode list or specific entry

        CTxIn vin;
        vRecv >> vin;

        if(vin == CTxIn()) { //only should ask for this once
            //local network
            if(!pfrom->addr.IsRFC1918() && Params().NetworkID() == CChainParams::MAIN)
            {
                std::map<CNetAddr, int64_t>::iterator i = askedForStormnodeList.find(pfrom->addr);
                if (i != askedForStormnodeList.end())
                {
                    int64_t t = (*i).second;
                    if (GetTime() < t) {
                        Misbehaving(pfrom->GetId(), 34);
                        LogPrintf("dseg - peer already asked me for the list\n");
                        return;
                    }
                }

                int64_t askAgain = GetTime()+(60*60*3);
                askedForStormnodeList[pfrom->addr] = askAgain;
            }
        } //else, asking for a specific node which is ok

        int count = this->size();
        int i = 0;

        BOOST_FOREACH(CStormnode& sn, vStormnodes) {

            if(sn.addr.IsRFC1918()) continue; //local network

            if(sn.IsEnabled())
            {
                if(fDebug) LogPrintf("dseg - Sending stormnode entry - %s \n", sn.addr.ToString().c_str());
                if(vin == CTxIn()){
                    pfrom->PushMessage("dsee", sn.vin, sn.addr, sn.sig, sn.now, sn.pubkey, sn.pubkey2, count, i, sn.lastTimeSeen, sn.protocolVersion);
                } else if (vin == sn.vin) {
                    pfrom->PushMessage("dsee", sn.vin, sn.addr, sn.sig, sn.now, sn.pubkey, sn.pubkey2, count, i, sn.lastTimeSeen, sn.protocolVersion);
                    LogPrintf("dseg - Sent 1 stormnode entries to %s\n", pfrom->addr.ToString().c_str());
                    return;
                }
                i++;
            }
        }

        LogPrintf("dseg - Sent %d stormnode entries to %s\n", i, pfrom->addr.ToString().c_str());
    }

}
