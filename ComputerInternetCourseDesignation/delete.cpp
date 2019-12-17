#include "router.h"
#include"router_table.h"
#include<iostream>
#include<fstream>
using namespace std;

int router::delete_(int n)
{
	int number = 0;
	int number2 = 0;
	int* p[20];
	int pt[20][20];
	cout << "delete node or side,1 or 2." << flush << endl;
	cin >> number;
	ifstream in("topo.txt", ios::in);
	if (in)
	{
		in >> n;
		for (int i = 0; i < n; i++)
		{
			p[i] = pt[i];
			for (int j = 0; j < n; j++)
			{
				in >> pt[i][j];
			}
		}
	}
	in.close();
	if (number == 1)//node
	{
		n = n - 1;
		cout << "input the number of node you want to delete." << flush << endl;
		cin >> number;
		for (int j = 0; j < n; j++)
		{
			for (int i = number; i < n - 1; i++)
			{
				p[j][i] = p[j][i + 1];
			}
		}
		for (int i = number; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				p[i][j] = p[i + 1][j];
			}
		}
		//this->create(n, p);
	}
	else if (number == 2)//side
	{
		cout << "input the two nodes of the side" << endl << flush;
		cin >> number >> number2;
		p[number][number2] = 0;
		p[number2][number] = 0;
		//this->create(n, p);
	}
	ofstream out("topo.txt", ios::out);
	if (out)
	{
		out << n << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				out << p[i][j] << ' ';
			}
			out << endl;
		}
	}
	out.close();
	return n;
}