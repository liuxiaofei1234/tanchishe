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
	int getfoodm_x()		//����ʳ���x����
	{
		return m_iX;
	}
	int getfoodm_y()		//����ʳ���y����
	{
		return m_iY;
	}
};