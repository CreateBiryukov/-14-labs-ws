//Лабораторная 3. Шифр Цезаря, сортировка пузырьком, шейкерная сортировка
#include "pch.h"
#include <iostream>

int main()
{
	//Задание 1
	std::cout << "int pointer size = " << sizeof(int) << std::endl;
	std::cout << "double pointer size = " << sizeof(double) << std::endl;
	std::cout << "char pointer size = " << sizeof(char *) << std::endl;
	std::cout << "long pointer size = " << sizeof(long *) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;
	//Задание 2 Шифр Цезаря
	const int length0 = 10;
	char chr[length0] = { 'h','e','l','l','o','w','o','r','l','d' };
	std::cout << "Original: ";
	for (int i = 0; i < length0; i++)
	{
		std::cout << chr[i] << ' ';
	}
	std::cout << std::endl;

	int key = 1;
	int code;

	for (int iter = 0; iter < length0; iter++)
	{
		code = chr[iter] + key;
		if (code > 122)
		{
			code = code - 26;
		}
		chr[iter] = char(code);
	}
	std::cout << "Encrypted: ";
	for (int i = 0; i < length0; i++)
	{
		std::cout << chr[i] << ' ';
	}
	std::cout << std::endl;
	//Задание 3 Сортировка пузырьком
	const int length1 = 10;
	int str[length1] = { 37,84,62,91,11,65,57,28,19,49 };
	std::cout << "Original: ";
	for (int i = 0; i < length1; i++)
	{
		std::cout << str[i] << ' ';
	}
	std::cout << std::endl;
	int i, j;
	for (i = 0; i < length1; i++)
	{
		for (j = 0; j < length1 - 1; j++)
		{
			if (str[j] > str[j + 1])
			{
				int temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

	std::cout << "Sorted: ";
	for (int i = 0; i < length1; i++)
	{
		std::cout << str[i] << ' ';
	}
	std::cout << std::endl;
	//Задание 4 Шейкерная сортировка
	const int length2 = 10;
	int arr2[length2] = { 32,12,43,15,21,9,17,1,19,25 };
	std::cout << "Original: ";
	for (int i = 0; i < length2; i++)
	{
		std::cout << arr2[i] << ' ';
	}
	std::cout << std::endl;
	for (int i = 0; i < length2; i++) {
		int pn = 0;
		int kn = 9;
		for (int j = pn; j < kn; j++) {
			if (arr2[pn] > arr2[pn + 1]) {
				int temp = arr2[pn];
				arr2[pn] = arr2[pn + 1];
				arr2[pn + 1] = temp;
			}
			pn = pn + 1;
			if (arr2[kn - 1] > arr2[kn]) {
				int temp = arr2[kn - 1];
				arr2[kn - 1] = arr2[kn];
				arr2[kn] = temp;
			}
			kn = kn - 1;
		}
	}
	std::cout << "Sorted: ";
	for (int i = 0; i < length2; i++)
	{
		std::cout << arr2[i] << ' ';
	}
}
