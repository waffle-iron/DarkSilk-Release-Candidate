// Copyright (c) 2014-2016 The Bitcoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "crypto/blake256.h"
#include "crypto/common.h"

////// CBLAKE2B256-256

CBLAKE2B256::CBLAKE2B256() : bytes(0)
{
    blake2b_init(S, OUTPUT_SIZE);
}

CBLAKE2B256& CBLAKE2B256::Write(const unsigned char* data, size_t len)
{
    bytes = len;
    blake2b_update(S, ((unsigned char*)&data[0]), bytes);
    return *this;
}

void CBLAKE2B256::Finalize(unsigned char hash[OUTPUT_SIZE])
{
    blake2b_final(S, (unsigned char*)&hash, OUTPUT_SIZE);
}

CBLAKE2B256& CBLAKE2B256::Reset()
{
    bytes = 0;
    blake2b_init(S, OUTPUT_SIZE);
    return *this;
}

