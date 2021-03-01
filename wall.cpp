#include<iostream>
#include"wall.h"
using namespace std;
void wall::initwall() //初始化墙壁，用二维数组
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
			//画的时候多加一个空格，看起来好看一些
			cout << gamewall[i][j];
		}
		if (i == 1)
		{
			cout << "游戏名称:贪吃蛇";
		}
		if (i == 3)
		{
			cout << "wsad四的字母控制";
		}
		if (i == 5)
		{
			cout << "每吃5个为一关";
		}
		if (i == 7)
		{
			cout << "编写者：刘飞";
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