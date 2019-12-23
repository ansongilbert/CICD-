#include "router.h"
#include"router_table.h"
#include<iostream>
using namespace std;
void router::create(int n, int** p)
{
	cout << endl << "Anson Gilbert" << endl;
	int m =0;
	int j = this->number;
	int k = 255;
	int dis[20];//shortest distance
	int nxt[20];//the next node
	int tag[20];//tag for if is visited
	int count[20] = { 0 };//the number of every item 
	int fin = n ; 
	//router_table* pre=this->a;
	for (int i = 0; i < n; i++)
	{
		if (p[j][i] != 0)
		{
			if (k > p[j][i])
			{
				m = i;
				k = p[j][i];
				//nxt[i] = j;
			}
			dis[i] = p[j][i]; //cout << i << ' ' << dis[i] << endl;
			nxt[i] = this->number;
		}
		else
		{
			dis[i] = 255;
			nxt[i] = this->number;
		}
	}
	dis[this->number] = 0;
	tag[this->number] = 1;
	tag[m] = 1;
	j = m;
	int b = 0; 
	while (fin--)
	{
		k = 255;
		b = dis[j]; //cout << b <<' '<<j<< endl;
		for (int i = 0; i < n; i++)
		{
			if (p[j][i] != 0)
			{
				//cout << i << ' ' << dis[i] << ' ' << j << ' ' << p[j][i] << endl;
				if (dis[i] > p[j][i] + b)
				{
					dis[i] = p[j][i] + b;
					nxt[i] = j;
				}
				if (k > p[j][i])
				{
					//cout <<endl<< i<<endl;
					if (tag[i] != 1)
					{
						m = i;
						k = p[j][i];
					}
				}
				
			}
		}
		j = m;
		tag[m] = 1;
	}
	for (int i = 0; i <= n - 1; i++)
	{
		while (nxt[nxt[i]] != this->number)
		{
			nxt[i] = nxt[nxt[i]]; //cout << 'c';
		}
	}
	/*cout << endl << endl;
	for (int i = 0; i <= n - 1; i++)
	{
		cout << dis[i] << ' ' << nxt[i] << endl;
	}*/
	/*int default_ = 0; 
	for (int i = 0; i <= n - 1; i++)
	{
		if (nxt[i] == this->number)
		{
			count[i]++;
		}
		else 
		{
			count[nxt[i]]++;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		if (count[default_] < count[i])
			default_ = i;
	}*/
	/*for (int i = 0; i <= n - 1; i++)
		cout << count[i] << endl;*/
	this->a = new router_table;
	router_table* pre = this->a;
	router_table* cur = nullptr;
	for (int i = 0; i <= n - 1; i++)
	{
		if (i != this->number)
		{
			cur = new router_table;
			cur->next = nullptr;
			pre->next = cur;
			if (nxt[i] == this->number)
				cur->create(i + 1, i);
			else
				cur->create(i + 1, nxt[i]);
			pre = cur;
		}
	}//cout << endl << default_;
	/*cur = new router_table;
	cur->next = nullptr;
	pre->next = cur;
	cur->create(default_, default_);*/
	pre = cur;
	cur = this->a->next;
	int des[4] = { 0,0,0,0 };
	int mask[4] = { 0,0,0,0 };
	int aa = 0;
	int bb = 0;
	while (cur != nullptr)
	{
		aa = 0;
		bb = 0;
		for (int i = 0; i < 8; i++)
		{
			aa = cur->destination[i] - '0';
			bb = cur->mask[i] - '0';
			for (int j = 1; j < 8 - i; j++)
			{
				aa *= 2;
				bb *= 2;
			}
			des[0] += aa;
			mask[0] += bb;
		}
		aa = 0;
		bb = 0;
		for (int i = 8; i < 16; i++)
		{
			aa = cur->destination[i] - '0';
			bb = cur->mask[i] - '0';
			for (int j = 9; j < 16 - i; j++)
			{
				aa *= 2;
				bb *= 2;
			}
			des[1] += aa;
			mask[1] += bb;
		}
		aa = 0;
		bb = 0;
		for (int i = 16; i < 24; i++)
		{
			aa = cur->destination[i] - '0';
			bb = cur->mask[i] - '0';
			for (int j = 17; j < 24 - i; j++)
			{
				aa *= 2;
				bb *= 2;
			}
			des[2] += aa;
			mask[2] += bb;
		}
		aa = 0;
		bb = 0;
		for (int i = 24; i < 32; i++)
		{
			aa = cur->destination[i] - '0';
			bb = cur->mask[i] - '0';
			for (int j = 25; j < 32 - i; j++)
			{
				aa *= 2;
				bb *= 2;
			}
			des[3] += aa;
			mask[3] += bb;
		}
		cout << endl << "des: ";
		for (int i = 0; i < 4; i++)
		{
			cout << des[i] << '.';
			des[i] = 0;
		}
		cout << "mask: ";
		for (int i = 0; i < 4; i++)
		{
			cout << mask[i] << '.';
			mask[i] = 0;
		}
		cout << "next: " << cur->next_step + 1;
		//cout << endl << "des: " << cur->destination << "mask: " << cur->mask << ' ' << "next: " << cur->next_step;
		cur = cur->next;
	}
}