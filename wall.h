#pragma once
#include<iostream>
#include"unit.h"
using namespace std;
class wall:public unit
{
public:
	enum
	{
		row = KHEIGHT,
		col = KWIDTH
	};
	void initwall();
	void drawwall();
	char gamewall[row][col];
};
