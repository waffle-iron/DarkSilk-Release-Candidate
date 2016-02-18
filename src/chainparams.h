// Copyright (c) 2009-2016 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Developers
// Copyright (c) 2015-2016 Silk Network
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DARKSILK_CHAIN_PARAMS_H
#define DARKSILK_CHAIN_PARAMS_H

#include "primitives/block.h"
#include "protocol.h"
#include "chainparamsbase.h"
#include "bignum.h"
#include "uint256.h"
#include "amount.h"

#include <vector>

#define MESSAGE_START_SIZE 4
typedef unsigned char MessageStartChars[MESSAGE_START_SIZE];

class CAddress;
//class CBlock;

struct CDNSSeedData {
    std::string name, host;
    CDNSSeedData(const std::string &strName, const std::string &strHost) : name(strName), host(strHost) {}
};

/**
 * CBaseChainParams defines various tweakable parameters of a given instance of the
 * DarkSilk system. There are three: the main network on which people trade goods
 * and services, the public test network which gets reset from time to time and
 * a regression test mode which is intended for private networks only. It has
 * minimal difficulty to ensure that blocks can be found instantly.
 */
class CChainParams
{
public:
    enum Base58Type {
        PUBKEY_ADDRESS,
        SCRIPT_ADDRESS,
        SECRET_KEY,
        EXT_PUBLIC_KEY,
        EXT_SECRET_KEY,

        MAX_BASE58_TYPES
    };

    const uint256& HashGenesisBlock() const { return hashGenesisBlock; }
    const MessageStartChars& MessageStart() const { return pchMessageStart; }
    const std::vector<unsigned char>& AlertKey() const { return vAlertPubKey; }
    int GetDefaultPort() const { return nDefaultPort; }
    const CBigNum& ProofOfWorkLimit() const { return bnProofOfWorkLimit; }
    int SubsidyHalvingInterval() const { return nSubsidyHalvingInterval; }
    const CBlock& GenesisBlock() const { return genesis; }
    virtual bool RequireRPCPassword() const { return true; }
	CBaseChainParams::Network NetworkID() const { return networkID; }
    const std::vector<CDNSSeedData>& DNSSeeds() const { return vSeeds; }
    const std::vector<unsigned char> &Base58Prefix(Base58Type type) const { return base58Prefixes[type]; }
    const std::vector<CAddress>& FixedSeeds() const { return vFixedSeeds; }
    int FirstPOSBlock() const { return nFirstPOSBlock; }
    std::string StormnodePaymentPubKey() const { return strStormnodePaymentsPubKey; }
    int64_t StartStormnodePayments() const { return nStartStormnodePayments; }
    int PoolMaxTransactions() const { return nPoolMaxTransactions; }
    std::string SandstormPoolDummyAddress() const { return strSandstormPoolDummyAddress; }
	int GetPoWTargetSpacing() const { return nPoWTargetSpacing; }
	int GetPoSTargetSpacing() const { return nPoSTargetSpacing; }
	int StormNodePaymentBlock() const { return nSNPaymentBlock; }
	CAmount PoSReward() const {return nStakeReward; }
protected:
    CChainParams() {};

    uint256 hashGenesisBlock;
    MessageStartChars pchMessageStart;
    // Raw pub key bytes for the broadcast alert signing key.
    std::vector<unsigned char> vAlertPubKey;
    int nDefaultPort;
    int nPoWTargetSpacing;
    int nPoSTargetSpacing;
    int nSNPaymentBlock;
    CAmount nStakeReward;
    CBigNum bnProofOfWorkLimit;
    int nSubsidyHalvingInterval;
    std::vector<CDNSSeedData> vSeeds;
    std::vector<unsigned char> base58Prefixes[MAX_BASE58_TYPES];
    std::string strStormnodePaymentsPubKey;
    int64_t nStartStormnodePayments;
    int nFirstPOSBlock;
    int nPoolMaxTransactions;
    std::string strSandstormPoolDummyAddress;
    CBaseChainParams::Network networkID;
    std::string strNetworkID;
    CBlock genesis;
    std::vector<CAddress> vFixedSeeds;
};

/**
 * Return the currently selected parameters. This won't change after app startup
 * outside of the unit tests.
 */
const CChainParams &Params();

/** Return parameters for the given network. */
CChainParams &Params(CBaseChainParams::Network network);

/** Sets the params returned by Params() to those for the given network. */
void SelectParams(CBaseChainParams::Network network);

/**
 * Looks for -regtest or -testnet and then calls SelectParams as appropriate.
 * Returns false if an invalid combination is given.
 */
bool SelectParamsFromCommandLine();

inline bool TestNet(){
    return Params().NetworkID() == CBaseChainParams::TESTNET;
}

#endif // DARKSILK_CHAIN_PARAMS_H
