#include "router.h"
#include"router_table.h"
#include<iostream>
#include<fstream>
using namespace std;

void router::delete_()
{
	int number = 0;
	int number2 = 0;
	int* p[9];
	cout << "delete node or side,1 or 2." << flush << endl;
	cin >> number;
	ifstream in("topo.txt", ios::in);
	if (in)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> p[i][j];
			}
		}
	}
	in.close();
	if (number == 1)//node
	{
		cout << "input the number of node you want to delete." << flush << endl;
		cin >> number;
		for (int i = 0; i < 9; i++)
		{
			p[number][i] = 0;
			p[i][number] = 0;
		}
	}
	else if (number == 2)//side
	{
		cout << "input the two nodes of the side" << endl << flush;
		cin >> number >> number2;
		p[number][number2] = 0;
		p[number2][number] = 0;
	}
	this->create(9, p);
}