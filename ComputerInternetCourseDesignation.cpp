// ComputerInternetCourseDesignation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include"router_table.h"
#include"router.h"
using namespace std;

int main()
{
	int num = 0;//the num of the router
	int table[20][20];
	int number1 = 0;
	int* Ptable[20];
	router* h = new router;
	while (1)
	{
		ifstream in("topo.txt", ios::in);
		if (in)
		{
			in >> num;
			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					in >> table[i][j];
				}
			}
		}
		in.close();
		/*for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				Ptable[i][j] = table[i][j];
			}
		}*/
		/*for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout<< table[i][j]<<' ';
			}
			cout << endl;
		}*/
		for (int i = 0; i < num; i++)
		{
			cout << endl;
			Ptable[i] = table[i];
			for (int j = 0; j < num; j++)
			{
				cout << table[i][j] << ' ';
			}
		}
		cout << endl << "choice? 1 for table, 2 for delete, 3 for add, else for quit." << flush << endl;
		cin >> number1;
		if (number1 == 1)
		{
			cout << "number" << flush << endl;
			cin >> number1;
			h->number = number1;
			h->create(num, Ptable);
		}
		else if (number1 == 2)
		{
			num = h->delete_(num);
		}
		else if (number1 == 3)
		{
			num = h->add(num);
		}
		else
			exit(2);
	}
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
