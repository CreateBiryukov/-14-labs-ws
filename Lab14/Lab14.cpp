//tree
#include "pch.h"
#include <iostream>
#include <cstdlib>

struct node
{
	int info;
	node *l, *r;
};

node *tree = NULL;

void push(int a, node **t)
{
	if ((*t) == NULL)
	{
		(*t) = new node;
		(*t)->info = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}
	if (a > (*t)->info) push(a, &(*t)->r);
	else push(a, &(*t)->l);
}

void print(node *t, int u)
{
	if (t == NULL) return;
	else
	{
		print(t->l, ++u);
		std::cout << "|";
		for (int i = 0; i < u; ++i) std::cout << "-";
		std::cout << t->info << std::endl;
		u--;
	}
	print(t->r, ++u);
}

int main()
{
	int n;
	int s;
	std::cout << "Number of elements =   ";
	std::cin >> n;
	std::cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		s = (rand() % 100);
		push(s, &tree);
	}
	std::cout << "Result: \n";
	print(tree, 0);
	std::cin.ignore().get();
}