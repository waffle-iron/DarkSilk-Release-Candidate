// Copyright (c) 2014-2016 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>

#include <openssl/rand.h>

#include <algorithm>

#include "anon/sandstorm/sandstorm.h"
#include "init.h"
#include "util.h"
#include "anon/stormnode/stormnode-payments.h"
#include "anon/stormnode/stormnode-sync.h"
#include "script/script.h"
#include "anon/instantx/instantx.h"
#include "ui_interface.h"

using namespace std;
using namespace boost;

// The main object for accessing Sandstorm
CSandstormPool sandStormPool;
// A helper object for signing messages from Stormnodes
CSandStormSigner sandStormSigner;
// The current Sandstorms in progress on the network
std::vector<CSandstormQueue> vecSandstormQueue;
// Keep track of the used Stormnodes
std::vector<CTxIn> vecStormnodesUsed;
// Keep track of the scanning errors I've seen
map<uint256, CSandstormBroadcastTx> mapSandstormBroadcastTxes;
// Keep track of the active Stormnode
CActiveStormnode activeStormnode;

void CSandstormPool::ProcessMessageSandstorm(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{
    if(fLiteMode) return; //disable all Sandstorm/Stormnode related functionality
    if(!stormnodeSync.IsBlockchainSynced()) return;

    if (strCommand == "ssa") { //Sandstorm Accept Into Pool

        int errorID;

        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            errorID = ERR_VERSION;
            LogPrintf("ssa -- incompatible version! \n");
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);

            return;
        }

        if(!fStormNode){
            errorID = ERR_NOT_A_SN;
            LogPrintf("ssa -- not a Stormnode! \n");
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);

            return;
        }

        int nDenom;
        CTransaction txCollateral;
        vRecv >> nDenom >> txCollateral;

        CStormnode* psn = snodeman.Find(activeStormnode.vin);
        if(psn == NULL)
        {
            errorID = ERR_SN_LIST;
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
            return;
        }

        if(sessionUsers == 0) {
            if(psn->nLastSsq != 0 &&
                psn->nLastSsq + snodeman.CountEnabled(MIN_POOL_PEER_PROTO_VERSION)/5 > snodeman.nSsqCount){
                LogPrintf("ssa -- last ssq too recent, must wait. %s \n", pfrom->addr.ToString());
                errorID = ERR_RECENT;
                pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                return;
            }
        }

        if(!IsCompatibleWithSession(nDenom, txCollateral, errorID))
        {
            LogPrintf("ssa -- not compatible with existing transactions! \n");
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
            return;
        } else {
            LogPrintf("ssa -- is compatible, please submit! \n");
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_ACCEPTED, errorID);
            return;
        }

    } else if (strCommand == "ssq") { //Sandstorm Queue
        TRY_LOCK(cs_sandstorm, lockRecv);
        if(!lockRecv) return;

        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            return;
        }

        CSandstormQueue ssq;
        vRecv >> ssq;

        CService addr;
        if(!ssq.GetAddress(addr)) return;
        if(!ssq.CheckSignature()) return;

        if(ssq.IsExpired()) return;

        CStormnode* psn = snodeman.Find(ssq.vin);
        if(psn == NULL) return;

        // if the queue is ready, submit if we can
        if(ssq.ready) {
            if(!pSubmittedToStormnode) return;
            if((CNetAddr)pSubmittedToStormnode->addr != (CNetAddr)addr){
                LogPrintf("ssq - message doesn't match current Stormnode - %s != %s\n", pSubmittedToStormnode->addr.ToString(), addr.ToString());
                return;
            }

            if(state == POOL_STATUS_QUEUE){
                LogPrint("sandstorm", "Sandstorm queue is ready - %s\n", addr.ToString());
                PrepareSandstormDenominate();
            }
        } else {
            BOOST_FOREACH(CSandstormQueue q, vecSandstormQueue){
                if(q.vin == ssq.vin) return;
            }

            LogPrint("sandstorm", "ssq last %d last2 %d count %d\n", psn->nLastSsq, psn->nLastSsq + snodeman.size()/5, snodeman.nSsqCount);
            //don't allow a few nodes to dominate the queuing process
            if(psn->nLastSsq != 0 &&
                psn->nLastSsq + snodeman.CountEnabled(MIN_POOL_PEER_PROTO_VERSION)/5 > snodeman.nSsqCount){
                LogPrint("sandstorm", "ssq -- Stormnode sending too many ssq messages. %s \n", psn->addr.ToString());
                return;
            }
            snodeman.nSsqCount++;
            psn->nLastSsq = snodeman.nSsqCount;
            psn->allowFreeTx = true;

            LogPrint("sandstorm", "ssq - new Sandstorm queue object - %s\n", addr.ToString());
            vecSandstormQueue.push_back(ssq);
            ssq.Relay();
            ssq.time = GetTime();
        }

    } else if (strCommand == "ssi") { //SandStorm vIn
        int errorID;

        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            LogPrintf("ssi -- incompatible version! \n");
            errorID = ERR_VERSION;
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);

            return;
        }

        if(!fStormNode){
            LogPrintf("ssi -- not a Stormnode! \n");
            errorID = ERR_NOT_A_SN;
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);

            return;
        }

        std::vector<CTxIn> in;
        CAmount nAmount;
        CTransaction txCollateral;
        std::vector<CTxOut> out;
        vRecv >> in >> nAmount >> txCollateral >> out;

        //do we have enough users in the current session?
        if(!IsSessionReady()){
            LogPrintf("ssi -- session not complete! \n");
            errorID = ERR_SESSION;
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
            return;
        }

        //do we have the same denominations as the current session?
        if(!IsCompatibleWithEntries(out))
        {
            LogPrintf("ssi -- not compatible with existing transactions! \n");
            errorID = ERR_EXISTING_TX;
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
            return;
        }

        //check it like a transaction
        {
            CAmount nValueIn = 0;
            CAmount nValueOut = 0;
            bool missingTx = false;

            CValidationState state;
            CTransaction tx; //TODO (Amir): Use CMutableTransaction

            BOOST_FOREACH(const CTxOut o, out){
                nValueOut += o.nValue;
                tx.vout.push_back(o);

                if(o.scriptPubKey.size() != 25){
                    LogPrintf("ssi - non-standard pubkey detected! %s\n", o.scriptPubKey.ToString());
                    errorID = ERR_NON_STANDARD_PUBKEY;
                    pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                    return;
                }
                if(!o.scriptPubKey.IsNormalPaymentScript()){
                    LogPrintf("ssi - invalid script! %s\n", o.scriptPubKey.ToString());
                    errorID = ERR_INVALID_SCRIPT;
                    pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                    return;
                }
            }

            BOOST_FOREACH(const CTxIn i, in){
                tx.vin.push_back(i);

                LogPrint("sandstorm", "ssi -- tx in %s\n", i.ToString());

                CTransaction tx2;
                uint256 hash;
                if(GetTransaction(i.prevout.hash, tx2, hash)){
                    if(tx2.vout.size() > i.prevout.n) {
                        nValueIn += tx2.vout[i.prevout.n].nValue;
                    }
                } else{
                    missingTx = true;
                }
            }

            if (nValueIn > SANDSTORM_POOL_MAX) {
                LogPrintf("ssi -- more than Sandstorm pool max! %s\n", tx.ToString());
                errorID = ERR_MAXIMUM;
                pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                return;
            }

            if(!missingTx){
                if (nValueIn-nValueOut > nValueIn*.01) {
                    LogPrintf("ssi -- fees are too high! %s\n", tx.ToString());
                    errorID = ERR_FEES;
                    pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                    return;
                }
            } else {
                LogPrintf("ssi -- missing input tx! %s\n", tx.ToString());
                errorID = ERR_MISSING_TX;
                pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                return;
            }

            {
                LOCK(cs_main);
                if(!AcceptableInputs(mempool, state, tx, false, NULL, false)) {
                    LogPrintf("ssi -- transaction not valid! \n");
                    errorID = ERR_INVALID_TX;
                    pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
                    return;
                }
            }
        }

        if(AddEntry(in, nAmount, txCollateral, out, errorID)){
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_ACCEPTED, errorID);
            Check();

            RelayStatus(sessionID, GetState(), GetEntriesCount(), STORMNODE_RESET);
        } else {
            pfrom->PushMessage("sssu", sessionID, GetState(), GetEntriesCount(), STORMNODE_REJECTED, errorID);
        }

    } else if (strCommand == "sssu") { //Sandstorm status update
        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            return;
        }

        if(!pSubmittedToStormnode) return;
        if((CNetAddr)pSubmittedToStormnode->addr != (CNetAddr)pfrom->addr){
            //LogPrintf("sssu - message doesn't match current Stormnode - %s != %s\n", pSubmittedToStormnode->addr.ToString(), pfrom->addr.ToString());
            return;
        }

        int sessionIDMessage;
        int state;
        int entriesCount;
        int accepted;
        int errorID;
        vRecv >> sessionIDMessage >> state >> entriesCount >> accepted >> errorID;

        LogPrint("sandstorm", "sssu - state: %i entriesCount: %i accepted: %i error: %s \n", state, entriesCount, accepted, GetMessageByID(errorID));

        if((accepted != 1 && accepted != 0) && sessionID != sessionIDMessage){
            LogPrintf("sssu - message doesn't match current Sandstorm session %d %d\n", sessionID, sessionIDMessage);
            return;
        }

        StatusUpdate(state, entriesCount, accepted, errorID, sessionIDMessage);

    } else if (strCommand == "sss") { //Sandstorm Sign Final Tx

        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            return;
        }

        vector<CTxIn> sigs;
        vRecv >> sigs;

        bool success = false;
        int count = 0;

        BOOST_FOREACH(const CTxIn item, sigs)
        {
            if(AddScriptSig(item)) success = true;
            LogPrint("sandstorm", " -- sigs count %d %d\n", (int)sigs.size(), count);
            count++;
        }

        if(success){
            sandStormPool.Check();
            RelayStatus(sandStormPool.sessionID, sandStormPool.GetState(), sandStormPool.GetEntriesCount(), STORMNODE_RESET);
        }
    } else if (strCommand == "ssf") { //Sandstorm Final tx
        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            return;
        }

        if(!pSubmittedToStormnode) return;
        if((CNetAddr)pSubmittedToStormnode->addr != (CNetAddr)pfrom->addr){
            //LogPrintf("ssc - message doesn't match current Stormnode - %s != %s\n", pSubmittedToStormnode->addr.ToString(), pfrom->addr.ToString());
            return;
        }

        int sessionIDMessage;
        CTransaction txNew;
        vRecv >> sessionIDMessage >> txNew;

        if(sessionID != sessionIDMessage){
            LogPrint("sandstorm", "ssf - message doesn't match current Sandstorm session %d %d\n", sessionID, sessionIDMessage);
            return;
        }

        //check to see if input is spent already? (and probably not confirmed)
        SignFinalTransaction(txNew, pfrom);

    } else if (strCommand == "ssc") { //Sandstorm Complete

        if (pfrom->nVersion < MIN_POOL_PEER_PROTO_VERSION) {
            return;
        }

        if(!pSubmittedToStormnode) return;
        if((CNetAddr)pSubmittedToStormnode->addr != (CNetAddr)pfrom->addr){
            //LogPrintf("ssc - message doesn't match current Stormnode - %s != %s\n", pSubmittedToStormnode->addr.ToString(), pfrom->addr.ToString());
            return;
        }

        int sessionIDMessage;
        bool error;
        int errorID;
        vRecv >> sessionIDMessage >> error >> errorID;

        if(sessionID != sessionIDMessage){
            LogPrint("sandstorm", "ssc - message doesn't match current Sandstorm session %d %d\n", sandStormPool.sessionID, sessionIDMessage);
            return;
        }

        sandStormPool.CompletedTransaction(error, errorID);
    }

}

