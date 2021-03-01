#pragma once
#include "unit.h"
#include<vector>
using namespace std;
class food : public unit
{
public:
	food(int x=0, int y=0, char c='@');
	virtual ~food();
	void setfood();
	int getfoodm_x()		//返回食物的x坐标
	{
		return m_iX;
	}
	int getfoodm_y()		//返回食物的y坐标
	{
		return m_iY;
	}
};