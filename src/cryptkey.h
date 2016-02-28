// Copyright (c) 2009-2016 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef DARKSILK_CRYPTKEY_H
#define DARKSILK_CRYPTKEY_H

#include <map>

#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>
#include <openssl/ssl.h>
#include <openssl/ecdh.h> 

#include "key.h"
#include "crypto/common.h"
#include "crypto/hmac_sha512.h"
#include "pubkey.h"
#include "util.h"

#include "cryptogram/ies.h"

class key_error : public std::runtime_error
{
public:
    explicit key_error(const std::string& str) : std::runtime_error(str) {}
};

class CCryptKey
{
	protected:
		EC_KEY* pkey;
	public:
		// Encrypt data
		void EncryptData(const std::vector<unsigned char>& data, std::vector<unsigned char>& encrypted);

		// Decrypt data
		void DecryptData(const std::vector<unsigned char>& encrypted, std::vector<unsigned char>& data);
		
		// Set public key
		bool SetPubKey(const CPubKey& vchPubKey);
}

class CCryptPubKey
{
	public:
		// Encrypt data
		void EncryptData(const std::vector<unsigned char>& data, std::vector<unsigned char>& encrypted);
}

#endif // DARKSILK_KEY_H
