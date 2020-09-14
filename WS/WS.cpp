#include "pch.h"
#include <iostream>
#include <openssl/conf.h> 
#include <openssl/conf.h>
#include <openssl/evp.h> 
#include <openssl/err.h> 
#include <openssl/aes.h>
#include <fstream>
#include <string>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

class DBClass
{
private:
	int row;
	int column;
	std::string Name[9];
	std::string Second_Name[9];
	std::string Passport[9];
public:
	char *key1;
	int load();
	void printAll();
	void print(int index);
	void find(const std::string secondname);
};

void bruteforce(const char * filename, char pass_to_find[5])
{
	for (int i = 0; i < 10000; i++)
	{
		char key[33];
		sprintf_s(key, 33, "%032d", i);

		unsigned char *iv = (unsigned char *)"0123456789012345";
		unsigned char decryptedtext[1024];

		EVP_CIPHER_CTX *ctx;
		int len = 0;
		ctx = EVP_CIPHER_CTX_new();
		EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, iv);
		EVP_CIPHER_CTX_set_padding(ctx, 0);

		EVP_DecryptUpdate(ctx, decryptedtext, &len, (unsigned char*)filename, 256);
		if ((decryptedtext[0] == '{') && (decryptedtext[1] == '\r') && (decryptedtext[2] == '\n'))
		{
			for (int k = 28, s = 0; k < 32; k++, s++)
				pass_to_find[s] = key[k];
			std::cout << "\n";
		}
	}
}


int main()
{
	std::fstream fenc("4_encrypted", std::ios::binary | std::ios::in);
	unsigned char cryptedtext[256];
	fenc.read((char*)cryptedtext, 256);
	char pass[5];
	bruteforce((char*)cryptedtext, pass);
	fenc.close();
	std::cout << "Key ";
	for (int g = 0; g < 4; g++)
	{
		std::cout << pass[g];
	}
	std::cout << "\n" << "\n";


	unsigned char *key = (unsigned char *)"00000000000000000000000000006436";
	unsigned char *iv = (unsigned char *)"0123456789012345";
	unsigned char decryptedtext[1024];

	std::fstream fdec("enc.txt", std::ios::binary | std::ios::out | std::ios::trunc);

	EVP_CIPHER_CTX *ctx;

	ctx = EVP_CIPHER_CTX_new();

	fenc.open("4_encrypted", std::ios::in | std::ios::binary);
	if (!(fenc.is_open()))
		return 0;

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	int len = 0;
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

	DBClass DB;
	DB.load();
	std::cout << "\n" << "DB.printAll()" << "\n";
	DB.printAll();
	std::cout << "\n" << "DB.print(2)" << "\n";
	DB.print(2);
	std::cout << "\n" << "DB.find(\"Hetz\")" << "\n";
	DB.find("Hetz");

	return 0;
}

int DBClass::load()
{
	int p;
	int ccount = 0;
	std::fstream fdec("enc.txt", std::ios::binary | std::ios::in);
	std::string buff;
	for (int j = 0; j < 7; j++)
	{

		std::getline(fdec, buff);
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Second_Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Passport[ccount] = buff;
		std::getline(fdec, buff);
		ccount = ccount + 1;

	}
	for (int o = 0; o < ccount; o++) {
		std::cout << o + 1 << ". " << Name[o] << " " << Second_Name[o] << " " << Passport[o] << "\n";
	}


	return 0;
}

void DBClass::printAll()
{
	std::fstream fdec("enc.txt", std::ios::binary | std::ios::in);
	std::string bufer;
	std::getline(fdec, bufer);
	while (!fdec.eof())
	{
		std::getline(fdec, bufer);
		std::cout << bufer << "\n";
	}
	fdec.close();

}

void DBClass::print(int index)
{
	int p;
	int ccount = 0;
	std::fstream fdec("enc.txt", std::ios::binary | std::ios::in);
	std::string buff;
	for (int j = 0; j < 7; j++)
	{

		std::getline(fdec, buff);
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Second_Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Passport[ccount] = buff;
		std::getline(fdec, buff);
		ccount = ccount + 1;

	}
	for (int o = 0; o < ccount; o++) {
		if (o == index) {
			std::cout << o + 1 << ". " << Name[o] << " " << Second_Name[o] << " " << Passport[o] << "\n";
		}
	}
}

void DBClass::find(const std::string secondname)
{
	int p;
	int ccount = 0;
	std::fstream fdec("enc.txt", std::ios::binary | std::ios::in);
	std::string buff;
	for (int j = 0; j < 7; j++)
	{

		std::getline(fdec, buff);
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Second_Name[ccount] = buff;
		std::getline(fdec, buff);
		p = buff.find('=');
		p = p + 1;
		buff.erase(0, p + 1);
		p = buff.find('\"');
		buff.erase(p, 4);
		Passport[ccount] = buff;
		std::getline(fdec, buff);
		ccount = ccount + 1;

	}
	for (int o = 0; o < ccount; o++) {
		if (secondname == Second_Name[o])
		{
			std::cout << o + 1 << ". " << Name[o] << " " << Second_Name[o] << " " << Passport[o] << "\n";
		}
	}
}