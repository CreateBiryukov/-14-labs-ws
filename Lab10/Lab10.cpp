#include "pch.h"
#include <iostream>
#include "lab10sldmlib.h"




int main()
{
	matrix A;
	matrix B;
	std::cout << "Input A\n" << std::endl;
	A.create();
	A.input();
	std::cout << "A = \n" << A << std::endl;
	std::cout << "Input B\n" << std::endl;
	B.create();
	B.input();
	std::cout << "B = \n" << B << std::endl;
	A.tr();
	std::cout << "A TRANSPOSED = \n" << A << std::endl;
	std::cout << "A TRANSPOSED + B = \n" << A + B << std::endl;
	A.tr();
	std::cout << "A * B = \n" << A * B << std::endl;

	vector C;
	vector D;
	std::cout << "Input vector C\n" << std::endl;
	C.create();
	C.input();
	std::cout << "Input vector D\n" << std::endl;
	D.create();
	D.input();
	std::cout << "C*5 = \n" << C * 5 << std::endl;
	std::cout << "C+D = \n" << C + D << std::endl;
	std::cout << "C*D = " << C * D << std::endl;

	system("pause");
	return 0;
}