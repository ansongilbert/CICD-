#pragma once
#include"router_table.h"
class router
{
public:
	int number;
	router_table* a;//table
	router* next;
	void create(int n, int** p);
	void delete_();
};

