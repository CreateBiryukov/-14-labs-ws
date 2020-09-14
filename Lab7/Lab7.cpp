#include "pch.h"
#include <iostream>

class matrixd
{
protected:
	int rows;
	int columns;
	double *ma;
public:
	matrixd();
	~matrixd();
	virtual void create();
	virtual void input();
	void print();
	int getrows();
	int getcolumns();
	bool summ(matrixd ma2);
	bool mult(matrixd ma2);
	void transp();
	double getelem(int r, int c)
	{
		return ma[r*columns + c];
	}
	void del();
};


matrixd::matrixd()
{
}

matrixd::~matrixd()
{
}

void matrixd::del()
{
	delete ma;
}

void matrixd::create()
{
	int rs;
	int cs;
	std::cout << "Rows = ";
	std::cin >> rs;
	std::cout << "Columns = ";
	std::cin >> cs;
	std::cout << "\n";
	rows = rs;
	columns = cs;
	ma = new double[rows*columns];
}

void matrixd::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			std::cout << "Matr[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> ma[i*columns + j];
		}
	std::cout << "\n";
}

void matrixd::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << ma[i*columns + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}

int matrixd::getrows()
{
	return rows;
}

int matrixd::getcolumns()
{
	return columns;
}

bool matrixd::summ(matrixd ma2)
{
	if (rows < ma2.getrows())
		return false;
	if (columns < ma2.getcolumns())
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma[i*columns + j] += ma2.getelem(i, j);

		}

	}
	return true;
}

bool matrixd::mult(matrixd ma2)
{
	if (columns != ma2.getrows())
	{
		std::cout << "ERROR \n" << std::endl;
		return false;
	}

	double *ma3 = new double[rows*ma2.getcolumns()];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma3[i*columns + j] = ma[i*columns + j];
		}
	}
	int temp = columns;
	columns = ma2.getcolumns();
	for (int j = 0; j < ma2.getcolumns(); j++)
	{
		for (int i = 0; i < rows; i++)
		{
			double x = 0;
			for (int t = 0; t < temp; t++)
			{
				x += ma3[i*temp + t] * ma2.getelem(t, j);
			}
			ma[i*columns + j] = x;
		}
	}
	delete ma3;
	return true;
}

void matrixd::transp()
{
	double * ma3 = new double[rows*columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma3[i*columns + j] = ma[i*columns + j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma[j*rows + i] = ma3[i*columns + j];
		}
	}
	int temp = rows;
	rows = columns;
	columns = temp;
	delete ma3;
	
}


class vectord : public matrixd
{
public:

	vectord();
	double scalmultvector(vectord vec2);
	void xmult(double k);
	virtual void create();
	virtual void input();

	//double summvectord(vectord vec2);
};

void vectord::create()
{
	int rs = 1;
	int cs;
	std::cout << "Rows = 1" << std::endl;
	std::cout << "Columns = ";
	std::cin >> cs;
	columns = cs;
	rows = rs;
	ma = new double[rows*columns];
}

void vectord::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			std::cout << "Vec[" << j + 1 << "] = ";
			std::cin >> ma[i*columns + j];
		}
	std::cout << "\n";
}

/*double vectord::summvectord(vectord vec2)
{
	vectord tmp = *this;
	if (tmp.summ(vec2))
	{
		return tmp.getelem(0, 0);
	}
	tmp = *this;
	tmp.transp();
	if (tmp.summ(vec2))
	{
		return tmp.getelem(0, 0);
	}
	return -1;
}
*/

vectord::vectord()
{
}

double vectord::scalmultvector(vectord vec2)
{
	vectord tmp = *this;
	if (tmp.mult(vec2))
	{
		return tmp.getelem(0, 0);
	}
	tmp = *this;
	tmp.transp();
	if (tmp.mult(vec2))
	{
		return tmp.getelem(0, 0);
	}
	return -1;
}

void vectord::xmult(double k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma[i*columns + j] *= k;
		}
	}
}


int main()
{
	std::cout << "lab7\n" << std::endl;
	matrixd A;
	matrixd B;
	std::cout << "Input A  \n" << std::endl;
	A.create();
	A.input();
	std::cout << "A = \n" << std::endl;
	A.print();
	std::cout << "Input B  \n" << std::endl;
	B.create();
	B.input();
	std::cout << "B = \n" << std::endl;
	B.print();
	A.summ(B);
	std::cout << "A + B = \n" << std::endl;
	A.print();
	A.transp();
	std::cout << "(A + B) TRANSPOSED = \n" << std::endl;
	A.print();
	A.mult(B);
	std::cout << "((A + B) TRANSPOSED) * B = \n" << std::endl;
	A.print();

	vectord C;
	vectord D;
	std::cout << "Input vec(C)  \n" << std::endl;
	C.create();
	C.input();
	std::cout << "vec(C) = \n" << std::endl;
	C.print();
	C.transp();
	C.print();
	std::cout << "Second element=" << C.getelem(0, 1) << "\n";
	std::cout << "Input vec(D)  \n" << std::endl;
	D.create();
	D.input();
	std::cout << "vec(D) = \n" << std::endl;
	D.print();
	C.summ(D);
	std::cout << "vec(C) + vec(D) = \n" << std::endl;
	C.print();
	C.transp();
	std::cout << "(vec(C) + vec(D)) TRANSPOSED = \n" << std::endl;
	C.print();
	C.xmult(7);
	std::cout << "7*(vec(C) + vec(D)) TRANSPOSED = \n" << std::endl;
	C.print();
	double a = C.scalmultvector(D);
	std::cout << "(7*(vec(C) + vec(D)) TRANSPOSED) * vec(D) = " << a << std::endl;
	
	


	A.del();
	B.del();
	C.del();
	D.del();

	system("pause");
	return 0;
}

	/*
	A= 1 2
	   3 4

	A.xmult(2);

	
	
	
	*/

	
