#include "pch.h"
#include <iostream>
//Лабараторная 4. Шифр Цезаря, сортировка пузырьком, шейкерная сортировка (функции)
void ceasars(char* arr, int n)
{
	int key = 1;
	int code;

	for (int iter = 0; iter < n; iter++)
	{
		code = arr[iter] + key;
		if (code > 122)
		{
			code = code - 26;
		}
		arr[iter] = char(code);
	}
}

void bubbleSort(int* arr, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void shakerSort(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		int pn = 0;
		int kn = 9;
		for (int j = pn; j < kn; j++) {
			if (arr[pn] > arr[pn + 1]) {
				int temp = arr[pn];
				arr[pn] = arr[pn + 1];
				arr[pn + 1] = temp;
			}
			pn = pn + 1;
			if (arr[kn - 1] > arr[kn]) {
				int temp = arr[kn - 1];
				arr[kn - 1] = arr[kn];
				arr[kn] = temp;
			}
			kn = kn - 1;
		}
	}
}

void outputArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

void outputCharArray(char* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
}

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
	outputCharArray(chr, length0);
	std::cout << std::endl;
	ceasars(chr, length0);
	std::cout << "Encrypted: ";
	outputCharArray(chr, length0);
	std::cout << std::endl;

	//Задание 3 Сортировка пузырьком
	const int length1 = 10;
	int str[length1] = { 37,84,62,91,11,65,57,28,19,49 };
	std::cout << "Original: ";
	outputArray(str, length1);
	std::cout << std::endl;
	bubbleSort(str, length1);
	std::cout << "Sorted: ";
	outputArray(str, length1);
	std::cout << std::endl;

	//Задание 4 Шейкерная сортировка
	const int length2 = 10;
	int arr2[length2] = { 32,12,43,15,21,9,17,1,19,25 };
	std::cout << "Original: ";
	outputArray(arr2, length2);
	std::cout << std::endl;
	shakerSort(arr2, length2);
	std::cout << "Sorted: ";
	outputArray(arr2, length2);

}
