// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "script/sigcache.h"

bool CachingTransactionSignatureChecker::VerifySignature(const std::vector<unsigned char>& vchSig, const CPubKey& pubkey, const uint256& sighash) const
{
    static CSignatureCache signatureCache;

    if (signatureCache.Get(sighash, vchSig, pubkey))
        return true;

    if (!TransactionSignatureChecker::VerifySignature(vchSig, pubkey, sighash))
        return false;

    if (store)
        signatureCache.Set(sighash, vchSig, pubkey);
    return true;
}