void CSandstormPool::Reset(){
    cachedLastSuccess = 0;
    lastNewBlock = 0;
    txCollateral = CMutableTransaction();
    vecStormnodesUsed.clear();
    UnlockCoins();
    SetNull();
}

void CSandstormPool::SetNull(){

    // SN side
    sessionUsers = 0;
    vecSessionCollateral.clear();

    // Client side
    entriesCount = 0;
    lastEntryAccepted = 0;
    countEntriesAccepted = 0;
    sessionFoundStormnode = false;

    // Both sides
    state = POOL_STATUS_IDLE;
    sessionID = 0;
    sessionDenom = 0;
    entries.clear();
    finalTransaction.vin.clear();
    finalTransaction.vout.clear();
    lastTimeChanged = GetTimeMillis();

    // -- seed random number generator (used for ordering output lists)
    unsigned int seed = 0;
    RAND_bytes((unsigned char*)&seed, sizeof(seed));
    std::srand(seed);
}

bool CSandstormPool::SetCollateralAddress(std::string strAddress){
    CDarkSilkAddress address;
    if (!address.SetString(strAddress))
    {
        LogPrintf("CSandstormPool::SetCollateralAddress - Invalid Sandstorm collateral address\n");
        return false;
    }
    collateralPubKey = GetScriptForDestination(address.Get());
    return true;
}

//
// Unlock coins after Sandstorm fails or succeeds
//
void CSandstormPool::UnlockCoins(){
    while(true) {
        TRY_LOCK(pwalletMain->cs_wallet, lockWallet);
        if(!lockWallet) {MilliSleep(50); continue;}
        BOOST_FOREACH(CTxIn v, lockedCoins)
                pwalletMain->UnlockCoin(v.prevout);
        break;
    }

    lockedCoins.clear();
}

std::string CSandstormPool::GetStatus()
{
    static int showingSandStormMessage = 0;
    showingSandStormMessage += 10;
    std::string suffix = "";

    if(pindexBest->nHeight - cachedLastSuccess < minBlockSpacing || !stormnodeSync.IsBlockchainSynced()) {
        return strAutoDenomResult;
    }
    switch(state) {
        case POOL_STATUS_IDLE:
            return _("Sandstorm is idle.");
        case POOL_STATUS_ACCEPTING_ENTRIES:
            if(entriesCount == 0) {
                showingSandStormMessage = 0;
                return strAutoDenomResult;
            } else if (lastEntryAccepted == 1) {
                if(showingSandStormMessage % 10 > 8) {
                    lastEntryAccepted = 0;
                    showingSandStormMessage = 0;
                }
                return _("Sandstorm request complete:") + " " + _("Your transaction was accepted into the pool!");
            } else {
                std::string suffix = "";
                if(     showingSandStormMessage % 70 <= 40) return strprintf(_("Submitted following entries to stormnode: %u / %d"), entriesCount, GetMaxPoolTransactions());
                else if(showingSandStormMessage % 70 <= 50) suffix = ".";
                else if(showingSandStormMessage % 70 <= 60) suffix = "..";
                else if(showingSandStormMessage % 70 <= 70) suffix = "...";
                return strprintf(_("Submitted to stormnode, waiting for more entries ( %u / %d ) %s"), entriesCount, GetMaxPoolTransactions(), suffix);
            }
        case POOL_STATUS_SIGNING:
            if(     showingSandStormMessage % 70 <= 40) return _("Found enough users, signing ...");
            else if(showingSandStormMessage % 70 <= 50) suffix = ".";
            else if(showingSandStormMessage % 70 <= 60) suffix = "..";
            else if(showingSandStormMessage % 70 <= 70) suffix = "...";
            return strprintf(_("Found enough users, signing ( waiting %s )"), suffix);
        case POOL_STATUS_TRANSMISSION:
            return _("Transmitting final transaction.");
        case POOL_STATUS_FINALIZE_TRANSACTION:
            return _("Finalizing transaction.");
        case POOL_STATUS_ERROR:
            return _("Sandstorm request incomplete:") + " " + lastMessage + " " + _("Will retry...");
        case POOL_STATUS_SUCCESS:
            return _("Sandstorm request complete:") + " " + lastMessage;
        case POOL_STATUS_QUEUE:
            if(     showingSandStormMessage % 70 <= 30) suffix = ".";
            else if(showingSandStormMessage % 70 <= 50) suffix = "..";
            else if(showingSandStormMessage % 70 <= 70) suffix = "...";
            return strprintf(_("Submitted to stormnode, waiting in queue %s"), suffix);;
       default:
            return strprintf(_("Unknown state: id = %u"), state);
    }
}

//
// Check the Sandstorm progress and send client updates if a Stormnode
//
void CSandstormPool::Check()
{
    if(fStormNode) LogPrint("sandstorm", "CSandstormPool::Check() - entries count %lu\n", entries.size());
    //printf("CSandstormPool::Check() %d - %d - %d\n", state, anonTx.CountEntries(), GetTimeMillis()-lastTimeChanged);

    if(fStormNode) {
        LogPrint("sandstorm", "CSandstormPool::Check() - entries count %lu\n", entries.size());

        // If entries is full, then move on to the next phase
        if(state == POOL_STATUS_ACCEPTING_ENTRIES && (int)entries.size() >= GetMaxPoolTransactions())
        {
            LogPrint("sandstorm", "CSandstormPool::Check() -- TRYING TRANSACTION \n");
            UpdateState(POOL_STATUS_FINALIZE_TRANSACTION);
        }
    }

    // create the finalized transaction for distribution to the clients
    if(state == POOL_STATUS_FINALIZE_TRANSACTION) {
        LogPrint("sandstorm", "CSandstormPool::Check() -- FINALIZE TRANSACTIONS\n");
        UpdateState(POOL_STATUS_SIGNING);

        if (fStormNode) {
            CMutableTransaction txNew;

            // make our new transaction
            for(unsigned int i = 0; i < entries.size(); i++){
                BOOST_FOREACH(const CTxOut& v, entries[i].vout)
                    txNew.vout.push_back(v);

                BOOST_FOREACH(const CTxSSIn& s, entries[i].sev)
                    txNew.vin.push_back(s);
            }

            // BIP69 https://github.com/kristovatlas/bips/blob/master/bip-0069.mediawiki
            // TODO (Amir): Put the sort lines back.  get strange errors. no match for 'operator<'
            //sort(txNew.vin.begin(), txNew.vin.end());
            //sort(txNew.vout.begin(), txNew.vout.end());


            LogPrint("sandstorm", "Transaction 1: %s\n", txNew.ToString());
            finalTransaction = txNew;

            // request signatures from clients
            RelayFinalTransaction(sessionID, finalTransaction);
        }
    }

    // If we have all of the signatures, try to compile the transaction
    if(fStormNode && state == POOL_STATUS_SIGNING && SignaturesComplete()) {
        LogPrint("sandstorm", "CSandstormPool::Check() -- SIGNING\n");
        UpdateState(POOL_STATUS_TRANSMISSION);

        CheckFinalTransaction();
    }

    // reset if we're here for 10 seconds
    if((state == POOL_STATUS_ERROR || state == POOL_STATUS_SUCCESS) && GetTimeMillis()-lastTimeChanged >= 10000) {
        LogPrint("sandstorm", "CSandstormPool::Check() -- timeout, RESETTING\n");
        UnlockCoins();
        SetNull();
        if(fStormNode) RelayStatus(sessionID, GetState(), GetEntriesCount(), STORMNODE_RESET);
    }
}

void CSandstormPool::CheckFinalTransaction()
{
    if (!fStormNode) return; // check and relay final tx only on stormnode

    CWalletTx txNew = CWalletTx(pwalletMain, finalTransaction);


    LogPrint("sandstorm", "Transaction 2: %s\n", txNew.ToString());

    {
        LOCK(cs_main);
        // See if the transaction is valid
        if (!txNew.AcceptToMemoryPool(false, true, true))
        {
            LogPrintf("CSandstormPool::Check() - CommitTransaction : Error: Transaction not valid\n");
            SetNull();

            // not much we can do in this case
            UpdateState(POOL_STATUS_ACCEPTING_ENTRIES);
            RelayCompletedTransaction(sessionID, true, ERR_INVALID_TX);
            return;
        }
    }
    LogPrintf("CDarksendPool::Check() -- IS MASTER -- TRANSMITTING DARKSEND\n");
 
    // sign a message
    int64_t sigTime = GetAdjustedTime();
    std::string strMessage = txNew.GetHash().ToString() + boost::lexical_cast<std::string>(sigTime);
    std::string strError = "";
    std::vector<unsigned char> vchSig;
    CKey key2;
    CPubKey pubkey2;

    if(!sandStormSigner.SetKey(strStormNodePrivKey, strError, key2, pubkey2))
    {
        LogPrintf("CSandstormPool::Check() - ERROR: Invalid Stormnodeprivkey: '%s'\n", strError);
        return;
    }

    if(!sandStormSigner.SignMessage(strMessage, strError, vchSig, key2)) {
        LogPrintf("CSandstormPool::Check() - Sign message failed\n");
        return;
    }

    if(!sandStormSigner.VerifyMessage(pubkey2, vchSig, strMessage, strError)) {
        LogPrintf("CSandstormPool::Check() - Verify message failed\n");
        return;
    }

    if(!mapSandstormBroadcastTxes.count(txNew.GetHash())){
        CSandstormBroadcastTx sstx;
        sstx.tx = txNew;
        sstx.vin = activeStormnode.vin;
        sstx.vchSig = vchSig;
        sstx.sigTime = sigTime;

        mapSandstormBroadcastTxes.insert(make_pair(txNew.GetHash(), sstx));
    }

    CInv inv(MSG_SSTX, txNew.GetHash());
    RelayInv(inv);

    // Tell the clients it was successful
    RelayCompletedTransaction(sessionID, false, MSG_SUCCESS);

    // Randomly charge clients
    ChargeRandomFees();

    // Reset
    LogPrint("sandstorm", "CSandstormPool::Check() -- COMPLETED -- RESETTING\n");
    SetNull();
    RelayStatus(sessionID, GetState(), GetEntriesCount(), STORMNODE_RESET);
}

