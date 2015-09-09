// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2015 The DarkSilk developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef DARKSILK_INIT_H
#define DARKSILK_INIT_H

#include "wallet.h"

namespace boost {
    class thread_group;
} // namespace boost

extern CWallet* pwalletMain;
void StartShutdown();
bool ShutdownRequested();
void Shutdown();
bool AppInit2(boost::thread_group& threadGroup);
std::string HelpMessage();
extern bool fOnlyTor;

#endif
