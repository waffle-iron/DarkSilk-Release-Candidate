// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "stormnode-payments.h"
#include "stormnode-budget.h"
#include "stormnodeman.h"
#include "sandstorm.h"
#include "util.h"
#include "sync.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>

CCriticalSection cs_stormnodepayments;
/** Object for who's going to get paid on which blocks */
CStormnodePayments stormnodePayments;
map<uint256, CStormnodePaymentWinner> mapStormnodePayeeVotes;
map<uint256, CStormnodeBlockPayees> mapStormnodeBlocks;

bool IsBlockPayeeValid(const CTransaction& txNew, int64_t nBlockHeight)
{
    //check if it's a budget block
    if(budget.IsBudgetPaymentBlock(nBlockHeight)){
        if(budget.IsTransactionValid(txNew, nBlockHeight)){
            return true;
        }
    }

    //check for stormnode payee
    if(stormnodePayments.IsTransactionValid(txNew, nBlockHeight))
    {
        return true;
    }

    return false;
}

std::string GetRequiredPaymentsString(int64_t nBlockHeight)
{
    if(budget.IsBudgetPaymentBlock(nBlockHeight)){
        return budget.GetRequiredPaymentsString(nBlockHeight);
    } else {
        return stormnodePayments.GetRequiredPaymentsString(nBlockHeight);
    }
}

