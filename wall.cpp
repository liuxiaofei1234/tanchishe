#include<iostream>
#include"wall.h"
using namespace std;
void wall::initwall() //��ʼ��ǽ�ڣ��ö�ά����
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || i == row - 1)
			{
				gamewall[i][j] = '-';
			}
			else if (j == 0 || j == col - 1)
			{
				gamewall[i][j] = '|';
			}
			else
			{
				gamewall[i][j] = ' ';
			}
		}
	}
}
void wall::drawwall()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			//����ʱ����һ���ո񣬿������ÿ�һЩ
			cout << gamewall[i][j];
		}
		if (i == 1)
		{
			cout << "��Ϸ����:̰����";
		}
		if (i == 3)
		{
			cout << "wsad�ĵ���ĸ����";
		}
		if (i == 5)
		{
			cout << "ÿ��5��Ϊһ��";
		}
		if (i == 7)
		{
			cout << "��д�ߣ�����";
		}
		if (i == 9)
		{
			cout << "   ";
		}
		if (i == 11)
		{
			cout << "   ";
		}
		cout << endl;
	}
}