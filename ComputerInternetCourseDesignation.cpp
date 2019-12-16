// ComputerInternetCourseDesignation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include"router_table.h"
#include"router.h"
using namespace std;


int main()
{
	/*int table[9][9];
	ifstream in("topo.txt", ios::in);
	if(in)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> table[i][j];
			}
		}
	}
	in.close(); */
	int** table=read("topo.txt");
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout<< table[i][j]<<' ';
		}
		cout << endl;
	}*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}
	//int* p[9]; 
	//for(int i=0;i<9;i++)
	//p[i]= table[i];
	router* h = new router;
	//dijskstra is done, create()is done
	h->number = 6;
	h->create(9, table);
}

int** read(const char* a)
{
	int *table[9];
	ifstream in(a, ios::in);
	if (in)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				in >> table[i][j];
			}
		}
	}
	in.close();
	return table;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
