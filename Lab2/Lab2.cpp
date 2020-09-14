//Escape последовательности
#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "\\' " << " - single quote" << "\n";
	std::cout << "\\t" << " - double quote" << "\n";
	std::cout << "\\? " << " - question mark" << "\n";
	std::cout << "\\" << " - backslash" << "\n";
	std::cout << "\\n" << " - new line" << "\n";
	std::cout << "\\f " << " - new page" << "\n";
	std::cout << "\b " << "- backspace" << "\n";
	std::cout << "\r" << " - carriage return" << "\n";
}