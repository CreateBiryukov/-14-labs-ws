#include "pch.h"
#include <iostream> 
#include <openssl/conf.h> 
#include <openssl/evp.h> 
#include <openssl/err.h> 
#include <openssl/aes.h>
#include <fstream>


#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

int main()
{
	std::cout << "Encrypting..." << std::endl;
	std::cout << std::endl;

	unsigned char *key = (unsigned char *)"0123456789";
	unsigned char *iv = (unsigned char *)"0123456789012345";
	unsigned char plaintext[256];
	unsigned char cryptedtext[256];
	unsigned char decryptedtext[256];


	EVP_CIPHER_CTX *ctx;

	std::fstream fdef("def.txt", std::ios::binary | std::ios::in);
	std::fstream fenc("enc.txt", std::ios::binary | std::ios::out | std::ios::in | std::ios::trunc);
	std::fstream fdec("dec.txt", std::ios::binary | std::ios::out | std::ios::trunc);



	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	int len = 0;
	fdef.read((char*)plaintext, 256);
	while (fdef.gcount() > 0)
	{
		EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, fdef.gcount());

		fenc.write((char*)cryptedtext, len);

		fdef.read((char*)plaintext, 256);
	}
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	fenc.write((char*)cryptedtext, len);
	fenc.close();
	fdef.close();

	std::cout << "Encrypted!" << std::endl;
	std::cout << std::endl;


	std::cout << "Decrypting..." << std::endl;
	std::cout << std::endl;
	fenc.open("enc.txt", std::ios::in | std::ios::binary);
	if (!(fenc.is_open()))
		return 0;
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0;
	fenc.read((char*)cryptedtext, 256);
	while (fenc.gcount() > 0)

	{

		EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, fenc.gcount());


		fdec.write((char*)decryptedtext, len);


		fenc.read((char*)cryptedtext, 256);
	}


	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);
	fdec.write((char*)decryptedtext, len);
	fdec.close();
	fenc.close();

	std::cout << "Decrypted!" << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}

