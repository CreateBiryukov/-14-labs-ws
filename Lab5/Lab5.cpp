#include "pch.h"
#include <iostream>

//Лабораторная 5. Сортировка пузырьком и шейкерная сортировка. Классы.

void swap(int *arr, int i)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = temp;
}

class sorting
{
public:
	void bubbleSort(int *arr);
	void shakerSort(int *arr);
	sorting();
	const int n = 10;
private:
	int data[10];
public:
	void set_all(int *arr, int size);
	void outputArray();
};

sorting::sorting() {
	for (int i = 0; i < 10; i++) {
		data[i] = 0;
	};
}

void sorting::set_all(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = arr[i];
	}
}

void sorting::outputArray()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void sorting::bubbleSort(int *arr)
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
	std::cout << "Sorted: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void sorting::shakerSort(int *arr)
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
	std::cout << "Sorted: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr1[10] = { 37,84,62,91,11,65,57,28,19,49 };
	int arr2[10] = { 32,12,43,15,21,9,17,1,19,25 };
	std::cout << "1st array is sorted (bubble)" << std::endl;
	sorting array1;
	array1.set_all(arr1, 10);
	std::cout << "Original: ";
	array1.outputArray();
	array1.bubbleSort(arr1);
	std::cout << "2nd array is sorted (shaker)" << std::endl;
	sorting array2;
	array2.set_all(arr2, 10);
	std::cout << "Original: ";
	array2.outputArray();
	array2.shakerSort(arr2);
}