//
// Charge clients a fee if they're abusive
//
// Why bother? Sandstorm uses collateral to ensure abuse to the process is kept to a minimum.
// The submission and signing stages in Sandstorm are completely separate. In the cases where
// a client submits a transaction then refused to sign, there must be a cost. Otherwise they
// would be able to do this over and over again and bring the mixing to a hault.
//
// How does this work? Messages to Stormnodes come in via "ssi", these require a valid collateral
// transaction for the client to be able to enter the pool. This transaction is kept by the Stormnode
// until the transaction is either complete or fails.
//
void CSandstormPool::ChargeFees(){
    if(!fStormNode) return;

    //we don't need to charge collateral for every offence.
    int offences = 0;
    int r = rand()%100;
    if(r > 33) return;

    if(state == POOL_STATUS_ACCEPTING_ENTRIES){
        BOOST_FOREACH(const CTransaction& txCollateral, vecSessionCollateral) {
            bool found = false;
            BOOST_FOREACH(const CSandStormEntry& v, entries) {
                if(v.collateral == txCollateral) {
                    found = true;
                }
            }

            // This queue entry didn't send us the promised transaction
            if(!found){
                LogPrintf("CSandstormPool::ChargeFees -- found uncooperative node (didn't send transaction). Found offence.\n");
                offences++;
            }
        }
    }

    if(state == POOL_STATUS_SIGNING) {
        // who didn't sign?
        BOOST_FOREACH(const CSandStormEntry v, entries) {
            BOOST_FOREACH(const CTxSSIn s, v.sev) {
                if(!s.fHasSig){
                    LogPrintf("CSandstormPool::ChargeFees -- found uncooperative node (didn't sign). Found offence\n");
                    offences++;
                }
            }
        }
    }

    r = rand()%100;
    int target = 0;

    //mostly offending?
    if(offences >= Params().PoolMaxTransactions()-1 && r > 33) return;

    //everyone is an offender? That's not right
    if(offences >= Params().PoolMaxTransactions()) return;

    //charge one of the offenders randomly
    if(offences > 1) target = 50;

    //pick random client to charge
    r = rand()%100;

    if(state == POOL_STATUS_ACCEPTING_ENTRIES){
        BOOST_FOREACH(const CTransaction& txCollateral, vecSessionCollateral) {
            bool found = false;
            BOOST_FOREACH(const CSandStormEntry& v, entries) {
                if(v.collateral == txCollateral) {
                    found = true;
                }
            }

            // This queue entry didn't send us the promised transaction
            if(!found && r > target){
                LogPrintf("CSandstormPool::ChargeFees -- found uncooperative node (didn't send transaction). charging fees.\n");

                CWalletTx wtxCollateral = CWalletTx(pwalletMain, txCollateral);

                // Broadcast
                if (!wtxCollateral.AcceptToMemoryPool(true))
                {
                    // This must not fail. The transaction has already been signed and recorded.
                    LogPrintf("CSandstormPool::ChargeFees() : Error: Transaction not valid");
                }
                wtxCollateral.RelayWalletTransaction();
                return;
            }
        }
    }

    if(state == POOL_STATUS_SIGNING) {
        // who didn't sign?
        BOOST_FOREACH(const CSandStormEntry v, entries) {
            BOOST_FOREACH(const CTxSSIn s, v.sev) {
                if(!s.fHasSig && r > target){
                    LogPrintf("CSandstormPool::ChargeFees -- found uncooperative node (didn't sign). charging fees.\n");

                    CWalletTx wtxCollateral = CWalletTx(pwalletMain, v.collateral);

                    // Broadcast
                    if (!wtxCollateral.AcceptToMemoryPool(false))
                    {
                        // This must not fail. The transaction has already been signed and recorded.
                        LogPrintf("CSandstormPool::ChargeFees() : Error: Transaction not valid");
                    }
                    wtxCollateral.RelayWalletTransaction();
                    return;
                }
            }
        }
    }
}

// charge the collateral randomly
//  - Sandstorm is completely free, to pay miners we randomly pay the collateral of users.
void CSandstormPool::ChargeRandomFees(){
    if(fStormNode) {
        int i = 0;

        BOOST_FOREACH(const CTransaction& txCollateral, vecSessionCollateral) {
            int r = rand()%100;

            /*
                Collateral Fee Charges:

                Being that Sandstorm has "no fees" we need to have some kind of cost associated
                with using it to stop abuse. Otherwise it could serve as an attack vector and
                allow endless transaction that would bloat DarkSilk and make it unusable. To
                stop these kinds of attacks 1 in 10 successful transactions are charged. This
                adds up to a cost of 0.001DRK per transaction on average.
            */
            if(r <= 10)
            {
                LogPrintf("CSandstormPool::ChargeRandomFees -- charging random fees. %u\n", i);

                CWalletTx wtxCollateral = CWalletTx(pwalletMain, txCollateral);

                // Broadcast
                if (!wtxCollateral.AcceptToMemoryPool(true))
                {
                    // This must not fail. The transaction has already been signed and recorded.
                    LogPrintf("CSandstormPool::ChargeRandomFees() : Error: Transaction not valid");
                }
                wtxCollateral.RelayWalletTransaction();
            }
        }
    }
}

//
// Check for various timeouts (queue objects, Sandstorm, etc)
//
void CSandstormPool::CheckTimeout(){

    // check Sandstorm queue objects for timeouts
    int c = 0;
    vector<CSandstormQueue>::iterator it = vecSandstormQueue.begin();
    while(it != vecSandstormQueue.end()){
        if((*it).IsExpired()){
            LogPrint("sandstorm", "CSandstormPool::CheckTimeout() : Removing expired queue entry - %d\n", c);
            it = vecSandstormQueue.erase(it);
        } else ++it;
        c++;
    }

    if(!fEnableSandstorm && !fStormNode) return;

    // catching hanging sessions
    if(!fStormNode) {
        switch(state) {
            case POOL_STATUS_TRANSMISSION:
                LogPrint("sandstorm", "CSandstormPool::CheckTimeout() -- Session complete -- Running Check()\n");
                Check();
                break;
            case POOL_STATUS_ERROR:
                LogPrint("sandstorm", "CSandstormPool::CheckTimeout() -- Pool error -- Running Check()\n");
                Check();
                break;
            case POOL_STATUS_SUCCESS:
                LogPrint("sandstorm", "CSandstormPool::CheckTimeout() -- Pool success -- Running Check()\n");
                Check();
                break;
        }
    }

    int addLagTime = 0;
    if(!fStormNode) addLagTime = 10000; //if we're the client, give the server a few extra seconds before resetting.

    if(state == POOL_STATUS_ACCEPTING_ENTRIES || state == POOL_STATUS_QUEUE){
        c = 0;

        // check for a timeout and reset if needed
        vector<CSandStormEntry>::iterator it2 = entries.begin();
        while(it2 != entries.end()){
            if((*it2).IsExpired()){
                LogPrint("sandstorm", "CSandstormPool::CheckTimeout() : Removing expired entry - %d\n", c);
                it2 = entries.erase(it2);
                if(entries.size() == 0){
                    UnlockCoins();
                    SetNull();
                }
                if(fStormNode){
                    RelayStatus(sessionID, GetState(), GetEntriesCount(), STORMNODE_RESET);
                }
            } else ++it2;
            c++;
        }

        if(GetTimeMillis()-lastTimeChanged >= (SANDSTORM_QUEUE_TIMEOUT*1000)+addLagTime){
            UnlockCoins();
            SetNull();
        }
    } else if(GetTimeMillis()-lastTimeChanged >= (SANDSTORM_QUEUE_TIMEOUT*1000)+addLagTime){
        LogPrint("sandstorm", "CSandstormPool::CheckTimeout() -- Session timed out (%ds) -- resetting\n", SANDSTORM_QUEUE_TIMEOUT);
        UnlockCoins();
        SetNull();

        UpdateState(POOL_STATUS_ERROR);
        lastMessage = _("Session timed out.");
    }

    if(state == POOL_STATUS_SIGNING && GetTimeMillis()-lastTimeChanged >= (SANDSTORM_SIGNING_TIMEOUT*1000)+addLagTime ) {
            LogPrint("sandstorm", "CSandstormPool::CheckTimeout() -- Session timed out (%ds) -- restting\n", SANDSTORM_SIGNING_TIMEOUT);
            ChargeFees();
            UnlockCoins();
            SetNull();

            UpdateState(POOL_STATUS_ERROR);
            lastMessage = _("Signing timed out.");
    }
}

//
// Check for complete queue
//
void CSandstormPool::CheckForCompleteQueue(){
    if(!fEnableSandstorm && !fStormNode) return;

    /* Check to see if we're ready for submissions from clients */
    //
    // After receiving multiple ssa messages, the queue will switch to "accepting entries"
    // which is the active state right before merging the transaction
    //
    if(state == POOL_STATUS_QUEUE && sessionUsers == GetMaxPoolTransactions()) {
        UpdateState(POOL_STATUS_ACCEPTING_ENTRIES);

        CSandstormQueue ssq;
        ssq.nDenom = sessionDenom;
        ssq.vin = activeStormnode.vin;
        ssq.time = GetTime();
        ssq.ready = true;
        ssq.Sign();
        ssq.Relay();
    }
}

