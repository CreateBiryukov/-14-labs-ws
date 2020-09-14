#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <bitset>


int main()
{
	printf("lab9\n");
	/*
		Работа на паре:
	char cstr1[] = "C-style string 1";
	char cstr2[] = "C-style string 2";
	char cstr3[255];
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
	strcpy_s(cstr3, 255, cstr2);
	printf_s("Result of strcpy(%s, %s)\n", cstr3, cstr2);
	strcat_s(cstr3, 255, cstr1);
	std::cout << "Result of strcat(cstr2, cstr1) = " << cstr3 << std::endl;
	printf("Par1 = %f, Par2 = %d\n", 1.5, 100);
	printf("Insert double: %f,\n"
		"Insert long long: %d,\n"
		"Insert string: %s,\n"
		"Insert exponential: %e,\n"
		"Insert double with precision: %10.2f,\n"
		"Insert double as int: %10.2f,\n",
		1000.15,
		2000,
		"string :3",
		1123456.1123456,
		20.189,
		20.19);
	*/
	int q = 0;
	std::ofstream fout;
	fout.open("lab8.txt");
	std::string str1;
	std::string str2;
	std::cout << "Input str1: ";
	getline(std::cin, str1);
	std::cout << std::endl;
	std::cout << "Input str2: ";
	getline(std::cin, str2);
	std::cout << std::endl;
	fout << str1 << "\n" << str2 << "\n";

	int m = str1.length();
	int n = str2.length();
	int s = m - n + 1;
	int * a = new int[m];
	for (int i = 0; i < m; i++)
		a[i] = 0;
	for (int i = 0; i < s; i++)
	{
		int k = 0;
		for (int j = 0; j < n; j++)
		{
			if (str1[i + j] == str2[j])
				k++;
		}
		if (k == n)
			a[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		if (a[i] == 0)
			q++;
	}

	for (int i = 0; i < m; i++)
	{
		if (a[i] != 0)
		{
			std::cout << a[i] + 1 << "\t";
			fout << a[i] + 1 << "\t";
		}
	}
	std::cout << "\n" << std::endl;

	if (q == m)
	{
		std::cout << "nothing" << std::endl;
		fout << "nothing\n\n";
	}


	delete a;
	fout.close();
	system("pause");
	return 0;
}