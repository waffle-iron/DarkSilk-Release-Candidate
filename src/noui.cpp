// Copyright (c) 2009-2016 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Developers
// Copyright (c) 2015-2016 Silk Network
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <string>

#include "ui_interface.h"
#include "init.h"

static int noui_ThreadSafeMessageBox(const std::string& message, const std::string& caption, unsigned int style)
{
    std::string strCaption;
    // Check for usage of predefined caption
    switch (style) {
    case CClientUIInterface::MSG_ERROR:
        strCaption += _("Error");
        break;
    case CClientUIInterface::MSG_WARNING:
        strCaption += _("Warning");
        break;
    case CClientUIInterface::MSG_INFORMATION:
        strCaption += _("Information");
        break;
    default:
        strCaption += caption; // Use supplied caption
    }

    LogPrintf("%s: %s\n", caption, message);
    fprintf(stderr, "%s: %s\n", strCaption.c_str(), message.c_str());
    return 4;
}

static bool noui_ThreadSafeAskFee(CAmount nFeeRequired, const std::string& strCaption)
{
    return true;
}

static void noui_InitMessage(const std::string &message)
{
    LogPrintf("init message: %s\n", message);
}

void noui_connect()
{
    // Connect darksilkd signal handlers
    uiInterface.ThreadSafeMessageBox.connect(noui_ThreadSafeMessageBox);
    uiInterface.ThreadSafeAskFee.connect(noui_ThreadSafeAskFee);
    uiInterface.InitMessage.connect(noui_InitMessage);
}