// check to see if the signature is valid
bool CSandstormPool::SignatureValid(const CScript& newSig, const CTxIn& newVin){
    CMutableTransaction txNew;
    txNew.vin.clear();
    txNew.vout.clear();

    int found = -1;
    CScript sigPubKey = CScript();
    unsigned int i = 0;

    BOOST_FOREACH(CSandStormEntry& e, entries) {
        BOOST_FOREACH(const CTxOut& out, e.vout)
            txNew.vout.push_back(out);

        BOOST_FOREACH(const CTxSSIn& s, e.sev){
            txNew.vin.push_back(s);

            if(s == newVin){
                found = i;
                sigPubKey = s.prevPubKey;
            }
            i++;
        }
    }

    if(found >= 0){ //might have to do this one input at a time?
        int n = found;
        txNew.vin[n].scriptSig = newSig;
        LogPrint("sandstorm", "CSandstormPool::SignatureValid() - Sign with sig %s\n", newSig.ToString().substr(0,24));
        if (!VerifyScript(txNew.vin[n].scriptSig, sigPubKey, SCRIPT_VERIFY_P2SH | SCRIPT_VERIFY_STRICTENC, MutableTransactionSignatureChecker(&txNew, n))){
            LogPrint("sandstorm", "CSandstormPool::SignatureValid() - Signing - Error signing input %u\n", n);
            return false;
        }
    }

    LogPrint("sandstorm", "CSandstormPool::SignatureValid() - Signing - Successfully validated input\n");
    return true;
}

// check to make sure the collateral provided by the client is valid
bool CSandstormPool::IsCollateralValid(const CTransaction& txCollateral){
    if(txCollateral.vout.size() < 1) return false;
    if(txCollateral.nLockTime != 0) return false;

    CAmount nValueIn = 0;
    CAmount nValueOut = 0;
    bool missingTx = false;

    BOOST_FOREACH(const CTxOut o, txCollateral.vout){
        nValueOut += o.nValue;

        if(!o.scriptPubKey.IsNormalPaymentScript()){
            LogPrintf ("CSandstormPool::IsCollateralValid - Invalid Script %s", txCollateral.ToString());
            return false;
        }
    }

    BOOST_FOREACH(const CTxIn i, txCollateral.vin){
        CTransaction tx2;
        uint256 hash;
        if(GetTransaction(i.prevout.hash, tx2, hash)){
            if(tx2.vout.size() > i.prevout.n) {
                nValueIn += tx2.vout[i.prevout.n].nValue;
            }
        } else{
            missingTx = true;
        }
    }

    if(missingTx){
        LogPrint("sandstorm", "CSandstormPool::IsCollateralValid - Unknown inputs in collateral transaction - %s", txCollateral.ToString());
        return false;
    }

    //collateral transactions are required to pay out SANDSTORM_COLLATERAL as a fee to the miners
    if(nValueIn - nValueOut < SANDSTORM_COLLATERAL) {
        LogPrint("sandstorm", "CSandstormPool::IsCollateralValid - did not include enough fees in transaction %d\n%s", nValueOut-nValueIn, txCollateral.ToString());
        return false;
    }

    LogPrint("sandstorm", "CSandstormPool::IsCollateralValid %s", txCollateral.ToString());

    {
        LOCK(cs_main);
        CValidationState state;
        //TODO (Amir) Put this back.  getting errors.
        //if(!AcceptableInputs(mempool, txCollateral, true, NULL)){
            //if(fDebug) LogPrintf ("CSandstormPool::IsCollateralValid - didn't pass IsAcceptable\n");
            //return false;
        //}
    }

    return true;
}

//
// Add a clients transaction to the pool
//
bool CSandstormPool::AddEntry(const std::vector<CTxIn>& newInput, const CAmount& nAmount, const CTransaction& txCollateral, const std::vector<CTxOut>& newOutput, int& errorID){
    if (!fStormNode) return false;

    BOOST_FOREACH(CTxIn in, newInput) {
        if (in.prevout.IsNull() || nAmount < 0) {
            LogPrint("sandstorm", "CSandstormPool::AddEntry - input not valid!\n");
            errorID = ERR_INVALID_INPUT;
            sessionUsers--;
            return false;
        }
    }

    if (!IsCollateralValid(txCollateral)){
        LogPrint("sandstorm", "CSandstormPool::AddEntry - collateral not valid!\n");
        errorID = ERR_INVALID_COLLATERAL;
        sessionUsers--;
        return false;
    }

    if((int)entries.size() >= GetMaxPoolTransactions()){
        LogPrint("sandstorm", "CSandstormPool::AddEntry - entries is full!\n");
        errorID = ERR_ENTRIES_FULL;
        sessionUsers--;
        return false;
    }

    BOOST_FOREACH(CTxIn in, newInput) {
        LogPrint("sandstorm", "looking for vin -- %s\n", in.ToString());
        BOOST_FOREACH(const CSandStormEntry& v, entries) {
            BOOST_FOREACH(const CTxSSIn& s, v.sev){
                if((CTxIn)s == in) {
                    LogPrint("sandstorm", "CSandstormPool::AddEntry - found in vin\n");
                    errorID = ERR_ALREADY_HAVE;
                    sessionUsers--;
                    return false;
                }
            }
        }
    }

    CSandStormEntry v;
    v.Add(newInput, nAmount, txCollateral, newOutput);
    entries.push_back(v);

    LogPrint("sandstorm", "CSandstormPool::AddEntry -- adding %s\n", newInput[0].ToString());
    errorID = MSG_ENTRIES_ADDED;

    return true;
}

bool CSandstormPool::AddScriptSig(const CTxIn& newVin){
    LogPrint("sandstorm", "CSandstormPool::AddScriptSig -- new sig  %s\n", newVin.scriptSig.ToString().substr(0,24));


    BOOST_FOREACH(const CSandStormEntry& v, entries) {
        BOOST_FOREACH(const CTxSSIn& s, v.sev){
            if(s.scriptSig == newVin.scriptSig) {
                LogPrint("sandstorm", "CSandstormPool::AddScriptSig - already exists\n");
                return false;
            }
        }
    }

    if(!SignatureValid(newVin.scriptSig, newVin)){
        LogPrint("sandstorm", "CSandstormPool::AddScriptSig - Invalid Sig\n");
        return false;
    }

    LogPrint("sandstorm", "CSandstormPool::AddScriptSig -- sig %s\n", newVin.ToString());

    BOOST_FOREACH(CTxIn& vin, finalTransaction.vin){
        if(newVin.prevout == vin.prevout && vin.nSequence == newVin.nSequence){
            vin.scriptSig = newVin.scriptSig;
            vin.prevPubKey = newVin.prevPubKey;
            LogPrint("sandstorm", "CSandStormPool::AddScriptSig -- adding to finalTransaction  %s\n", newVin.scriptSig.ToString().substr(0,24));
        }
    }
    for(unsigned int i = 0; i < entries.size(); i++){
        if(entries[i].AddSig(newVin)){
            LogPrint("sandstorm", "CSandStormPool::AddScriptSig -- adding  %s\n", newVin.scriptSig.ToString().substr(0,24));
            return true;
        }
    }

    LogPrintf("CSandstormPool::AddScriptSig -- Couldn't set sig!\n" );
    return false;
}

// Check to make sure everything is signed
bool CSandstormPool::SignaturesComplete(){
    BOOST_FOREACH(const CSandStormEntry& v, entries) {
        BOOST_FOREACH(const CTxSSIn& s, v.sev){
            if(!s.fHasSig) return false;
        }
    }
    return true;
}

//
// Execute a Sandstorm denomination via a Stormnode.
// This is only ran from clients
//
void CSandstormPool::SendSandstormDenominate(std::vector<CTxIn>& vin, std::vector<CTxOut>& vout, CAmount amount){

    if(fStormNode) {
        LogPrintf("CSandstormPool::SendSandstormDenominate() - Sandstorm from a Stormnode is not supported currently.\n");
        return;
    }

    //TODO (Amir): Put these lines back.
    //if(txCollateral == CMutableTransaction()){
    //    LogPrintf ("CSandstormPool:SendSandstormDenominate() - Sandstorm collateral not set");
    //    return;
    //}

    // lock the funds we're going to use
    BOOST_FOREACH(CTxIn in, txCollateral.vin)
        lockedCoins.push_back(in);

    BOOST_FOREACH(CTxIn in, vin)
        lockedCoins.push_back(in);

    //BOOST_FOREACH(CTxOut o, vout)
    //    LogPrintf(" vout - %s\n", o.ToString());


    // we should already be connected to a Stormnode
    if(!sessionFoundStormnode){
        LogPrintf("CSandstormPool::SendSandstormDenominate() - No Stormnode has been selected yet.\n");
        UnlockCoins();
        SetNull();
        return;
    }

    if (!CheckDiskSpace()) {
        UnlockCoins();
        SetNull();
        fEnableSandstorm = false;
        LogPrintf("CSandstormPool::SendSandstormDenominate() - Not enough disk space, disabling Sandstorm.\n");
        return;
    }

    UpdateState(POOL_STATUS_ACCEPTING_ENTRIES);

    LogPrintf("CSandstormPool::SendSandstormDenominate() - Added transaction to pool.\n");

    ClearLastMessage();

    //check it against the memory pool to make sure it's valid
    {
        CAmount nValueOut = 0;

        CValidationState state;
        CTransaction tx; //TODO (Amir): Use CMutableTransaction

        BOOST_FOREACH(const CTxOut& o, vout){
            nValueOut += o.nValue;
            tx.vout.push_back(o);
        }

        BOOST_FOREACH(const CTxIn& i, vin){
            tx.vin.push_back(i);

            LogPrint("sandstorm", "ssi -- tx in %s\n", i.ToString());
        }

        LogPrintf("Submitting tx %s\n", tx.ToString());

        while(true){
            TRY_LOCK(cs_main, lockMain);
            if(!lockMain) { MilliSleep(50); continue;}
            if(!AcceptableInputs(mempool, state, tx, false, NULL, false, true)){
                LogPrintf("ssi -- transaction not valid! %s \n", tx.ToString());
                UnlockCoins();
                SetNull();
                return;
            }
            break;
        }
    }

    // store our entry for later use
    CSandStormEntry e;
    e.Add(vin, amount, txCollateral, vout);
    entries.push_back(e);

    RelayIn(entries[0].sev, entries[0].amount, txCollateral, entries[0].vout);
    Check();
}

