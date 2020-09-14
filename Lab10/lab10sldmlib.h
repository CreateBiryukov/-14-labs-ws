
#include<iostream>
#include<fstream>

class matrix
{
protected:
	int rows;
	int columns;
	double * data;
public:
	matrix();
	virtual ~matrix();
	virtual void create();
	virtual void input();
	int getrows() const;
	int getcolumns() const;
	matrix(int ro, int co);
	matrix(int st_rows, int st_columns, double * st_data);
	matrix(const matrix& b);
	bool sum(const matrix& b);
	void tr();
	bool mul(const matrix& b);
	void output();
	void setelem(int st, int sl, double el)
	{
		data[st*columns + sl] = el;
	}
	void setdim(int st, int sl)
	{
		rows = st;
		columns = sl;
		if (data != NULL)
		{
			delete data;
		}
		data = new double[rows*columns];
	}
	double getelem(int r, int c) const
	{
		return data[r*columns + c];
	}
	friend std::ostream& operator<<(std::ostream& os, const matrix& d);
};
class vector : public matrix
{
public:
	vector();
	virtual void create();
	virtual void input();
	double smv(const vector& d);
	void xmul(int k);
};

	matrix operator + (const matrix& A, const matrix& B);
	matrix operator - (const matrix& A, const matrix& B);
	matrix operator * (const matrix& A, const matrix& B);
	double operator * (const vector& A, const vector& B);
	vector operator * (const vector& A, int k);

