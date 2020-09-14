//Лабораторная 6. Матрицы. Векторы.
#include "pch.h"
#include <iostream>

class matrix
{
protected:
	double matrx[10][10];
	int rows;
	int	columns;
public:
	matrix();
	~matrix();
	bool add(matrix matrx2);
	bool transpose();
	bool multiply(matrix matrx2);
	virtual bool input();
	void print();
	void xmult(double k);


	int getrows()
	{
		return rows;
	}

	int getcolumns()
	{
		return columns;
	}

	double getelem(int r, int c)
	{
		if (r < rows && c<columns && c>-1)
			return matrx[r][c];
		std::cout << "Couldn't get element\n";
		return -1;
	}
};

matrix::matrix()
{

}
matrix::~matrix()
{

}

void matrix::xmult(double k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrx[i][j] *= k;
		}
	}
}

bool matrix::add(matrix matrx2)
{
	if (rows != matrx2.getrows())
		return false;
	if (columns != matrx2.getcolumns())
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			matrx[i][j] += matrx2.getelem(i, j);
	}
	return true;
}
bool matrix::input()
{
	int rs;
	int cs;
	std::cout << "Rows = ";
	std::cin >> rs;
	if (rs < 0)
		return false;
	if (rs > 10)
		return false;
	std::cout << "Columns = ";
	std::cin >> cs;
	std::cout << "\n";
	if (cs < 0)
		return false;
	if (cs > 10)
		return false;
	for (int i = 0; i < rs; i++)
		for (int j = 0; j < cs; j++)
			std::cin >> matrx[i][j];
	columns = cs;
	rows = rs;
	std::cout << "\n";
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << matrx[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "\n";
}

bool matrix::transpose()
{
	double matrx3[10][10];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrx3[i][j] = matrx[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrx[j][i] = matrx3[i][j];
		}
	}
	int temp = rows;
	rows = columns;
	columns = temp;

	return true;
}

bool matrix::multiply(matrix matrx2)
{

	if (columns != matrx2.getrows())
	{
		return false;
	}

	double matrx3[10][10];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrx3[i][j] = matrx[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < matrx2.getcolumns(); j++)
		{
			double x = 0.0;
			for (int t = 0; t < columns; t++)
			{
				x += matrx3[i][t] * matrx2.getelem(t, j);
			}
			matrx[i][j] = x;

		}
	}
	columns = matrx2.getcolumns();
	return true;
}


class vector : public matrix
{
public:

	vector();
	double scalarMultiplication(vector vec2);
	virtual bool input();

};

bool vector::input()
{
	int rs;
	int cs = 1;
	std::cout << "Rows = ";
	std::cin >> rs;
	if (rs < 0)
		return false;
	if (rs > 10)
		return false;
	std::cout << "Columns = 1";
	std::cout << "\n";
	for (int i = 0; i < rs; i++)
		for (int j = 0; j < cs; j++)
			std::cin >> matrx[i][j];
	std::cout << "\n";
	columns = cs;
	rows = rs;
	std::cout << "\n";
	return true;
}

vector::vector()
{
}

double vector::scalarMultiplication(vector vec2)
{
	vector tmp = *this;
	if (tmp.multiply(vec2))
	{
		return tmp.getelem(0, 0);
	}
	tmp = *this;
	tmp.transpose();
	if (tmp.multiply(vec2))
	{
		return tmp.getelem(0, 0);
	}
	return -1;
}

int main()
{
	matrix matrixA;
	std::cout << "Matrix A:" << std::endl;
	matrixA.input();
	matrixA.print();
	matrixA.transpose();
	matrixA.print();
	matrix matrixB;
	std::cout << "Matrix B:" << std::endl;
	matrixB.input();
	matrixB.print();
	matrixA.transpose();
	matrixA.add(matrixB);
	matrixA.print();
	matrixB.transpose();
	matrixA.multiply(matrixB);
	matrixA.print();
	vector vectorA;
	vector vectorB;
	std::cout << "Vector A:" << std::endl;
	vectorA.input();
	vectorA.print();
	std::cout << "Vector B:" << std::endl;
	vectorB.input();
	vectorB.print();
	double scal = vectorA.scalarMultiplication(vectorB);
	std::cout << "Scalar multiplication = " << scal << std::endl;
	scal = vectorA.scalarMultiplication(vectorB);
	std::cout << scal << "\n";
	vectorA.xmult(5);
	vectorA.print();
}
