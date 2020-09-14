#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

class myArray
{
private:
	int n;
	char *mass;

public:
	myArray()
	{
		n = 0;
		mass = new char[n];
	}

	myArray(char array[], int length)
	{
		n = length;
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = array[i];
		}
	}

	myArray(const myArray & m)
	{
		n = m.n;
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = m.mass[i];
		}
	}

	myArray(std::string s)
	{
		n = s.length();
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = s[i];
		}
	}

	~myArray()
	{
		if (mass)
		{
			delete[] mass;
		}
	}
	char* getMass()
	{
		return mass;
	}
	int getN()
	{
		return n;
	}

	void show()
	{
		std::cout << "Number of symbols = " << n << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << mass[i];
		}
		std::cout << "\n";
	}

	void clear()
	{
		n = 0;
		delete[] mass;
		mass = new char[n];
	}

	void add(std::string s)
	{
		std::string myString(mass, n);
		delete[] mass;
		n = n + s.length();
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			if (i < myString.length())
			{
				mass[i] = myString[i];
			}
			else
			{
				mass[i] = s[i - myString.length()];
			}
		}
	}
	void add(char array[], int length)
	{
		std::string myString(mass, n);
		delete[] mass;
		n = n + length;
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			if (i < myString.length())
			{
				mass[i] = myString[i];
			}
			else
			{
				mass[i] = array[i - myString.length()];
			}
		}

	}

	void insert(std::string s, int position)
	{
		std::string myString(mass, n);
		myString.insert(position - 1, s);
		delete[] mass;
		n = n + s.length();
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = myString[i];
		}
	}
	void insert(char array[], int length, int position)
	{
		std::string myString(mass, n);
		std::string s(array, length);
		myString.insert(position - 1, s);
		delete[] mass;
		n = n + length;
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = myString[i];
		}
	}

	void cut(int position, int count)
	{
		std::string myString(mass, n);
		delete[] mass;
		myString.erase(position - 1, count);
		n = n - count;
		mass = new char[n];
		for (int i = 0; i < n; i++)
		{
			mass[i] = myString[i];
		}
	}

	void find(std::string s)
	{
		std::string myString(mass, n);
		int p = myString.find(s);
		if (p == -1)
		{
			std::cout << "Not found!" << std::endl;
		}
		else
		{
			std::cout << "The string starts with symbol " << p + 1 << std::endl;
		}
	}
	void find(char array[], int length)
	{
		std::string myString(mass, n);
		std::string s(array, length);
		int p = myString.find(s);
		if (p == -1)
		{
			std::cout << "Not found!" << std::endl;
		}
		else
		{
			std::cout << "The string starts with symbol " << p + 1 << std::endl;
		}
	}

	void save(std::string fileName)
	{
		std::string myString(mass, n);
		std::ofstream fout(fileName);
		fout << myString << std::endl;
		fout.close();
	}

	void load(std::string fileName)
	{
		std::ifstream fin(fileName);
		if (!fin)
		{
			std::cout << "Failed to open the file" << std::endl;
		}
		else
		{
			std::string s;
			std::getline(fin, s);
			n = s.length();
			delete[] mass;
			mass = new char[n];
			for (int i = 0; i < n; i++)
			{
				mass[i] = s[i];
			}
		}
	}
};


myArray operator + (myArray &obj1, myArray &obj2)
{
	int n = obj1.getN() + obj2.getN();
	char *m = new char[n];
	for (int i = 0; i < n; i++)
	{
		if (i < obj1.getN())
		{
			m[i] = obj1.getMass()[i];
		}
		else
		{
			m[i] = obj2.getMass()[i - obj1.getN()];
		}
	}
	myArray obj(m, n);
	return obj;
}

std::ostream& operator << (std::ostream &s, myArray obj)
{
	std::string str(obj.getMass(), obj.getN());
	s << "Number of symbols = " << obj.getN() << std::endl << "Array (string): " << str << std::endl;
	return s;
}

int main() {

	char array[] = { 's', 'p', 'a', 'm' };
	int count = sizeof(array) / sizeof(char);
	myArray myObject1(array, count);
	myObject1.show();

	myArray m(myObject1);
	m.show();

	std::string str = "spam drum";
	myArray myObject2(str);
	myObject2.show();
	myArray myObject6 = myArray();
	/*for (int i = 0; i < 10000;) {
		
		myObject6.add("spamspamspam");
		myObject6.insert("drum", 4);
		myObject6.clear();
		std::cout << i++ << std::endl;
	}
	*/

	std::cout << "+ operator check:" << std::endl;
	myArray myObject7("spam");
	myArray myObject8("drum");
	(myObject7 + myObject8).show();

	std::cout << "Operataor overload:" << std::endl;
	std::cout << myObject8;

	std::cout << "Find() check:" << std::endl;
	myArray myObject9("spamspamdrumspam");
	myObject9.find("drum");
	myObject9.find("1234");
	myArray myObject10("123456assd789");
	myObject10.find(array, count);

	std::cout << "Save() check:" << std::endl;
	

	std::cout << "Load() check:" << std::endl;
	myObject10.load("load.txt");
	std::cout << myObject10;

	return 0;
}
