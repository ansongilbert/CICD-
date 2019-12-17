#include "router.h"
#include"router_table.h"
#include<iostream>
#include<fstream>

using namespace std;

int router::add(int n)
{
	int* p[20];
	int pt[20][20];
	int number = 0;
	int number2 = 0;
	int length = 0;
	cout << "add node for 1 and side for 2." << flush << endl;
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
	if (number == 2)
	{
		cout << "input the two nodes of the side." << endl << flush;
		cin >> number >> number2;
		cout << "the length" << flush << endl;
		cin >> length;
		p[number][number2] = length;
		p[number2][number] = length;
		//create(n, p);
	}
	else if (number == 1)
	{
		n += 1;
		//int* a[20];
		cout << "input the sides to all the nodes." << flush << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "i " << i << endl;
			cin >> pt[n - 1][i];
		}
		p[n - 1] = pt[n - 1];
		for (int i = 0; i < n; i++)
		{
			p[i][n-1] = p[n-1][i];
		}
		//create(n, p);
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
