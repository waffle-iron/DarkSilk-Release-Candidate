// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2015 The DarkSilk developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x1f;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x31;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 31000;
        nRPCPort = 31500;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16); //PoW starting difficulty

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        
        const char* pszTimestamp = "2015 DarkSilk is Born";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1438578382, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1438578382; //Change to current UNIX Time of generated genesis
        genesis.nBits    = 504365040; 
        genesis.nNonce   = 1810177;

        hashGenesisBlock = genesis.GetHash(); 

        //// debug print

        /*
        printf("Gensis Hash: %s\n", genesis.GetHash().ToString().c_str());
        printf("Gensis Hash Merkle: %s\n", genesis.hashMerkleRoot.ToString().c_str());
        printf("Gensis nTime: %u\n", genesis.nTime);
        printf("Gensis nBits: %08x\n", genesis.nBits);
        printf("Gensis Nonce: %u\n\n\n", genesis.nNonce);
        */

        assert(hashGenesisBlock == uint256("0xfa5e0f06963f850fe0896359c6ed1495d8414525d9a78e62b483243bf2e0cbc4"));
        assert(genesis.hashMerkleRoot == uint256("0xfb3953d6e08d7ccd5230ee997430e1b3eac702b8f149146a6c2239fd51207934"));
        
        
        base58Prefixes[PUBKEY_ADDRESS] = list_of(30);                     //DarkSilk addresses start with 'D'
        base58Prefixes[SCRIPT_ADDRESS] = list_of(10);                     //DarkSilk script addresses start with '5'
        base58Prefixes[SECRET_KEY] =     list_of(140);                    //DarkSilk private keys start with 'y'              
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x02)(0xFE)(0x52)(0x7D); //DarkSilk BIP32 pubkeys start with 'drks'
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x02)(0xFE)(0x52)(0x8C); //DarkSilk BIP32 prvkeys start with 'drky'

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 42001;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x1f;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x30;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16); //PoW starting difficulty
        vAlertPubKey = ParseHex("");
        nDefaultPort = 31750;
        nRPCPort = 31800;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1438578972;
        genesis.nBits  = 0; 
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash(); 


        //printf("Test Gensis Hash: %s\n", genesis.GetHash().ToString().c_str());
        assert(hashGenesisBlock == uint256("0x5df91956099936ddb98e30a242ae10f1464665d843b30d40ee406a70bc340dc6"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(30);                     //DarkSilk addresses start with 'D'
        base58Prefixes[SCRIPT_ADDRESS] = list_of(10);                     //DarkSilk script addresses start with '5'
        base58Prefixes[SECRET_KEY] =     list_of(140);                    //DarkSilk private keys start with 'y'              
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x02)(0xFE)(0x52)(0x7D); //DarkSilk BIP32 pubkeys start with 'drks'
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x02)(0xFE)(0x52)(0x8C); //DarkSilk BIP32 prvkeys start with 'drky'

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