// Incoming message from Stormnode updating the progress of Sandstorm
//    newAccepted:  -1 mean's it'n not a "transaction accepted/not accepted" message, just a standard update
//                  0 means transaction was not accepted
//                  1 means transaction was accepted

bool CSandstormPool::StatusUpdate(int newState, int newEntriesCount, int newAccepted, int& errorID, int newSessionID){
    if(fStormNode) return false;
    if(state == POOL_STATUS_ERROR || state == POOL_STATUS_SUCCESS) return false;

    UpdateState(newState);
    entriesCount = newEntriesCount;

    if(errorID != MSG_NOERR) strAutoDenomResult = _("Stormnode:") + " " + GetMessageByID(errorID);

    if(newAccepted != -1) {
        lastEntryAccepted = newAccepted;
        countEntriesAccepted += newAccepted;
        if(newAccepted == 0){
            UpdateState(POOL_STATUS_ERROR);
            lastMessage = GetMessageByID(errorID);
        }

        if(newAccepted == 1 && newSessionID != 0) {
            sessionID = newSessionID;
            LogPrintf("CSandstormPool::StatusUpdate - set sessionID to %d\n", sessionID);
            sessionFoundStormnode = true;
        }
    }

    if(newState == POOL_STATUS_ACCEPTING_ENTRIES){
        if(newAccepted == 1){
            LogPrintf("CSandstormPool::StatusUpdate - entry accepted! \n");
            sessionFoundStormnode = true;
            //wait for other users. Stormnode will report when ready
            UpdateState(POOL_STATUS_QUEUE);
        } else if (newAccepted == 0 && sessionID == 0 && !sessionFoundStormnode) {
            LogPrintf("CSandstormPool::StatusUpdate - entry not accepted by Stormnode \n");
            UnlockCoins();
            UpdateState(POOL_STATUS_ACCEPTING_ENTRIES);
            DoAutomaticDenominating(); //try another Stormnode
        }
        if(sessionFoundStormnode) return true;
    }

    return true;
}

//
// After we receive the finalized transaction from the Stormnode, we must
// check it to make sure it's what we want, then sign it if we agree.
// If we refuse to sign, it's possible we'll be charged collateral
//
bool CSandstormPool::SignFinalTransaction(CTransaction& finalTransactionNew, CNode* node){
    if(fStormNode) return false;

    finalTransaction = finalTransactionNew;
    LogPrintf("CSandstormPool::SignFinalTransaction %s", finalTransaction.ToString());

    vector<CTxIn> sigs;

    //make sure my inputs/outputs are present, otherwise refuse to sign
    BOOST_FOREACH(const CSandStormEntry e, entries) {
        BOOST_FOREACH(const CTxSSIn s, e.sev) {
            /* Sign my transaction and all outputs */
            int mine = -1;
            CScript prevPubKey = CScript();
            CTxIn vin = CTxIn();

            for(unsigned int i = 0; i < finalTransaction.vin.size(); i++){
                if(finalTransaction.vin[i] == s){
                    mine = i;
                    prevPubKey = s.prevPubKey;
                    vin = s;
                }
            }

            if(mine >= 0){ //might have to do this one input at a time?
                int foundOutputs = 0;
                CAmount nValue1 = 0;
                CAmount nValue2 = 0;

                for(unsigned int i = 0; i < finalTransaction.vout.size(); i++){
                    BOOST_FOREACH(const CTxOut& o, e.vout) {
                        if(finalTransaction.vout[i] == o){
                            foundOutputs++;
                            nValue1 += finalTransaction.vout[i].nValue;
                        }
                    }
                }

                BOOST_FOREACH(const CTxOut o, e.vout)
                    nValue2 += o.nValue;

                int targetOuputs = e.vout.size();
                if(foundOutputs < targetOuputs || nValue1 != nValue2) {
                    // in this case, something went wrong and we'll refuse to sign. It's possible we'll be charged collateral. But that's
                    // better then signing if the transaction doesn't look like what we wanted.
                    LogPrintf("CSandstormPool::Sign - My entries are not correct! Refusing to sign. %d entries %d target. \n", foundOutputs, targetOuputs);
                    UnlockCoins();
                    SetNull();

                    return false;
                }

                const CKeyStore& keystore = *pwalletMain;

                LogPrint("sandstorm", "CSandstormPool::Sign - Signing my input %i\n", mine);
                if(!SignSignature(keystore, prevPubKey, finalTransaction, mine, int(SIGHASH_ALL|SIGHASH_ANYONECANPAY))) { // changes scriptSig
                    LogPrint("sandstorm", "CSandstormPool::Sign - Unable to sign my own transaction! \n");
                    // not sure what to do here, it will timeout...?
                }

                sigs.push_back(finalTransaction.vin[mine]);
                LogPrint("sandstorm", " -- dss %d %d %s\n", mine, (int)sigs.size(), finalTransaction.vin[mine].scriptSig.ToString());
            }

        }

        LogPrint("sandstorm", "CSandstormPool::Sign - txNew:\n%s", finalTransaction.ToString());
    }

    // push all of our signatures to the Stormnode
    if(sigs.size() > 0 && node != NULL)
        node->PushMessage("sss", sigs);


    return true;
}

void CSandstormPool::NewBlock()
{
    LogPrint("sandstorm", "CSandstormPool::NewBlock \n");

    //we we're processing lots of blocks, we'll just leave
    if(GetTime() - lastNewBlock < 10) return;
    lastNewBlock = GetTime();

    sandStormPool.CheckTimeout();
}

// Sandstorm transaction was completed (failed or successful)
void CSandstormPool::CompletedTransaction(bool error, int errorID)
{
    if(fStormNode) return;

    if(error){
        LogPrintf("CompletedTransaction -- error \n");
        UpdateState(POOL_STATUS_ERROR);

        Check();
        UnlockCoins();
        SetNull();
    } else {
        LogPrintf("CompletedTransaction -- success \n");
        UpdateState(POOL_STATUS_SUCCESS);

        UnlockCoins();
        SetNull();

        // To avoid race conditions, we'll only let SS run once per block
        cachedLastSuccess = pindexBest->nHeight;
    }
    lastMessage = GetMessageByID(errorID);
}

void CSandstormPool::ClearLastMessage()
{
    lastMessage = "";
}

