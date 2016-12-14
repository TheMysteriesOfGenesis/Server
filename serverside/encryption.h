#pragma once

#include <string>
#include <cstdio>
#include "Crypto\aes.h"
#include "Crypto\MD5.h"
#include "Crypto\modes.h"

class AESEncryption
{
	std::string pw;
	std::string error;
	std::unique_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption> encrypt;
	std::unique_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption> decrypt;

public:
	AESEncryption(const std::string password);
	bool encode(std::string text);
	bool decode(std::string cipher);
	std::string getError() { return error; }
	~AESEncryption();
};

