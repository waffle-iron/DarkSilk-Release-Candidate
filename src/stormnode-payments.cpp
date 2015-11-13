// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "stormnode-payments.h"
#include "stormnodeman.h"
#include "sandstorm.h"
#include "util.h"
#include "sync.h"
#include "addrman.h"
#include <boost/lexical_cast.hpp>

CCriticalSection cs_stormnodepayments;
/** Object for who's going to get paid on which blocks */
CStormnodePayments stormnodePayments;
// keep track of stormnode votes I've seen
map<uint256, CStormnodePaymentWinner> mapSeenStormnodeVotes;

void ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
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

        //this is required in litemode
        CStormnodePaymentWinner winner;
        vRecv >> winner;

        if(pindexBest == NULL) return;

        CTxDestination address1;
        ExtractDestination(winner.payee, address1);
        CDarkSilkAddress address2(address1);

        uint256 hash = winner.GetHash();
        if(mapSeenStormnodeVotes.count(hash)) {
            if(fDebug) LogPrintf("snw - seen vote %s Addr %s Height %d bestHeight %d\n", hash.ToString().c_str(), address2.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);
            return;
        }

        if(winner.nBlockHeight < pindexBest->nHeight - 10 || winner.nBlockHeight > pindexBest->nHeight+20){
            LogPrintf("snw - winner out of range %s Addr %s Height %d bestHeight %d\n", winner.vin.ToString().c_str(), address2.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);
            return;
        }

        if(winner.vin.nSequence != std::numeric_limits<unsigned int>::max()){
            LogPrintf("snw - invalid nSequence\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        LogPrintf("snw - winning vote - Vin %s Addr %s Height %d bestHeight %d\n", winner.vin.ToString().c_str(), address2.ToString().c_str(), winner.nBlockHeight, pindexBest->nHeight);
 
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

bool CStormnodePayments::GetBlockPayee(int nBlockHeight, CScript& payee, CTxIn& vin)
{
    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning){
        if(winner.nBlockHeight == nBlockHeight) {
            payee = winner.payee;
            vin = winner.vin;
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

                mapSeenStormnodeVotes.insert(make_pair(winnerIn.GetHash(), winnerIn));

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
    LOCK(cs_stormnodepayments);

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
    LOCK(cs_stormnodepayments);

    if(nBlockHeight <= nLastBlockHeight) return false;
    if(!enabled) return false;
    CStormnodePaymentWinner newWinner;
    int nMinimumAge = snodeman.CountEnabled();
    CScript payeeSource;

    uint256 hash;
    if(!GetBlockHash(hash, nBlockHeight-10)) return false;
    unsigned int nHash;
    memcpy(&hash, &nHash, 2);

    LogPrintf(" ProcessBlock Start nHeight %d. \n", nBlockHeight);

    std::vector<CTxIn> vecLastPayments;
    BOOST_REVERSE_FOREACH(CStormnodePaymentWinner& winner, vWinning)
    {
        //if we already have the same vin - we have one full payment cycle, break
        if(vecLastPayments.size() > (unsigned int)nMinimumAge) break;
        vecLastPayments.push_back(winner.vin);
    }

    // pay to the oldest SN that still had no payment but its input is old enough and it was active long enough
    CStormnode *psn = snodeman.FindOldestNotInVec(vecLastPayments, nMinimumAge);
    if(psn != NULL)
    {
        LogPrintf(" Found by FindOldestNotInVec \n");

        newWinner.score = 0;
        newWinner.nBlockHeight = nBlockHeight;
        newWinner.vin = psn->vin;
        psn->nLastPaid = GetAdjustedTime();

        if(psn->donationPercentage > 0 && (nHash % 100) <= (unsigned int)psn->donationPercentage) {
            newWinner.payee = psn->donationAddress;
        } else {
            newWinner.payee.SetDestination(psn->pubkey.GetID());
        }

        payeeSource.SetDestination(psn->pubkey.GetID());
    }

    //if we can't find new SN to get paid, pick the first active SN counting back from the end of vecLastPayments list
    if(newWinner.nBlockHeight == 0 && nMinimumAge > 0)
    {   
        LogPrintf(" Find by reverse \n");

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
                psn->nLastPaid = GetAdjustedTime();
                
                if(psn->donationPercentage > 0 && (nHash % 100) <= (unsigned int)psn->donationPercentage) {
                    newWinner.payee = psn->donationAddress;
                } else {
                    newWinner.payee.SetDestination(psn->pubkey.GetID());
                }

                payeeSource.SetDestination(psn->pubkey.GetID());

                break; // we found active SN
            }
        }
    }

    if(newWinner.nBlockHeight == 0) return false;

    CTxDestination address1;
    ExtractDestination(newWinner.payee, address1);
    CDarkSilkAddress address2(address1);

    CTxDestination address3;
    ExtractDestination(payeeSource, address3);
    CDarkSilkAddress address4(address3);

    LogPrintf("Winner payee %s nHeight %d vin source %s. \n", address2.ToString().c_str(), newWinner.nBlockHeight, address4.ToString().c_str());
 
    if(Sign(newWinner))
    {
        if(AddWinningStormnode(newWinner))
        {
            Relay(newWinner);
            nLastBlockHeight = nBlockHeight;
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
    LOCK(cs_stormnodepayments);

    BOOST_FOREACH(CStormnodePaymentWinner& winner, vWinning)
        if(winner.nBlockHeight >= pindexBest->nHeight-10 && winner.nBlockHeight <= pindexBest->nHeight + 20)
            node->PushMessage("snw", winner);
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