//
// Passively run Sandstorm in the background to anonymize funds based on the given configuration.
//
// This does NOT run by default for daemons, only for QT.
//
bool CSandstormPool::DoAutomaticDenominating(bool fDryRun)
{
    if(!fEnableSandstorm) return false;
    if(fStormNode) return false;
    if(state == POOL_STATUS_ERROR || state == POOL_STATUS_SUCCESS) return false;
    if(GetEntriesCount() > 0) {
        strAutoDenomResult = _("Mixing in progress...");
        return false;
    }

    TRY_LOCK(cs_sandstorm, lockSS);
    if(!lockSS) {
        strAutoDenomResult = _("Lock is already in place.");
        return false;
    }

    if(!stormnodeSync.IsBlockchainSynced()) {
        strAutoDenomResult = _("Can't mix while sync in progress.");
        return false;
    }

    if (!fDryRun && pwalletMain->IsLocked()){
        strAutoDenomResult = _("Wallet is locked.");
        return false;
    }

    if(pindexBest->nHeight - cachedLastSuccess < minBlockSpacing) {
        LogPrintf("CSandstormPool::DoAutomaticDenominating - Last successful Sandstorm action was too recent\n");
        strAutoDenomResult = _("Last successful Sandstorm action was too recent.");
        return false;
    }

    if(snodeman.size() == 0){
        LogPrint("sandstorm", "CSandstormPool::DoAutomaticDenominating - No Stormnodes detected\n");
        strAutoDenomResult = _("No Stormnodes detected.");
        return false;
    }

    // ** find the coins we'll use
    std::vector<CTxIn> vCoins;
    CAmount nValueMin = CENT;
    CAmount nValueIn = 0;

    CAmount nOnlyDenominatedBalance;
    CAmount nBalanceNeedsDenominated;

    // should not be less than fees in SANDSTORM_COLLATERAL + few (lets say 5) smallest denoms
    CAmount nLowestDenom = sandStormDenominations[sandStormDenominations.size() - 1];

    // if there are no confirmed SS collateral inputs yet
    if(!pwalletMain->HasCollateralInputs())
        // should have some additional amount for them
        nLowestDenom += SANDSTORM_COLLATERAL*4;

    CAmount nBalanceNeedsAnonymized = nAnonymizeDarkSilkAmount*COIN - pwalletMain->GetAnonymizedBalance();

    // if balanceNeedsAnonymized is more than pool max, take the pool max
    if(nBalanceNeedsAnonymized > SANDSTORM_POOL_MAX) nBalanceNeedsAnonymized = SANDSTORM_POOL_MAX;

    // try to overshoot target DS balance up to nLowestDenom
    nBalanceNeedsAnonymized += nLowestDenom;

    CAmount nAnonymizableBalance = pwalletMain->GetAnonymizableBalance();

    // anonymizable balance is way too small
    if(nAnonymizableBalance < nLowestDenom)
    {
        LogPrintf("DoAutomaticDenominating : No funds detected in need of denominating \n");
        strAutoDenomResult = _("No funds detected in need of denominating.");
        return false;
    }

    // not enough funds to anonymze amount we want, try the max we can
    if(nBalanceNeedsAnonymized > nAnonymizableBalance) nBalanceNeedsAnonymized = nAnonymizableBalance;

    LogPrint("sandstorm", "DoAutomaticDenominating : nLowestDenom=%d, nBalanceNeedsAnonymized=%d\n", nLowestDenom, nBalanceNeedsAnonymized);

    // select coins that should be given to the pool
    if (!pwalletMain->SelectCoinsDark(nValueMin, nBalanceNeedsAnonymized, vCoins, nValueIn, 0, nSandstormRounds))
    {
        nValueIn = 0;
        vCoins.clear();

        if (pwalletMain->SelectCoinsDark(nValueMin, 9999999*COIN, vCoins, nValueIn, -2, 0))
        {
            nOnlyDenominatedBalance = pwalletMain->GetDenominatedBalance(true) + pwalletMain->GetDenominatedBalance() - pwalletMain->GetAnonymizedBalance();
            nBalanceNeedsDenominated = nBalanceNeedsAnonymized - nOnlyDenominatedBalance;

            if(nBalanceNeedsDenominated > nValueIn) nBalanceNeedsDenominated = nValueIn;

            if(nBalanceNeedsDenominated < nLowestDenom) return false; // most likely we just waiting for denoms to confirm
            if(!fDryRun) return CreateDenominated(nBalanceNeedsDenominated);

            return true;
        } else {
            LogPrintf("DoAutomaticDenominating : Can't denominate - no compatible inputs left\n");
            strAutoDenomResult = _("Can't denominate: no compatible inputs left.");
            return false;
        }

    }

    if(fDryRun) return true;

    nOnlyDenominatedBalance = pwalletMain->GetDenominatedBalance(true) + pwalletMain->GetDenominatedBalance() - pwalletMain->GetAnonymizedBalance();
    nBalanceNeedsDenominated = nBalanceNeedsAnonymized - nOnlyDenominatedBalance;

    //check if we have should create more denominated inputs
    if(nBalanceNeedsDenominated > nOnlyDenominatedBalance) return CreateDenominated(nBalanceNeedsDenominated);

    //check if we have the collateral sized inputs
    if(!pwalletMain->HasCollateralInputs()) return !pwalletMain->HasCollateralInputs() && MakeCollateralAmounts();

    std::vector<CTxOut> vOut;

    // initial phase, find a Stormnode
    if(!sessionFoundStormnode){
        // Clean if there is anything left from previous session
        UnlockCoins();
        SetNull();

        int nUseQueue = rand()%100;
        UpdateState(POOL_STATUS_ACCEPTING_ENTRIES);

        if(pwalletMain->GetDenominatedBalance(true) > 0) { //get denominated unconfirmed inputs
            LogPrintf("DoAutomaticDenominating -- Found unconfirmed denominated outputs, will wait till they confirm to continue.\n");
            strAutoDenomResult = _("Found unconfirmed denominated outputs, will wait till they confirm to continue.");
            return false;
        }

        //check our collateral and create new if needed
        std::string strReason;
        CValidationState state;
        if(txCollateral == CMutableTransaction()){
            if(!pwalletMain->CreateCollateralTransaction(txCollateral, strReason)){
                LogPrintf("% -- create collateral error:%s\n", __func__, strReason);
                return false;
            }
        } else {
            if(!IsCollateralValid(txCollateral)) {
                LogPrintf("%s -- invalid collateral, recreating...\n", __func__);
                if(!pwalletMain->CreateCollateralTransaction(txCollateral, strReason)){
                    LogPrintf("%s -- create collateral error: %s\n", __func__, strReason);
                    return false;
                }
            }
        }

        //if we've used 90% of the Stormnode list then drop all the oldest first
        int nThreshold = (int)(snodeman.CountEnabled(MIN_POOL_PEER_PROTO_VERSION) * 0.9);
        LogPrint("sandstorm", "Checking vecStormnodesUsed size %d threshold %d\n", (int)vecStormnodesUsed.size(), nThreshold);
        while((int)vecStormnodesUsed.size() > nThreshold){
            vecStormnodesUsed.erase(vecStormnodesUsed.begin());
            LogPrint("sandstorm", "  vecStormnodesUsed size %d threshold %d\n", (int)vecStormnodesUsed.size(), nThreshold);
        }

        // don't use the queues all of the time for mixing unless we are a liquidity provider
        if(nLiquidityProvider || nUseQueue > 33){

            // Look through the queues and see if anything matches
            BOOST_FOREACH(CSandstormQueue& ssq, vecSandstormQueue){
                CService addr;
                if(ssq.time == 0) continue;

                if(!ssq.GetAddress(addr)) continue;
                if(ssq.IsExpired()) continue;

                int protocolVersion;
                if(!ssq.GetProtocolVersion(protocolVersion)) continue;
                if(protocolVersion < MIN_POOL_PEER_PROTO_VERSION) continue;

                //non-denom's are incompatible
                if((ssq.nDenom & (1 << 4))) continue;

                bool fUsed = false;
                //don't reuse Stormnodes
                BOOST_FOREACH(CTxIn usedVin, vecStormnodesUsed){
                    if(ssq.vin == usedVin) {
                        fUsed = true;
                        break;
                    }
                }
                if(fUsed) continue;

                std::vector<CTxIn> vTempCoins;
                std::vector<COutput> vTempCoins2;
                // Try to match their denominations if possible
                if (!pwalletMain->SelectCoinsByDenominations(ssq.nDenom, nValueMin, nBalanceNeedsAnonymized, vTempCoins, vTempCoins2, nValueIn, 0, nSandstormRounds)){
                    LogPrintf("DoAutomaticDenominating --- Couldn't match denominations %d\n", ssq.nDenom);
                    continue;
                }

                CStormnode* psn = snodeman.Find(ssq.vin);
                if(psn == NULL)
                {
                    LogPrintf("DoAutomaticDenominating --- ssq vin %s is not in stormnode list!", ssq.vin.ToString());
                    continue;
                }

                LogPrintf("DoAutomaticDenominating --- attempt to connect to stormnode from queue %s\n", psn->addr.ToString());
                lastTimeChanged = GetTimeMillis();

                // connect to Stormnode and submit the queue request
                CNode* pnode = ConnectNode((CAddress)addr, NULL, true);
                if(pnode != NULL)
                {
                    pSubmittedToStormnode = psn;
                    vecStormnodesUsed.push_back(ssq.vin);
                    sessionDenom = ssq.nDenom;

                    pnode->PushMessage("ssa", sessionDenom, txCollateral);
                    LogPrintf("DoAutomaticDenominating --- connected (from queue), sending dsa for %d - %s\n", sessionDenom, pnode->addr.ToString());
                    strAutoDenomResult = _("Mixing in progress...");
                    ssq.time = 0; //remove node
                    return true;
                } else {
                    LogPrintf("DoAutomaticDenominating --- error connecting \n");
                    strAutoDenomResult = _("Error connecting to Stormnode.");
                    ssq.time = 0; //remove node
                    continue;
                }
            }
        }

        // do not initiate queue if we are a liquidity proveder to avoid useless inter-mixing
        if(nLiquidityProvider) return false;

        int i = 0;

        // otherwise, try one randomly
        while(i < 10)
        {
            CStormnode* psn = snodeman.FindRandomNotInVec(vecStormnodesUsed, MIN_POOL_PEER_PROTO_VERSION);
            if(psn == NULL)
            {
                LogPrintf("DoAutomaticDenominating --- Can't find random stormnode!\n");
                strAutoDenomResult = _("Can't find random Stormnode.");
                return false;
            }

            if(psn->nLastSsq != 0 &&
                psn->nLastSsq + snodeman.CountEnabled(MIN_POOL_PEER_PROTO_VERSION)/5 > snodeman.nSsqCount){
                i++;
                continue;
            }

            lastTimeChanged = GetTimeMillis();
            LogPrintf("DoAutomaticDenominating --- attempt %d connection to Stormnode %s\n", i, psn->addr.ToString());
            CNode* pnode = ConnectNode((CAddress)psn->addr, NULL, true);
            if(pnode != NULL){
                pSubmittedToStormnode = psn;
                vecStormnodesUsed.push_back(psn->vin);

                std::vector<CAmount> vecAmounts;
                pwalletMain->ConvertList(vCoins, vecAmounts);
                // try to get a single random denom out of vecAmounts
                while(sessionDenom == 0)
                    sessionDenom = GetDenominationsByAmounts(vecAmounts);

                pnode->PushMessage("ssa", sessionDenom, txCollateral);
                LogPrintf("DoAutomaticDenominating --- connected, sending dsa for %d\n", sessionDenom);
                strAutoDenomResult = _("Mixing in progress...");
                return true;
            } else {
                vecStormnodesUsed.push_back(psn->vin); // postpone SN we wasn't able to connect to
                i++;
                continue;
            }
        }

        strAutoDenomResult = _("No compatible Stormnode found.");
        return false;
    }

    strAutoDenomResult = _("Mixing in progress...");
    return false;
}


bool CSandstormPool::PrepareSandstormDenominate()
{
    std::string strError = "";
    // Submit transaction to the pool if we get here
    // Try to use only inputs with the same number of rounds starting from lowest number of rounds possible
    for(int i = 0; i < nSandstormRounds; i++) {
        strError = pwalletMain->PrepareSandstormDenominate(i, i+1);
        LogPrintf("DoAutomaticDenominating : Running Sandstorm denominate for %d rounds. Return '%s'\n", i, strError);
        if(strError == "") return true;
    }

    // We failed? That's strange but let's just make final attempt and try to mix everything
    strError = pwalletMain->PrepareSandstormDenominate(0, nSandstormRounds);
    LogPrintf("DoAutomaticDenominating : Running Sandstorm denominate for all rounds. Return '%s'\n", strError);
    if(strError == "") return true;

    // Should never actually get here but just in case
    strAutoDenomResult = strError;
    LogPrintf("DoAutomaticDenominating : Error running denominate, %s\n", strError);
    return false;
}

