
// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef STORMNODEMAN_H
#define STORMNODEMAN_H

#include "bignum.h"
#include "sync.h"
#include "net.h"
#include "key.h"
#include "core.h"
#include "util.h"
#include "script.h"
#include "base58.h"
#include "main.h"
#include "stormnode.h"

#define STORMNODES_DUMP_SECONDS               (15*60)
#define STORMNODES_DSEG_SECONDS              (3*60*60)

using namespace std;

class CStormnodeMan;

extern CStormnodeMan snodeman;

void DumpStormnodes();

/** Access to the SN database (stormnodes.dat) */
class CStormnodeDB
{
private:
    boost::filesystem::path pathSN;
public:
    CStormnodeDB();
    bool Write(const CStormnodeMan &snodemanToSave);
    bool Read(CStormnodeMan& snodemanToLoad);
};

class CStormnodeMan
{
private:
    // critical section to protect the inner data structures
    mutable CCriticalSection cs;

    // map to hold all SNs
    std::vector<CStormnode> vStormnodes;
    // who's asked for the stormnode list and the last time
    std::map<CNetAddr, int64_t> mWeAskedUsForStormnodeList;
    // who we asked for the stormnode list and the last time
    std::map<CNetAddr, int64_t> mWeAskedForStormnodeList;
    // which stormnodes we've asked for
    std::map<COutPoint, int64_t> mWeAskedForStormnodeListEntry;

public:

    IMPLEMENT_SERIALIZE
    (
        // serialized format:
        // * version byte (currently 0)
        // * stormnodes vector
        {
                LOCK(cs);
                unsigned char nVersion = 0;
                READWRITE(nVersion);
                READWRITE(vStormnodes);
                READWRITE(mWeAskedUsForStormnodeList);
                READWRITE(mWeAskedForStormnodeList);
                READWRITE(mWeAskedForStormnodeListEntry);
        }
    )

    CStormnodeMan();
    CStormnodeMan(CStormnodeMan& other);

    // Find an entry
    CStormnode* Find(const CTxIn& vin);

    // Find a random entry
    CStormnode* FindRandom();

    //Find an entry thta do not match every entry provided vector
    CStormnode* FindOldestNotInVec(const std::vector<CTxIn> &vVins);

    // Add an entry
    bool Add(CStormnode &sn);

    // Check all stormnodes
    void Check();

    // Check all stormnodes and remove inactive
    void CheckAndRemove();

    // Clear stormnode vector
    void Clear();

    // Return the number of (unique) stormnodes
    int size() { return vStormnodes.size(); }

    std::string ToString();

    // Get the current winner for this block
    CStormnode* GetCurrentStormNode(int mod=1, int64_t nBlockHeight=0, int minProtocol=0);

    int GetStormnodeRank(const CTxIn &vin, int64_t nBlockHeight, int minProtocol=0);

    int CountStormnodesAboveProtocol(int protocolVersion);

    int CountEnabled();

    void DsegUpdate(CNode* pnode);

    std::vector<CStormnode> GetFullStormnodeVector() { Check(); return vStormnodes; }

    void ProcessMessage(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);

};

#endif
