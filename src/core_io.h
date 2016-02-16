// Copyright (c) 2009-2016 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DARKSILK_CORE_IO_H
#define DARKSILK_CORE_IO_H

#include <string>
#include <vector>

class CBlock;
class CScript;
class CTransaction;
class uint256;

// core_read.cpp
extern bool DecodeHexBlk(CBlock&, const std::string& strHexBlk);

#endif // DARKSILK_CORE_IO_H