#include"router_table.h"
#include<iostream>
using namespace std;

void router_table::create(int n,int p)
{
	int m = 0;
	//to create the destination and the submask
	while (m <= 7)
	{
		this->destination[7 - m] = n % 2 + '0';
		this->mask[m] = '1';
		m++;
		n /= 2;
	}
	for (int i = 8; i < 32; i++)
	{
		this->destination[i] = '0';
		this->mask[i] = '0';
	}
	this->next_step = p; this->destination[32] = '\0'; this->mask[32] = '\0'; //cout << this->mask[7] << endl;
	//cout << this->destination << endl << this->mask << endl << endl;
}