#include "encryption.h"

AESEncryption::AESEncryption(const std::string password) {
	pw = password;
}
bool AESEncryption::encode(std::string text) {
	try
	{
		if (!encrypt)
			encrypt.reset(new CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption);
		encrypt->SetKey(reinterpret_cast<unsigned char*>(&pw[0]), pw.size());
		encrypt->ProcessData(reinterpret_cast<unsigned char*>(&text[0]), reinterpret_cast<unsigned char*>(&text[0]), text.size());
	}
	catch (CryptoPP::Exception& e)
	{
		error = e.what();
		return false;
	}
	return true;
}
bool AESEncryption::decode(std::string encodedMessage) {
	try
	{
		if (!decrypt)
			decrypt.reset(new CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption);
		encrypt->SetKey(reinterpret_cast<unsigned char*>(&pw[0]), pw.size());
		encrypt->ProcessData(reinterpret_cast<unsigned char*>(&encodedMessage[0]), reinterpret_cast<unsigned char*>(&encodedMessage[0]),
			encodedMessage.size());
	}
	catch (CryptoPP::Exception& e)
	{
		error = e.what();
		return false;
	}
	return true;
}

AESEncryption::~AESEncryption() {
}