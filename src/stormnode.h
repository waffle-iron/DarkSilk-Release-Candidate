
// Copyright (c) 2009-2015 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Darkcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef STORMNODE_H
#define STORMNODE_H

#include "uint256.h"
#include "uint256.h"
#include "sync.h"
#include "net.h"
#include "key.h"
//#include "primitives/transaction.h"
//#include "primitives/block.h"
#include "util.h"
//#include "script/script.h"
#include "base58.h"
#include "main.h"
#include "timedata.h"
#include "script.h"

class CStormNode;
class CStormnodePayments;
class uint256;

#define STORMNODE_NOT_PROCESSED               0 // initial state
#define STORMNODE_IS_CAPABLE                  1
#define STORMNODE_NOT_CAPABLE                 2
#define STORMNODE_STOPPED                     3
#define STORMNODE_INPUT_TOO_NEW               4
#define STORMNODE_PORT_NOT_OPEN               6
#define STORMNODE_PORT_OPEN                   7
#define STORMNODE_SYNC_IN_PROCESS             8
#define STORMNODE_REMOTELY_ENABLED            9

#define STORMNODE_MIN_CONFIRMATIONS           15
#define STORMNODE_MIN_DSEEP_SECONDS           (30*60)
#define STORMNODE_MIN_DSEE_SECONDS            (5*60)
#define STORMNODE_PING_SECONDS                (1*60)
#define STORMNODE_EXPIRATION_SECONDS          (65*60)
#define STORMNODE_REMOVAL_SECONDS             (70*60)

using namespace std;

class CStormnodePaymentWinner;

extern CCriticalSection cs_stormnodes;
extern std::vector<CStormNode> vecStormnodes;
extern CStormnodePayments stormnodePayments;
extern std::vector<CTxIn> vecStormnodeAskedFor;
extern map<uint256, CStormnodePaymentWinner> mapSeenStormnodeVotes;
extern map<int64_t, uint256> mapCacheBlockHashes;


// manage the stormnode connections
void ProcessStormnodeConnections();
int CountStormnodesAboveProtocol(int protocolVersion);


void ProcessMessageStormnode(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);

//
// The Stormnode Class. For managing the sandstorm process. It contains the input of the 1000DRK, signature to prove
// it's the one who own that ip address and code for calculating the payment election.
//
class CStormNode
{
public:
	static int minProtoVersion;
    CService addr;
    CTxIn vin;
    int64_t lastTimeSeen;
    CPubKey pubkey;
    CPubKey pubkey2;
    std::vector<unsigned char> sig;
    int64_t now; //dsee message times
    int64_t lastDseep;
    int cacheInputAge;
    int cacheInputAgeBlock;
    int enabled;
    bool unitTest;
    bool allowFreeTx;
    int protocolVersion;

    //the dsq count from the last dsq broadcast of this node
    int64_t nLastDsq;

    CStormNode(CService newAddr, CTxIn newVin, CPubKey newPubkey, std::vector<unsigned char> newSig, int64_t newNow, CPubKey newPubkey2, int protocolVersionIn)
    {
        addr = newAddr;
        vin = newVin;
        pubkey = newPubkey;
        pubkey2 = newPubkey2;
        sig = newSig;
        now = newNow;
        enabled = 1;
        lastTimeSeen = 0;
        unitTest = false;
        cacheInputAge = 0;
        cacheInputAgeBlock = 0;
        nLastDsq = 0;
        lastDseep = 0;
        allowFreeTx = true;
        protocolVersion = protocolVersionIn;
    }

    uint256 CalculateScore(int mod=1, int64_t nBlockHeight=0);

    void UpdateLastSeen(int64_t override=0)
    {
        if(override == 0){
            lastTimeSeen = GetAdjustedTime();
        } else {
            lastTimeSeen = override;
        }
    }

    inline uint64_t SliceHash(uint256& hash, int slice)
    {
        uint64_t n = 0;
        memcpy(&n, &hash+slice*64, 64);
        return n;
    }

    void Check();

    bool UpdatedWithin(int seconds)
    {
        // LogPrintf("UpdatedWithin %d, %d --  %d \n", GetAdjustedTime() , lastTimeSeen, (GetAdjustedTime() - lastTimeSeen) < seconds);

        return (GetAdjustedTime() - lastTimeSeen) < seconds;
    }

    void Disable()
    {
        lastTimeSeen = 0;
    }

    bool IsEnabled()
    {
        return enabled == 1;
    }

    int GetStormnodeInputAge()
    {
        if(pindexBest == NULL) return 0;

        if(cacheInputAge == 0){
            cacheInputAge = GetInputAge(vin);
            cacheInputAgeBlock = pindexBest->nHeight;
        }

        return cacheInputAge+(pindexBest->nHeight-cacheInputAgeBlock);
    }
};


// Get the current winner for this block
int GetCurrentStormNode(int mod=1, int64_t nBlockHeight=0, int minProtocol=CStormNode::minProtoVersion);

int GetStormnodeByVin(CTxIn& vin);
int GetStormnodeRank(CTxIn& vin, int64_t nBlockHeight=0, int minProtocol=CStormNode::minProtoVersion);
int GetStormnodeByRank(int findRank, int64_t nBlockHeight=0, int minProtocol=CStormNode::minProtoVersion);


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

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion){
	unsigned int nSerSize = 0;
        READWRITE(nBlockHeight);
        READWRITE(payee);
        READWRITE(vin);
        READWRITE(score);
        READWRITE(vchSig);
     }
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
    std::string strTestPubKey;
    std::string strMainPubKey;
    bool enabled;

public:

    CStormnodePayments() {
        strMainPubKey = "0430a870a5a1e8a85b816c64cb86d6aa4955134efe72c458246fb84cfd5221c111ee84dfc0dbf160d339415044259519eae2840ab3ffe86368f3f9a93ec22e3f4d";
        strTestPubKey = "0430a870a5a1e8a85b816c64cb86d6aa4955134efe72c458246fb84cfd5221c111ee84dfc0dbf160d339415044259519eae2840ab3ffe86368f3f9a93ec22e3f4d";
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
    int LastPayment(CStormNode& sn);

    //slow
    bool GetBlockPayee(int nBlockHeight, CScript& payee);
};



#endif