void CStormnodePayments::ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{
    if(IsInitialBlockDownload()) return;

    if (strCommand == "snget") {//Stormnode Payments Request Sync
        if(fLiteMode) return; //disable all sandstorm/stormnode related functionality

        if(pfrom->HasFulfilledRequest("snget")) {
            LogPrintf("snget - peer already asked me for the list\n");
            Misbehaving(pfrom->GetId(), 20);
            return;
        }
       

        pfrom->FulfilledRequest("snget");
        stormnodePayments.Sync(pfrom);
        LogPrintf("snget - Sent stormnode winners to %s\n", pfrom->addr.ToString().c_str());
    }
    else if (strCommand == "snw") { //Stormnode Payments Declare Winner

        LOCK(cs_stormnodepayments);

        //this is required in litemodef
        CStormnodePaymentWinner winner;
        vRecv >> winner;

        if(pindexBest == NULL) return;

        if(mapStormnodePayeeVotes.count(winner.GetHash())){
           if(fDebug) LogPrintf("snw - Already seen - %s bestHeight %d\n", winner.GetHash().ToString().c_str(), pindexBest->nHeight);
           return; 
        }

        if(winner.nBlockHeight < pindexBest->nHeight - 10 || winner.nBlockHeight > pindexBest->nHeight+20){
            LogPrintf("snw - winner out of range - Height %d bestHeight %d\n", winner.nBlockHeight, pindexBest->nHeight);
             return;
        }

        if(!winner.IsValid()){
            LogPrintf("snw - invalid message\n");
            return;
        }

        if(!winner.SignatureValid()){
            LogPrintf("snw - invalid signature\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        if(mapStormnodePayeeVotes.count(winner.GetHash())){
           if(fDebug) LogPrintf("snw - Already seen - %s bestHeight %d\n", winner.GetHash().ToString().c_str(), pindexBest->nHeight);
           return; 
        }
 
        if(winner.nBlockHeight < pindexBest->nHeight - 10 || winner.nBlockHeight > pindexBest->nHeight+20){             
            LogPrintf("snw - winner out of range - Height %d bestHeight %d\n", winner.nBlockHeight, pindexBest->nHeight); 
        }

        if(!winner.IsValid()){
            LogPrintf("snw - invalid message\n");
            return;
        }

        if(!winner.SignatureValid()){
            LogPrintf("snw - invalid signature\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        CTxDestination address1;
        ExtractDestination(winner.payee.scriptPubKey, address1);
        CDarkSilkAddress address2(address1);

        if(fDebug) LogPrintf("snw - winning vote - Addr %s Height %d bestHeight %d\n", address2.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);

        if(stormnodePayments.AddWinningStormnode(winner)){
            winner.Relay();
        }
    }
}

bool CStormnodePaymentWinner::Sign(CKey& keyStormnode, CPubKey& pubKeyStormnode)
{
    std::string errorMessage;
    std::string strStormNodeSignMessage;

    std::string strMessage =  vinStormnode.prevout.ToStringShort() +
                boost::lexical_cast<std::string>(nBlockHeight) + 
                payee.ToString();
                
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

bool CStormnodePayments::GetBlockPayee(int nBlockHeight, CScript& payee)
{
    if(mapStormnodeBlocks.count(nBlockHeight)){
        return mapStormnodeBlocks[nBlockHeight].GetPayee(payee);
    }

    return false;
}

bool CStormnodePayments::IsScheduled(CStormnode& sn)
{
    CBlockIndex* pindexPrev = pindexBest;
    if(pindexPrev == NULL) return false;

    CScript snpayee;
    snpayee = GetScriptForDestination(sn.pubkey.GetID());

    CScript payee;
    for(int64_t h = pindexPrev->nHeight; h <= pindexPrev->nHeight+10; h++){
        if(mapStormnodeBlocks.count(h)){
            if(mapStormnodeBlocks[h].GetPayee(payee)){
                if(snpayee == payee || sn.donationAddress == payee) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool CStormnodePayments::AddWinningStormnode(CStormnodePaymentWinner& winnerIn)
{
    uint256 blockHash = 0;
    if(!GetBlockHash(blockHash, winnerIn.nBlockHeight-100)) {
        return false;
    }

    if(mapStormnodePayeeVotes.count(winnerIn.GetHash())){
       return false; 
    }

    mapStormnodePayeeVotes[winnerIn.GetHash()] = winnerIn;

    if(!mapStormnodeBlocks.count(winnerIn.nBlockHeight)){
       CStormnodeBlockPayees blockPayees(winnerIn.nBlockHeight);
       mapStormnodeBlocks[winnerIn.nBlockHeight] = blockPayees;
    }

    int n = 1;
    if(IsReferenceNode(winnerIn.vinStormnode)) n = 100;
    mapStormnodeBlocks[winnerIn.nBlockHeight].AddPayee(winnerIn.payee.scriptPubKey, winnerIn.payee.nValue, n);

    return true;
}

bool CStormnodeBlockPayees::IsTransactionValid(const CTransaction& txNew)
{
    int nMaxSignatures = 0;
    std::string strPayeesPossible = "";

    //require at least 6 signatures

    BOOST_FOREACH(CStormnodePayee& payee, vecPayments)
        if(payee.nVotes >= nMaxSignatures && MNPAYMENTS_SIGNATURES_REQUIRED)
            nMaxSignatures = payee.nVotes;

    // if we don't have at least 6 signatures on a payee, approve whichever is the longest chain
    if(nMaxSignatures == 0) return true;

    BOOST_FOREACH(CStormnodePayee& payee, vecPayments)
    {
        bool found = false;
        BOOST_FOREACH(CTxOut out, txNew.vout)
            if(payee.scriptPubKey == out.scriptPubKey && payee.nValue == out.nValue) 
                found = true;

        //if 2 contenders are within +/- 20%, take either 
        // If nMaxSignatures == 6, the min signatures = 2
        // If nMaxSignatures == 10, the min signatures = 6
        // If nMaxSignatures == 15, the min signatures = 11
        if(payee.nVotes >= nMaxSignatures-(MNPAYMENTS_SIGNATURES_TOTAL/5)){            
            if(found) return true;

            CTxDestination address1;
            ExtractDestination(payee.scriptPubKey, address1);
            CBitcoinAddress address2(address1);

            if(strPayeesPossible == ""){
                strPayeesPossible += address2.ToString()  + ":" + boost::lexical_cast<std::string>(payee.nValue);
            } else {
                strPayeesPossible += "," + address2.ToString() + ":" + boost::lexical_cast<std::string>(payee.nValue);
            }
        }
    }


    LogPrintf("CStormnodePayments::IsTransactionValid - Missing required payment - %s\n", strPayeesPossible.c_str());
    return false;
}

std::string CStormnodeBlockPayees::GetRequiredPaymentsString()
{
    std::string ret = "Unknown";

    BOOST_FOREACH(CStormnodePayee& payee, vecPayments)
    {
        CTxDestination address1;
        ExtractDestination(payee.scriptPubKey, address1);
        CDarkSilkAddress address2(address1);

        if(ret != "Unknown"){
            ret += ", " + address2.ToString() + ":" + boost::lexical_cast<std::string>(payee.nValue) + ":" + boost::lexical_cast<std::string>(payee.nVotes);
        } else {            
            ret = address2.ToString() + ":" + boost::lexical_cast<std::string>(payee.nValue) + ":" + boost::lexical_cast<std::string>(payee.nVotes);
        }
    }
    return ret;
}

std::string CStormnodePayments::GetRequiredPaymentsString(int nBlockHeight)
{
    if(mapStormnodeBlocks.count(nBlockHeight)){
        return mapStormnodeBlocks[nBlockHeight].GetRequiredPaymentsString();
        }
    }

    return "Unknown";
}

bool CStormnodePayments::IsTransactionValid(const CTransaction& txNew, int nBlockHeight)
{
    if(mapStormnodeBlocks.count(nBlockHeight)){
        return mapStormnodeBlocks[nBlockHeight].IsTransactionValid(txNew);
    }

    return true;
}

void CStormnodePayments::CleanPaymentList()
{
    LOCK(cs_stormnodepayments);

    if(pindexBest == NULL) return;

    int nLimit = std::max(((int)snodeman.size())*2, 1000);

    std::map<uint256, CStormnodePaymentWinner>::iterator it = mapStormnodePayeeVotes.begin();
    while(it != mapStormnodePayeeVotes.end()) {
        CStormnodePaymentWinner winner = (*it).second;
   
        if(pindexBest->nHeight - winner.nBlockHeight > nLimit){
            if(fDebug) LogPrintf("CStormnodePayments::CleanPaymentList - Removing old Stormnode payment - block %d\n", winner.nBlockHeight);
            mapStormnodePayeeVotes.erase(it++);
        } else {
            ++it;
        }
    }
}

bool IsReferenceNode(CTxIn& vin)
{
    //reference node - hybrid mode
    if(vin.prevout.ToStringShort() == "099c01bea63abd1692f60806bb646fa1d288e2d049281225f17e499024084e28-0") return true; // mainnet
    if(vin.prevout.ToStringShort() == "testnet-0") return true; // testnet

    return false;
}

bool CStormnodePaymentWinner::IsValid()
{
    if(IsReferenceNode(vinStormnode)) return true;

    int n = snodeman.GetStormnodeRank(vinStormnode, nBlockHeight-100, MIN_SNPAYMENTS_PROTO_VERSION);

    if(n == -1)
    {
        if(fDebug) LogPrintf("CStormnodePaymentWinner::IsValid - Unknown Stormnode\n");
        return false;
    }

    if(n > SNPAYMENTS_SIGNATURES_TOTAL)
    {
        if(fDebug) LogPrintf("CStormnodePaymentWinner::IsValid - Stormnode not in the top %d (%d)\n", SNPAYMENTS_SIGNATURES_TOTAL, n);
        return false;
    }

    return true;
}

bool CStormnodePayments::ProcessBlock(int nBlockHeight)
{
    LOCK(cs_stormnodepayments);


    if(!fStormNode) return false;

    //reference node - hybrid mode

    if(!IsReferenceNode(activeStormnode.vin)){
        int n = snodeman.GetStormnodeRank(activeStormnode.vin, nBlockHeight-100, MIN_SNPAYMENTS_PROTO_VERSION);

        if(n == -1)
        {
            if(fDebug) LogPrintf("CStormnodePayments::ProcessBlock - Unknown Stormnode\n");
            return false;
        }

        if(n > SNPAYMENTS_SIGNATURES_TOTAL)
        {
            if(fDebug) LogPrintf("CStormnodePayments::ProcessBlock - Stormnode not in the top %d (%d)\n", SNPAYMENTS_SIGNATURES_TOTAL, n);
            return false;
        }
    }

    if(nBlockHeight <= nLastBlockHeight) return false;
    
    CBlockIndex* pindexPrev = pindexBest;
    if(pindexPrev == NULL) return false;
    CAmount blockValue = GetBlockValue(pindexPrev->nBits, pindexPrev->nHeight, 0);
    CAmount stormnodePayment = GetStormnodePayment(pindexPrev->nHeight+1, blockValue);

    CStormnodePaymentWinner newWinner(activeStormnode.vin);

    if(budget.IsBudgetPaymentBlock(nBlockHeight)){
        //is budget payment block -- handled by the budgeting software

    } else {
        
        CScript payeeSource;
        uint256 hash;
        if(!GetBlockHash(hash, nBlockHeight-100)) return false;
        unsigned int nHash;
        memcpy(&nHash, &hash, 2);

        LogPrintf(" ProcessBlock Start nHeight %d. \n", nBlockHeight);

        // pay to the oldest SN that still had no payment but its input is old enough and it was active long enough
        CStormnode *psn = snodeman.GetNextStormnodeInQueueForPayment();
        if(psn != NULL)
        {
            LogPrintf(" Found by FindOldestNotInVec \n");

            newWinner.nBlockHeight = nBlockHeight;

            CScript payee;
            if(psn->donationPercentage > 0 && (nHash % 100) <= (unsigned int)psn->donationPercentage) {
                payee = pmn->donationAddress;
            } else {
                payee = GetScriptForDestination(psn->pubkey.GetID());
            }

            payeeSource = GetScriptForDestination(psn->pubkey.GetID());
            newWinner.AddPayee(payee, stormnodePayment);
            
            CTxDestination address1;
            ExtractDestination(payee, address1);
            CDarkSilkAddress address2(address1);

            CTxDestination address3;
            ExtractDestination(payeeSource, address3);
            CDarkSilkAddress address4(address3);

            LogPrintf("Winner payee %s nHeight %d vin source %s. \n", address2.ToString().c_str(), newWinner.nBlockHeight, address4.ToString().c_str());
        } else {
            LogPrintf(" Failed to find Stormnode to pay\n");
        }

    }

    std::string errorMessage;
    CPubKey pubKeyStormnode;
    CKey keyStormnode;

    if(!sandStormSigner.SetKey(strStormNodePrivKey, errorMessage, keyStormnode, pubKeyStormnode))
    {
        LogPrintf("CStormnodePayments::ProcessBlock() - Error upon calling SetKey: %s\n", errorMessage.c_str());
        return false;
    }

    if(newWinner.Sign(keyStormnode, pubKeyStormnode))
    {
        if(AddWinningStormnode(newWinner))
        {
            newWinner.Relay();
            nLastBlockHeight = nBlockHeight;
            return true;
        }
    }

    return false;
}

void CStormnodePaymentWinner::Relay()
{
    CInv inv(MSG_STORMNODE_WINNER, GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }
}

bool CStormnodePaymentWinner::SignatureValid()
{
    CStormnode* psn = snodeman.Find(vinStormnode);


    if(psn != NULL)
    {
        std::string strMessage =  vinStormnode.prevout.ToStringShort() +
                    boost::lexical_cast<std::string>(nBlockHeight) + 
                    payee.ToString();

        std::string errorMessage = "";
        if(!sandStormSigner.VerifyMessage(psn->pubkey2, vchSig, strMessage, errorMessage)){
            return error("CStormnodePaymentWinner::SignatureValid() - Got bad Stormnode address signature %s \n", vinStormnode.ToString().c_str());
        }

        return true;
    }
    return false;
}

void CStormnodePayments::Sync(CNode* node)
{
    LOCK(cs_stormnodepayments);

    if(pindexBest == NULL) return;

    std::map<uint256, CStormnodePaymentWinner>::iterator it = mapStormnodePayeeVotes.begin();
    while(it != mapStormnodePayeeVotes.end()) {
        CStormnodePaymentWinner winner = (*it).second;
        if(winner.nBlockHeight >= pindexBest->nHeight-10 && winner.nBlockHeight <= pindexBest->nHeight + 20)
            node->PushMessage("snw", winner);
        ++it;
    }
}