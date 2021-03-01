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
	//������ṹ
	struct  Snakecoor
	{
		int x;
		int y;
	};
	//������
	vector<Snakecoor> snakecoor;


	//�жϺ͸ı䷽����
	void degdir(Snakecoor& nexthead)	//����������ͷ�ṹ����������������
	{
		static char key = 'd';	//��̬������ֹ�ı��ƶ���������¸Ļ���

		if (_kbhit())			//�ı���ǰ���ķ���;_kbbit()�����������Ǽ�����̨���ڵİ����Ƿ񱻰��¡�
		{
			char temp = _getch();//_getch()�����������Ǵӿ���̨�л�ȡ������ַ����ڻ�ȡ������ַ�֮�󣬲������ڿ���̨����ʾ���ַ���

			switch (temp)		//�����ʱ������ֵΪwasd�е�һ������ֵ��key
			{
			default:
				break;
			case 'w':
			case 'a':
			case 's':
			case 'd':
				//���temp�ķ����key�ķ����෴��ֵ
				if ((key == 'w' && temp != 's') || (key == 's' && temp != 'w') || \
					(key == 'a' && temp != 'd') || (key == 'd' && temp != 'a'))
					key = temp;
			}
		}


		switch (key)		//����key��ֵȷ���ߵ��ƶ�����
		{
		case 'd':
			nexthead.x = snakecoor.front().x + 2;	  //�µ���ͷ��ͷ�����������ڵ�һ������(����ͷ)x����+2
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

	//��Ϸ����ʱ��Ҫ��������
	void finmatt(const int score)
	{
		system("cls");
		gotoxy(40, 14);
		cout << "��Ϸ����";
		gotoxy(40, 16);
		cout << "�÷֣�" << score;
		gotoxy(0, 26);
		exit(0);
	}

	//��Ϸ���������
	void finishgame(const int score)
	{
		//ײǽ���
		if (snakecoor[0].x > KWIDTH - 4 || snakecoor[0].x < 1 || snakecoor[0].y > KHEIGHT - 2 || snakecoor[0].y < 1)
			finmatt(score);

		//ײ���Լ����
		for (int i = 1; i < snakecoor.size(); i++)
			if (snakecoor[0].x == snakecoor[i].x && snakecoor[0].y == snakecoor[i].y)
				finmatt(score);
	}
public:
	//�����ʼ���ߵ�λ��
	Snake()
	{
		Snakecoor temp;	//��ʱ�ṹ�������ڴ�����
		for (int i = 5; i >= 0; i--)	//���򴴽���ʼ������ʼ��ͷ����
		{
			temp.x = 16 + (i << 1);		//ż��
			temp.y = 8;
			snakecoor.push_back(temp);
		}

	}

	//���˶���Ҫ����
	void move(food& food, int& score)
	{
		Snakecoor nexthead;			//����ͷ����

		degdir(nexthead);				//�жϺ͸ı���ǰ���ķ���

		snakecoor.insert(snakecoor.begin(), nexthead);	//���µ���ͷ��������ͷ��

		gotoxy(KWIDTH, KHEIGHT);
		cout << "�÷֣�" << score;				//ÿ���ƶ��������Ͻ�ˢ�µ÷�

		finishgame(score);				//�ж���Ϸ��������

		if (snakecoor[0].x == food.getfoodm_x() && snakecoor[0].y == food.getfoodm_y())	//��ͷ��ʳ���غ�
		{
			gotoxy(snakecoor[0].x, snakecoor[0].y);		//�Ե�ʳ��ʱ��Ϊֱ�ӷ��ش˴��ƶ�û����������������һ����
			cout << "��";						        //���������ﲹ�����ƶ�ʱ��Ҫ������ַ�
			gotoxy(snakecoor[1].x, snakecoor[1].y);
			cout << "��";	
			score++;			 //�Ե�ʳ��÷�+1		
			food.setfood();		 //�����ͷ�����ʳ�������غ������²���һ��ʳ��
			return;				 //ֱ�ӽ��������ƶ�
		}
		
		for (int i = 0; i < snakecoor.size(); i++)	//�����������ж�ʳ���������Ƿ��غϲ����������
		{
			gotoxy(snakecoor[i].x, snakecoor[i].y);		
			if (!i)								//ͷ�����Բ�η����������
				cout << "��";
			else
				cout << "��";
			//���ʳ��ˢ�µ��������ϣ������²���һ��ʳ��
			if (snakecoor[i].x == food.getfoodm_x() && snakecoor[i].y == food.getfoodm_y())
			{
				food.setfood();
			}
		}

		gotoxy(snakecoor.back().x, snakecoor.back().y);	//������β���ĵط�����ո�
		cout << "  ";
		snakecoor.pop_back();						//ɾ�����������һ������
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