// Split up large inputs or create fee sized inputs
bool CSandstormPool::MakeCollateralAmounts()
{
    CWalletTx wtx;
    CAmount nFeeRet = 0;
    std::string strFail = "";
    vector< pair<CScript, CAmount> > vecSend;
    CCoinControl *coinControl = NULL;

    // make our collateral address
    CReserveKey reservekeyCollateral(pwalletMain);
    // make our change address
    CReserveKey reservekeyChange(pwalletMain);

    CScript scriptCollateral;
    CPubKey vchPubKey;
    assert(reservekeyCollateral.GetReservedKey(vchPubKey)); // should never fail, as we just unlocked
    scriptCollateral = GetScriptForDestination(vchPubKey.GetID());

    vecSend.push_back(make_pair(scriptCollateral, SANDSTORM_COLLATERAL*4));

    // try to use non-denominated and not sn-like funds
    //             pwalletMain->CreateTransaction(scriptPubKey, nValue, sNarr, wtxNew, reservekey, nFeeRequired, NULL
    int nChangePos = -1;
    bool success = pwalletMain->CreateTransaction(vecSend, wtx, reservekeyChange, nFeeRet, nChangePos, strFail, coinControl, ALL_COINS, false);
    //TODO (Amir) implement ONLY_NONDENOMINATED_NOTSN in CreateTransaction
    //nFeeRet, strFail, coinControl, ONLY_NONDENOMINATED_NOTSN);
    if(!success){
        // if we failed (most likeky not enough funds), try to use all coins instead -
        // SN-like funds should not be touched in any case and we can't mix denominated without collaterals anyway
        LogPrintf("MakeCollateralAmounts: ONLY_NONDENOMINATED_NOTSN Error - %s\n", strFail);
        //TODO (Amir) implement ONLY_NONDENOMINATED in CreateTransaction
        success = pwalletMain->CreateTransaction(vecSend, wtx, reservekeyChange, nFeeRet, nChangePos, strFail, coinControl, ALL_COINS, false);
                //nFeeRet, strFail, coinControl, ONLY_NONDENOMINATED);
        if(!success){
            LogPrintf("MakeCollateralAmounts: ONLY_NONDENOMINATED Error - %s\n", strFail);
            reservekeyCollateral.ReturnKey();
            return false;
        }
    }

    reservekeyCollateral.KeepKey();

    LogPrintf("MakeCollateralAmounts: tx %s\n", wtx.GetHash().GetHex());

    // use the same cachedLastSuccess as for SS mixinx to prevent race
    if(!pwalletMain->CommitTransaction(wtx, reservekeyChange)) {
        LogPrintf("MakeCollateralAmounts: CommitTransaction failed!\n");
        return false;
    }

    cachedLastSuccess = pindexBest->nHeight;

    return true;
}

// Create denominations
bool CSandstormPool::CreateDenominated(CAmount nTotalValue)
{
    CWalletTx wtx;
    CAmount nFeeRet = 0;
    std::string strFail = "";
    vector< pair<CScript, CAmount> > vecSend;
    CAmount nValueLeft = nTotalValue;

    // make our collateral address
    CReserveKey reservekeyCollateral(pwalletMain);
    // make our change address
    CReserveKey reservekeyChange(pwalletMain);
    // make our denom addresses
    CReserveKey reservekeyDenom(pwalletMain);

    CScript scriptCollateral;
    CPubKey vchPubKey;
    assert(reservekeyCollateral.GetReservedKey(vchPubKey)); // should never fail, as we just unlocked
    scriptCollateral = GetScriptForDestination(vchPubKey.GetID());

    // ****** Add collateral outputs ************ /
    if(!pwalletMain->HasCollateralInputs()) {
        vecSend.push_back(make_pair(scriptCollateral, SANDSTORM_COLLATERAL*4));
        nValueLeft -= SANDSTORM_COLLATERAL*4;
    }

    // ****** Add denoms ************ /
    BOOST_REVERSE_FOREACH(CAmount v, sandStormDenominations){

        // Note: denoms are skipped if there are already DENOMS_COUNT_MAX of them

        // check skipped denoms
        if(IsDenomSkipped(v)) continue;

        // find new denoms to skip if any (ignore the largest one)
        if (v != sandStormDenominations[0] && pwalletMain->CountInputsWithAmount(v) > DENOMS_COUNT_MAX){
            strAutoDenomResult = strprintf(_("Too many %f denominations, removing."), (float)v/COIN);
            LogPrintf("DoAutomaticDenominating : %s\n", strAutoDenomResult);
            sandStormDenominationsSkipped.push_back(v);
            continue;
        }

        int nOutputs = 0;

        // add each output up to 10 times until it can't be added again
        while(nValueLeft - v >= 0 && nOutputs <= 10) {
            CScript scriptDenom;
            CPubKey vchPubKey;
            //use a unique change address
            assert(reservekeyDenom.GetReservedKey(vchPubKey)); // should never fail, as we just unlocked
            scriptDenom = GetScriptForDestination(vchPubKey.GetID());
            // TODO: do not keep reservekeyDenom here
            reservekeyDenom.KeepKey();

            vecSend.push_back(make_pair(scriptDenom, v));

            //increment outputs and subtract denomination amount
            nOutputs++;
            nValueLeft -= v;
            LogPrintf("CreateDenominated1 %d\n", nValueLeft);
        }

        if(nValueLeft == 0) break;
    }
    LogPrintf("CreateDenominated2 %d\n", nValueLeft);

    // if we have anything left over, it will be automatically send back as change - there is no need to send it manually

    CCoinControl *coinControl = NULL;
    //TODO (Amir): CreateTransaction use 7th parameter for sandstorm ONLY_NONDENOMINATED_NOTSN.
    int nChangePos = -1;
    bool success = pwalletMain->CreateTransaction(vecSend, wtx, reservekeyChange, nFeeRet, nChangePos, strFail, coinControl, ALL_COINS, false);
    if(!success){
        LogPrintf("CreateDenominated: Error - %s\n", strFail);
        // TODO: return reservekeyDenom here
        reservekeyCollateral.ReturnKey();
        return false;
    }

    // TODO: keep reservekeyDenom here
    reservekeyCollateral.KeepKey();

    // use the same cachedLastSuccess as for SS mixinx to prevent race
    if(pwalletMain->CommitTransaction(wtx, reservekeyChange))
        cachedLastSuccess = pindexBest->nHeight;
    else
        LogPrintf("CreateDenominated: CommitTransaction failed!\n");

    LogPrintf("CreateDenominated: tx %s\n", wtx.GetHash().GetHex());

    return true;
}

bool CSandstormPool::IsCompatibleWithEntries(std::vector<CTxOut>& vout)
{
    if(GetDenominations(vout) == 0) return false;

    BOOST_FOREACH(const CSandStormEntry v, entries) {
        LogPrintf(" IsCompatibleWithEntries %d %d\n", GetDenominations(vout), GetDenominations(v.vout));

        if(GetDenominations(vout) != GetDenominations(v.vout)) return false;
    }

    return true;
}

bool CSandstormPool::IsCompatibleWithSession(CAmount nDenom, CTransaction txCollateral, int& errorID)
{
    if(nDenom == 0) return false;

    LogPrintf("CSandstormPool::IsCompatibleWithSession - sessionDenom %d sessionUsers %d\n", sessionDenom, sessionUsers);

    if (!unitTest && !IsCollateralValid(txCollateral)){
        LogPrint("sandstorm", "CSandstormPool::IsCompatibleWithSession - collateral not valid!\n");
        errorID = ERR_INVALID_COLLATERAL;
        return false;
    }

    if(sessionUsers < 0) sessionUsers = 0;

    if(sessionUsers == 0) {
        sessionID = 1 + (rand() % 999999);
        sessionDenom = nDenom;
        sessionUsers++;
        lastTimeChanged = GetTimeMillis();

        if(!unitTest){
            //broadcast that I'm accepting entries, only if it's the first entry through
            CSandstormQueue ssq;
            ssq.nDenom = nDenom;
            ssq.vin = activeStormnode.vin;
            ssq.time = GetTime();
            ssq.Sign();
            ssq.Relay();
        }

        UpdateState(POOL_STATUS_QUEUE);
        vecSessionCollateral.push_back(txCollateral);
        return true;
    }

    if((state != POOL_STATUS_ACCEPTING_ENTRIES && state != POOL_STATUS_QUEUE) || sessionUsers >= GetMaxPoolTransactions()){
        if((state != POOL_STATUS_ACCEPTING_ENTRIES && state != POOL_STATUS_QUEUE)) errorID = ERR_MODE;
        if(sessionUsers >= GetMaxPoolTransactions()) errorID = ERR_QUEUE_FULL;
        LogPrintf("CSandstormPool::IsCompatibleWithSession - incompatible mode, return false %d %d\n", state != POOL_STATUS_ACCEPTING_ENTRIES, sessionUsers >= GetMaxPoolTransactions());
        return false;
    }

    if(nDenom != sessionDenom) {
        errorID = ERR_DENOM;
        return false;
    }

    LogPrintf("CSandStormPool::IsCompatibleWithSession - compatible\n");

    sessionUsers++;
    lastTimeChanged = GetTimeMillis();
    vecSessionCollateral.push_back(txCollateral);

    return true;
}

//create a nice string to show the denominations
void CSandstormPool::GetDenominationsToString(int nDenom, std::string& strDenom){
    // Function returns as follows:
    //
    // bit 0 - 100DRK+1 ( bit on if present )
    // bit 1 - 10DRK+1
    // bit 2 - 1DRK+1
    // bit 3 - .1DRK+1
    // bit 3 - non-denom


    strDenom = "";

    if(nDenom & (1 << 0)) {
        if(strDenom.size() > 0) strDenom += "+";
        strDenom += "100";
    }

    if(nDenom & (1 << 1)) {
        if(strDenom.size() > 0) strDenom += "+";
        strDenom += "10";
    }

    if(nDenom & (1 << 2)) {
        if(strDenom.size() > 0) strDenom += "+";
        strDenom += "1";
    }

    if(nDenom & (1 << 3)) {
        if(strDenom.size() > 0) strDenom += "+";
        strDenom += "0.1";
    }
}

int CSandstormPool::GetDenominations(const std::vector<CTxSSOut>& vout){
    std::vector<CTxOut> vout2;

    BOOST_FOREACH(CTxSSOut out, vout)
        vout2.push_back(out);

    return GetDenominations(vout2);
}

// return a bitshifted integer representing the denominations in this list
int CSandstormPool::GetDenominations(const std::vector<CTxOut>& vout, bool fSingleRandomDenom){
    std::vector<pair<CAmount, int> > denomUsed;

    // make a list of denominations, with zero uses
    BOOST_FOREACH(CAmount d, sandStormDenominations)
        denomUsed.push_back(make_pair(d, 0));

    // look for denominations and update uses to 1
    BOOST_FOREACH(CTxOut out, vout){
        bool found = false;
        BOOST_FOREACH (PAIRTYPE(CAmount, int)& s, denomUsed){
            if (out.nValue == s.first){
                s.second = 1;
                found = true;
            }
        }
        if(!found) return 0;
    }

    int denom = 0;
    int c = 0;
    // if the denomination is used, shift the bit on.
    // then move to the next
    BOOST_FOREACH (PAIRTYPE(CAmount, int)& s, denomUsed) {
        int bit = (fSingleRandomDenom ? rand()%2 : 1) * s.second;
        denom |= bit << c++;
        if(fSingleRandomDenom && bit) break; // use just one random denomination
    }

    // Function returns as follows:
    //
    // bit 0 - 100DRK+1 ( bit on if present )
    // bit 1 - 10DRK+1
    // bit 2 - 1DRK+1
    // bit 3 - .1DRK+1

    return denom;
}


