// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef STORMNODE_PAYMENTS_H
#define STORMNODE_PAYMENTS_H

#include "key.h"
#include "main.h"
#include "stormnode.h"
#include <boost/lexical_cast.hpp>

class CStormnodePayments;
class CStormnodePaymentWinner;
class CStormnodeBlockPayees;

extern CStormnodePayments stormnodePayments;
extern std::map<uint256, CStormnodePaymentWinner> mapStormnodePayeeVotes;
extern std::map<uint256, CStormnodeBlockPayees> mapStormnodeBlocks;

static const int MIN_SNPAYMENTS_PROTO_VERSION = 60020;
#define MNPAYMENTS_SIGNATURES_REQUIRED           11
#define MNPAYMENTS_SIGNATURES_TOTAL              20

void ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);
bool IsReferenceNode(CTxIn& vin);
bool IsBlockPayeeValid(const CTransaction& txNew, int64_t nBlockHeight);
std::string GetRequiredPaymentsString(int64_t nBlockHeight);

class CStormnodePayee : public CTxOut
{
public:
    int nVotes;

    CStormnodePayee() {
        scriptPubKey = CScript();
        nValue = 0;
        nVotes = 0;
    }

    CStormnodePayee(CAmount nValueIn, CScript payee) {
        scriptPubKey = payee;
        nValue = nValueIn;
        nVotes = 0;
    }
};

// Keep track of votes for payees from stormnodes
class CStormnodeBlockPayees
{
public:
    int nBlockHeight;
    std::vector<CStormnodePayee> vecPayments;

    CStormnodeBlockPayees(){
        nBlockHeight = 0;
        vecPayments.clear();
    }
    CStormnodeBlockPayees(int nBlockHeightIn) {
        nBlockHeight = nBlockHeightIn;
        vecPayments.clear();
    }

    void AddPayee(CScript payeeIn, int64_t nAmount, int nIncrement){
        BOOST_FOREACH(CStormnodePayee& payee, vecPayments){
            if(payee.scriptPubKey == payeeIn && payee.nValue == nAmount) {
                payee.nVotes += nIncrement;
                return;
            }
        }

        CStormnodePayee c((CAmount)nAmount, payeeIn);
        vecPayments.push_back(c);
    }

    bool GetPayee(CScript& payee)
    {
        int nVotes = -1;
        BOOST_FOREACH(CStormnodePayee& p, vecPayments){
            if(p.nVotes > nVotes){
                payee = p.scriptPubKey; 
                nVotes = p.nVotes;
            }
        }        

        return nVotes > -1;
    }

    bool IsTransactionValid(const CTransaction& txNew);
    std::string GetRequiredPaymentsString();

    IMPLEMENT_SERIALIZE(
        READWRITE(nBlockHeight);
        READWRITE(vecPayments);
    )
};

// for storing the winning payments
class CStormnodePaymentWinner
{
public:
    CTxIn vinStormnode;
    int nBlockHeight;
    CTxOut payee;
    std::vector<unsigned char> vchSig;

    CStormnodePaymentWinner() {
        nBlockHeight = 0;
        vinStormnode = CTxIn();
        payee = CTxOut();
    }

    CStormnodePaymentWinner(CTxIn vinIn) {
        nBlockHeight = 0;
        vinStormnode = vinIn;
        payee = CTxOut();
    }

    uint256 GetHash(){
        CHashWriter ss(SER_GETHASH, PROTOCOL_VERSION);
        ss << payee;

        return ss.GetHash(); 
    }

    bool Sign(CKey& keyStormnode, CPubKey& pubKeyStormnode);
    bool IsValid();
    bool SignatureValid();
    void Relay();

    void AddPayee(CScript payeeIn, int64_t nAmount){
        payee.scriptPubKey = payeeIn;
        payee.nValue = nAmount;
    }

    IMPLEMENT_SERIALIZE(
        READWRITE(vinStormnode);
        READWRITE(nBlockHeight);
        READWRITE(payee);
        READWRITE(vchSig);
    )

    std::string ToString()
    {
        std::string ret = "";
        ret += vinStormnode.ToString();
        ret += ", " + boost::lexical_cast<std::string>(nBlockHeight);
        ret += ", " + payee.ToString();
        ret += ", " + boost::lexical_cast<std::string>((int)vchSig.size());
        return ret;
    }
};

//
// Stormnode Payments Class
// Keeps track of who should get paid for which blocks
//

class CStormnodePayments
{
private:
    int nSyncedFromPeer;
    int nLastBlockHeight;

public:

    CStormnodePayments() {
        nSyncedFromPeer = 0;
        nLastBlockHeight = 0;
    }

    bool AddWinningStormnode(CStormnodePaymentWinner& winner);
    bool ProcessBlock(int nBlockHeight);
    void Sync(CNode* node);
    void CleanPaymentList();
    int LastPayment(CStormnode& sn);

    bool GetBlockPayee(int nBlockHeight, CScript& payee);
    bool IsTransactionValid(const CTransaction& txNew, int nBlockHeight);
    bool IsScheduled(CStormnode& sn);

    void ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);
    std::string GetRequiredPaymentsString(int nBlockHeight);
};

#endif