#pragma once
class router_table
{
public:
	int next_step;//address of the next step
	char destination[33];//ip address
	char mask[33];//subnet mask
	router_table* next;
	friend class router;
	void create(int n,int p);
};

