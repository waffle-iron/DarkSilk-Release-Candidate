// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef STORMNODE_PAYMENTS_H
#define STORMNODE_PAYMENTS_H

#include "sync.h"
#include "net.h"
#include "key.h"
#include "util.h"
#include "base58.h"
#include "main.h"
#include "stormnode.h"
#include "stormnode-pos.h"
#include "timedata.h"

class CStormnodePayments;
class CStormnodePaymentWinner;

extern CStormnodePayments stormnodePayments;
extern map<uint256, CStormnodePaymentWinner> mapSeenStormnodeVotes;

void ProcessMessageStormnodePayments(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);

// for storing the winning payments
class CStormnodePaymentWinner
{
public:
    int nBlockHeight;
    CTxIn vin;
    CScript payee;
    std::vector<unsigned char> vchSig;
    uint64_t score;

    CStormnodePaymentWinner() {
        nBlockHeight = 0;
        score = 0;
        vin = CTxIn();
        payee = CScript();
    }

    uint256 GetHash(){
        uint256 n2 = Hash(BEGIN(nBlockHeight), END(nBlockHeight));
        uint256 n3 = vin.prevout.hash > n2 ? (vin.prevout.hash - n2) : (n2 - vin.prevout.hash);

        return n3;
    }

    IMPLEMENT_SERIALIZE(
        READWRITE(nBlockHeight);
        READWRITE(payee);
        READWRITE(vin);
        READWRITE(score);
        READWRITE(vchSig);
     )
};

//
// Stormnode Payments Class
// Keeps track of who should get paid for which blocks
//

class CStormnodePayments
{
private:
    std::vector<CStormnodePaymentWinner> vWinning;
    int nSyncedFromPeer;
    std::string strMasterPrivKey;
    std::string strMainPubKey;
    bool enabled;
    int nLastBlockHeight;

public:

    CStormnodePayments() {
        strMainPubKey = "";
        enabled = false;
    }

    bool SetPrivKey(std::string strPrivKey);
    bool CheckSignature(CStormnodePaymentWinner& winner);
    bool Sign(CStormnodePaymentWinner& winner);

    // Deterministically calculate a given "score" for a stormnode depending on how close it's hash is
    // to the blockHeight. The further away they are the better, the furthest will win the election
    // and get paid this block
    //

    uint64_t CalculateScore(uint256 blockHash, CTxIn& vin);
    bool GetWinningStormnode(int nBlockHeight, CTxIn& vinOut);
    bool AddWinningStormnode(CStormnodePaymentWinner& winner);
    bool ProcessBlock(int nBlockHeight);
    void Relay(CStormnodePaymentWinner& winner);
    void Sync(CNode* node);
    void CleanPaymentList();
    int LastPayment(CStormnode& sn);

    //slow
    bool GetBlockPayee(int nBlockHeight, CScript& payee, CTxIn& vin);
};

#endif