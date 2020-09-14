#include "pch.h"
#include <iostream>

int main()
{
	int a = 310;
	std::cout << "a ^ 4 = " << (a * a * a * a) << std::endl;
	std::cout << "a ^ 5 = " << (a * a * a * a * a) << std::endl;
	std::cout << "5ABC = " << (0x5ABC) << std::endl;
	std::cout << "'b' + 37 = " << ('b' + 37) << std::endl;
	std::cout << "53 + 'b' = " << (53 + 'b') << std::endl;
}
