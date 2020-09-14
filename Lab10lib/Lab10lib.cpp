#include "pch.h"
#include <iostream>
#include "lab10sldmlib.h"

int matrix::getcolumns() const
{
	return columns;
}

matrix::matrix()
{
}

matrix::matrix(int ro, int co)
{
	rows = ro;
	columns = co;
	data = new double[rows*columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i*columns + j] = 0;
		}
	}
}

matrix::matrix(int st_rows, int st_columns, double * st_data)
{
	rows = st_rows;
	columns = st_columns;
	data = new double[rows*columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i*columns + j] = st_data[i*columns + j];
		}
	}
}

matrix::matrix(const matrix & b)
{
	rows = b.getrows();
	columns = b.getcolumns();
	data = new double[rows*columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i*columns + j] = b.getelem(i, j);
		}
	}
}

bool matrix::sum(const matrix& b)
{
	if (rows != b.getrows())
	{
		std::cout << "ERROR X_X \n" << std::endl;
		return false;
	}
	if (columns != b.getcolumns())
	{
		std::cout << "ERROR X_X \n" << std::endl;
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i*columns + j] += b.getelem(i, j);
		}
	}
	return true;
}

void matrix::tr()
{
	double * ma3 = new double[rows*columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma3[i*columns + j] = data[i*columns + j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[j*rows + i] = ma3[i*columns + j];
		}
	}
	int temp = rows;
	rows = columns;
	columns = temp;
	delete ma3;
}

bool matrix::mul(const matrix& b)
{

	if (columns != b.getrows())
	{
		std::cout << "ERROR X_X \n" << std::endl;
		return false;
	}
	double * ma3 = data;

	data = new double[rows*b.getcolumns()];

	int temp = columns;
	columns = b.getrows();
	for (int j = 0; j < columns; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			double x = 0;
			for (int t = 0; t < temp; t++)
			{
				x += ma3[i*temp + t] * b.getelem(t, j);
			}
			data[i*columns + j] = x;
		}
	}
	delete ma3;
	return true;
}

void matrix::output()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << data[i*columns + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}

matrix::~matrix()
{
	if (data != NULL) {
		delete data;
		data = NULL;
	}
	else
	{
		std::cout << "ERROR matrix already null";
	}
}

void matrix::create()
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
}

void matrix::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			std::cout << "Matrix[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> data[i*columns + j];
		}
	std::cout << "\n";
}

int matrix::getrows() const
{
	return rows;
}

std::ostream & operator<<(std::ostream & os, const matrix & d)
{
	for (int i = 0; i < d.getrows(); i++)
	{
		for (int j = 0; j < d.getcolumns(); j++)
		{
			os << d.getelem(i, j) << "\t";
		}
		os << "\n";
	}
	return os;
}

vector::vector()
{
}

void vector::create()
{
	int rs = 1;
	int cs;
	std::cout << "Rows = 1" << std::endl;
	std::cout << "Columns = ";
	std::cin >> cs;
	columns = cs;
	rows = rs;
}

void vector::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			std::cout << "Vector[" << j + 1 << "] = ";
			std::cin >> data[i*columns + j];
		}
	std::cout << "\n";
}

double vector::smv(const vector& d)
{
	vector tmp(*this);
	if (tmp.mul(d))
	{
		return tmp.getelem(0, 0);
	}
	vector tmp2(*this);
	tmp2.tr();
	if (tmp2.mul(d))
	{
		return tmp2.getelem(0, 0);
	}
	std::cout << "ERROR X_X ";
	return -1;
}

void vector::xmul(int k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i*columns + j] *= k;
		}
	}
}

matrix operator + (const matrix& A, const matrix& B)
{
	matrix res(A);
	res.sum(B);
	return res;
}

matrix operator - (const matrix& A, const matrix& B)
{
	matrix res;
	res.setdim(A.getrows(), A.getcolumns());
	if (A.getrows() != B.getrows())
	{
		std::cout << "ERROR X_X" << std::endl;
		return A;
	}

	if (A.getcolumns() != B.getcolumns())
	{
		std::cout << "ERROR X_X" << std::endl;
		return A;
	}

	for (int i = 0; i < B.getrows(); i++)
	{
		for (int j = 0; j < A.getcolumns(); j++)
			res.setelem(i, j, A.getelem(i, j) - B.getelem(i, j));
	}
	return res;
}

matrix operator * (const matrix& A, const matrix& B)
{
	matrix res(A);
	res.mul(B);
	return res;
}

double operator * (const vector& A, const vector& B)
{
	matrix K(A);
	matrix M(B);
	M.tr();
	if (K.getcolumns() != M.getrows())
	{
		std::cout << "ERROR  ";
		return -1;
	}
	matrix X = K * M;
	return X.getelem(0, 0);
}

vector operator * (const vector& A, int k)
{
	vector res;
	int x = A.getrows();
	int y = A.getcolumns();
	res.setdim(x, y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			double a = A.getelem(i, j);
			res.setelem(i, j, k*a);
		}
	}
	return res;
}

int main()
{
	return 0;
}