int CSandstormPool::GetDenominationsByAmounts(std::vector<CAmount>& vecAmount){
    CScript e = CScript();
    std::vector<CTxOut> vout1;

    // Make outputs by looping through denominations, from small to large
    BOOST_REVERSE_FOREACH(CAmount v, vecAmount){
        CTxOut o(v, e);
        vout1.push_back(o);
    }

    return GetDenominations(vout1, true);
}

int CSandstormPool::GetDenominationsByAmount(CAmount nAmount, int nDenomTarget){
    CScript e = CScript();
    CAmount nValueLeft = nAmount;

    std::vector<CTxOut> vout1;

    // Make outputs by looping through denominations, from small to large
    BOOST_REVERSE_FOREACH(CAmount v, sandStormDenominations){
        if(nDenomTarget != 0){
            bool fAccepted = false;
            if((nDenomTarget & (1 << 0)) &&      v == ((100*COIN)+100000)) {fAccepted = true;}
            else if((nDenomTarget & (1 << 1)) && v == ((10*COIN) +10000)) {fAccepted = true;}
            else if((nDenomTarget & (1 << 2)) && v == ((1*COIN)  +1000)) {fAccepted = true;}
            else if((nDenomTarget & (1 << 3)) && v == ((.1*COIN) +100)) {fAccepted = true;}
            if(!fAccepted) continue;
        }

        int nOutputs = 0;

        // add each output up to 10 times until it can't be added again
        while(nValueLeft - v >= 0 && nOutputs <= 10) {
            CTxOut o(v, e);
            vout1.push_back(o);
            nValueLeft -= v;
            nOutputs++;
        }
        LogPrintf("GetDenominationsByAmount --- %d nOutputs %d\n", v, nOutputs);
    }

    return GetDenominations(vout1);
}

std::string CSandstormPool::GetMessageByID(int messageID) {
    switch (messageID) {
    case ERR_ALREADY_HAVE: return _("Already have that input.");
    case ERR_DENOM: return _("No matching denominations found for mixing.");
    case ERR_ENTRIES_FULL: return _("Entries are full.");
    case ERR_EXISTING_TX: return _("Not compatible with existing transactions.");
    case ERR_FEES: return _("Transaction fees are too high.");
    case ERR_INVALID_COLLATERAL: return _("Collateral not valid.");
    case ERR_INVALID_INPUT: return _("Input is not valid.");
    case ERR_INVALID_SCRIPT: return _("Invalid script detected.");
    case ERR_INVALID_TX: return _("Transaction not valid.");
    case ERR_MAXIMUM: return _("Value more than Sandstorm pool maximum allows.");
    case ERR_SN_LIST: return _("Not in the Stormnode list.");
    case ERR_MODE: return _("Incompatible mode.");
    case ERR_NON_STANDARD_PUBKEY: return _("Non-standard public key detected.");
    case ERR_NOT_A_SN: return _("This is not a Stormnode.");
    case ERR_QUEUE_FULL: return _("Stormnode queue is full.");
    case ERR_RECENT: return _("Last Sandstorm was too recent.");
    case ERR_SESSION: return _("Session not complete!");
    case ERR_MISSING_TX: return _("Missing input transaction information.");
    case ERR_VERSION: return _("Incompatible version.");
    case MSG_SUCCESS: return _("Transaction created successfully.");
    case MSG_ENTRIES_ADDED: return _("Your entries added successfully.");
    case MSG_NOERR:
    default:
        return "";
    }
}

bool CSandStormSigner::IsVinAssociatedWithPubkey(CTxIn& vin, CPubKey& pubkey){
    CScript payee2;
    payee2 = GetScriptForDestination(pubkey.GetID());

    CTransaction txVin;
    uint256 hash;
    if(GetTransaction(vin.prevout.hash, txVin, hash)){
        BOOST_FOREACH(CTxOut out, txVin.vout){
            if(out.nValue == 1000*COIN){
                if(out.scriptPubKey == payee2) return true;
            }
        }
    }

    return false;
}

bool CSandStormSigner::SetKey(std::string strSecret, std::string& errorMessage, CKey& key, CPubKey& pubkey){
    CDarkSilkSecret vchSecret;
    bool fGood = vchSecret.SetString(strSecret);

    if (!fGood) {
        errorMessage = _("Invalid private key.");
        return false;
    }

    key = vchSecret.GetKey();
    pubkey = key.GetPubKey();

    return true;
}

bool CSandStormSigner::SignMessage(std::string strMessage, std::string& errorMessage, vector<unsigned char>& vchSig, CKey key)
{
    CHashWriter ss(SER_GETHASH, 0);
    ss << strMessageMagic;
    ss << strMessage;

    if (!key.SignCompact(ss.GetHash(), vchSig)) {
        errorMessage = _("Signing failed.");
        return false;
    }

    return true;
}

bool CSandStormSigner::VerifyMessage(CPubKey pubkey, vector<unsigned char>& vchSig, std::string strMessage, std::string& errorMessage)
{
    CHashWriter ss(SER_GETHASH, 0);
    ss << strMessageMagic;
    ss << strMessage;

    CPubKey pubkey2;
    if (!pubkey2.RecoverCompact(ss.GetHash(), vchSig)) {
        errorMessage = _("Error recovering public key.");
        return false;
    }

    if (fDebug && pubkey2.GetID() != pubkey.GetID())
        LogPrintf("CSandStormSigner::VerifyMessage -- keys don't match: %s %s\n", pubkey2.GetID().ToString(), pubkey.GetID().ToString());

    return (pubkey2.GetID() == pubkey.GetID());
}

bool CSandstormQueue::Sign()
{
    if(!fStormNode) return false;

    std::string strMessage = vin.ToString() + boost::lexical_cast<std::string>(nDenom) + boost::lexical_cast<std::string>(time) + boost::lexical_cast<std::string>(ready);

    CKey key2;
    CPubKey pubkey2;
    std::string errorMessage = "";

    if(!sandStormSigner.SetKey(strStormNodePrivKey, errorMessage, key2, pubkey2))
    {
        LogPrintf("CSandstormQueue():Relay - ERROR: Invalid Stormnodeprivkey: '%s'\n", errorMessage);
        return false;
    }

    if(!sandStormSigner.SignMessage(strMessage, errorMessage, vchSig, key2)) {
        LogPrintf("CSandstormQueue():Relay - Sign message failed");
        return false;
    }

    if(!sandStormSigner.VerifyMessage(pubkey2, vchSig, strMessage, errorMessage)) {
        LogPrintf("CSandstormQueue():Relay - Verify message failed");
        return false;
    }

    return true;
}

bool CSandstormQueue::Relay()
{

    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        // always relay to everyone
        pnode->PushMessage("ssq", (*this));
    }

    return true;
}

bool CSandstormQueue::CheckSignature()
{
    CStormnode* psn = snodeman.Find(vin);

    if(psn != NULL)
    {
        std::string strMessage = vin.ToString() + boost::lexical_cast<std::string>(nDenom) + boost::lexical_cast<std::string>(time) + boost::lexical_cast<std::string>(ready);

        std::string errorMessage = "";
        if(!sandStormSigner.VerifyMessage(psn->pubkey2, vchSig, strMessage, errorMessage)){
            return error("CSandstormQueue::CheckSignature() - Got bad Stormnode address signature %s \n", vin.ToString().c_str());
        }

        return true;
    }

    return false;
}


void CSandstormPool::RelayFinalTransaction(const int sessionID, const CTransaction& txNew)
{
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes)
    {
        pnode->PushMessage("ssf", sessionID, txNew);
    }
}

void CSandstormPool::RelayIn(const std::vector<CTxSSIn>& vin, const CAmount& nAmount, const CTransaction& txCollateral, const std::vector<CTxSSOut>& vout)
{
    if(!pSubmittedToStormnode) return;

    std::vector<CTxIn> vin2;
    std::vector<CTxOut> vout2;

    BOOST_FOREACH(CTxSSIn in, vin)
        vin2.push_back(in);

    BOOST_FOREACH(CTxSSOut out, vout)
        vout2.push_back(out);

    CNode* pnode = FindNode(pSubmittedToStormnode->addr);
    if(pnode != NULL) {
        LogPrintf("RelayIn - found storm, relaying message - %s \n", pnode->addr.ToString());
        pnode->PushMessage("ssi", vin2, nAmount, txCollateral, vout2);
    }
}

void CSandstormPool::RelayStatus(const int sessionID, const int newState, const int newEntriesCount, const int newAccepted, const int errorID)
{
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes)
        pnode->PushMessage("sssu", sessionID, newState, newEntriesCount, newAccepted, errorID);
}

void CSandstormPool::RelayCompletedTransaction(const int sessionID, const bool error, const int errorID)
{
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes)
        pnode->PushMessage("ssc", sessionID, error, errorID);
}

//TODO: Rename/move to core
void ThreadCheckSandStormPool()
{
    if(fLiteMode) return; //disable all Sandstorm/Stormnode related functionality

    static bool fOneThread;
    if (fOneThread)
        return;
    fOneThread = true;

    // Make this thread recognisable as the Darksend/Masternode thread
    RenameThread("darksilk-sandstorm");

    unsigned int c = 0;

    while (true)
    {
        MilliSleep(1000);
        //LogPrintf("ThreadCheckSandStormPool::check timeout\n");

        // try to sync from all available nodes, one step at a time
        stormnodeSync.Process();

        if(stormnodeSync.IsBlockchainSynced()) {

            c++;

            // check if we should activate or ping every few minutes,
            // start right after sync is considered to be done
            if(c % STORMNODE_PING_SECONDS == 1) activeStormnode.ManageStatus();

            if(c % 60 == 0)
            {
                snodeman.CheckAndRemove();
                snodeman.ProcessStormnodeConnections();
                stormnodePayments.CleanPaymentList();
                CleanTransactionLocksList();
            }

            //if(c % STORMNODES_DUMP_SECONDS == 0) DumpStormnodes();

            sandStormPool.CheckTimeout();
            sandStormPool.CheckForCompleteQueue();

            if(sandStormPool.GetState() == POOL_STATUS_IDLE && c % 15 == 0){
                sandStormPool.DoAutomaticDenominating();
            }
        }
    }
}
