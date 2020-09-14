//Лабораторная 13 проверка на палиндром
#include "pch.h"
#include<iostream>
#include<deque>
#include<string>

int main()
{
	std::cout << "Palindrome check" << std::endl;
	std::deque <char> palindromic;
	std::string randomstring;
	std::cout << "Input random string: ";
	std::getline(std::cin, randomstring);
	for (int i = 0; i < randomstring.length(); i++)
	{
		palindromic.push_back(randomstring[i]);
	}
	while (palindromic.size() > 0)
	{
		if (palindromic.front() == palindromic.back())
		{
			palindromic.pop_back();
			palindromic.pop_front();
		}
		else
			break;
	}
	if (palindromic.size() == 1)
		palindromic.pop_back();
	if (palindromic.empty() == true)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	system("pause");
	return 0;
}
