/*
#pragma once
#include<iostream>
#include<vector>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include"food.h"
using namespace std;
class Snake:public unit
{
private:
	//蛇坐标结构
	struct  Snakecoor
	{
		int x;
		int y;
	};
	//蛇容器
	vector<Snakecoor> snakecoor;


	//判断和改变方向函数
	void degdir(Snakecoor& nexthead)	//参数：新蛇头结构变量、蛇坐标容器
	{
		static char key = 'd';	//静态变量防止改变移动方向后重新改回来

		if (_kbhit())			//改变蛇前进的方向;_kbbit()函数的作用是检查控制台窗口的按键是否被按下。
		{
			char temp = _getch();//_getch()函数的作用是从控制台中获取输入的字符，在获取输入的字符之后，并不会在控制台中显示该字符。

			switch (temp)		//如果临时变量的值为wasd中的一个，则赋值给key
			{
			default:
				break;
			case 'w':
			case 'a':
			case 's':
			case 'd':
				//如果temp的方向和key的方向不相反则赋值
				if ((key == 'w' && temp != 's') || (key == 's' && temp != 'w') || \
					(key == 'a' && temp != 'd') || (key == 'd' && temp != 'a'))
					key = temp;
			}
		}


		switch (key)		//根据key的值确定蛇的移动方向
		{
		case 'd':
			nexthead.x = snakecoor.front().x + 2;	  //新的蛇头的头部等于容器内第一个数据(旧蛇头)x坐标+2
			nexthead.y = snakecoor.front().y;
			break;
		case 'a':
			nexthead.x = snakecoor.front().x - 2;
			nexthead.y = snakecoor.front().y;
			break;
		case 'w':
			nexthead.x = snakecoor.front().x;
			nexthead.y = snakecoor.front().y - 1;
			break;
		case 's':
			nexthead.x = snakecoor.front().x;
			nexthead.y = snakecoor.front().y + 1;
		}

	}

	//游戏结束时需要做的事情
	void finmatt(const int score)
	{
		system("cls");
		gotoxy(40, 14);
		cout << "游戏结束";
		gotoxy(40, 16);
		cout << "得分：" << score;
		gotoxy(0, 26);
		exit(0);
	}

	//游戏结束的情况
	void finishgame(const int score)
	{
		//撞墙情况
		if (snakecoor[0].x > KWIDTH - 4 || snakecoor[0].x < 1 || snakecoor[0].y > KHEIGHT - 2 || snakecoor[0].y < 1)
			finmatt(score);

		//撞到自己情况
		for (int i = 1; i < snakecoor.size(); i++)
			if (snakecoor[0].x == snakecoor[i].x && snakecoor[0].y == snakecoor[i].y)
				finmatt(score);
	}
public:
	//构造初始化蛇的位置
	Snake()
	{
		Snakecoor temp;	//临时结构变量用于创建蛇
		for (int i = 5; i >= 0; i--)	//反向创建初始蛇身，初始蛇头朝东
		{
			temp.x = 16 + (i << 1);		//偶数
			temp.y = 8;
			snakecoor.push_back(temp);
		}

	}

	//蛇运动主要函数
	void move(food& food, int& score)
	{
		Snakecoor nexthead;			//新蛇头变量

		degdir(nexthead);				//判断和改变蛇前进的方向

		snakecoor.insert(snakecoor.begin(), nexthead);	//将新的蛇头插入容器头部

		gotoxy(KWIDTH, KHEIGHT);
		cout << "得分：" << score;				//每次移动都在左上角刷新得分

		finishgame(score);				//判断游戏结束函数

		if (snakecoor[0].x == food.getfoodm_x() && snakecoor[0].y == food.getfoodm_y())	//蛇头与食物重合
		{
			gotoxy(snakecoor[0].x, snakecoor[0].y);		//吃到食物时因为直接返回此次移动没有输出蛇身，会少输出一次蛇
			cout << "●";						        //所以在这里补上蛇移动时需要输出的字符
			gotoxy(snakecoor[1].x, snakecoor[1].y);
			cout << "■";	
			score++;			 //吃到食物得分+1		
			food.setfood();		 //如果蛇头坐标和食物坐标重合则重新产生一个食物
			return;				 //直接结束本次移动
		}
		
		for (int i = 0; i < snakecoor.size(); i++)	//遍历容器，判断食物与蛇身是否重合并输出整条蛇
		{
			gotoxy(snakecoor[i].x, snakecoor[i].y);		
			if (!i)								//头部输出圆形否则输出方块
				cout << "●";
			else
				cout << "■";
			//如果食物刷新到了蛇身上，则重新产生一个食物
			if (snakecoor[i].x == food.getfoodm_x() && snakecoor[i].y == food.getfoodm_y())
			{
				food.setfood();
			}
		}

		gotoxy(snakecoor.back().x, snakecoor.back().y);	//在容器尾部的地方输出空格
		cout << "  ";
		snakecoor.pop_back();						//删除容器中最后一个数据
	}

};
*/
#pragma once
#include <vector>
#include "unit.h"
#include"food.h"
#include<iostream>
using namespace std;

typedef enum Dir
{
	UP = 'w', 
	DOWN = 's',
	LEFT = 'a', 
	RIGHT = 'd'
};
class Snake:public unit
{
public:
	int m_HeadX;
	int m_HeadY;
	int m_Len;
	int m_Speed;
	Dir m_Dir;
	vector<unit> m_Body;
public:
	Snake(int x = 40, int y = 10, int len = 4, int speed = 500, Dir dir = RIGHT);
	~Snake();
	void showSnake();
	void eraseSnake();
	void finishgame(const int score);
	void move(food& food,int& score);
	Dir gaifangxiang();
};