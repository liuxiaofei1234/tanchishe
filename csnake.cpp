#include "csnake.h"
#include<conio.h>
#include"food.h"
Snake::Snake(int x, int y, int len, int speed, Dir dir)
{
	m_HeadX = x;
	m_HeadY = y;
	m_Len = len;
	m_Speed = speed;
	m_Dir = dir;
	for (int i = 0; i < m_Len; i++)
	{
		unit myUnit;
		m_Body.push_back(myUnit);
		switch (dir)
		{
		case UP:
			m_Body[i].m_iX = m_HeadX;
			m_Body[i].m_iY = m_HeadY-i;
			break;
		case DOWN:
			m_Body[i].m_iX = m_HeadX;
			m_Body[i].m_iY = m_HeadY+i;
			break;
		case LEFT:
			m_Body[i].m_iX = m_HeadX+2*i;//×
			m_Body[i].m_iY = m_HeadY;
			break;
		case RIGHT:
			m_Body[i].m_iX = m_HeadX-2*i;//×
			m_Body[i].m_iY= m_HeadY;
			break;
		default:
			break;
		}
	}
}
Snake::~Snake()
{
}

void Snake::showSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].show();
	}
}

void Snake::eraseSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].erase();
	}
}
//游戏结束时的分数界面
void finmatt(const int score)
{
	system("cls");
	unit::gotoxy(40, 14);
	std::cout << "游戏结束";
	unit::gotoxy(40, 16);
	std::cout << "得分：" << score;
	unit::gotoxy(0, 26);
	exit(0);
}
void Snake::finishgame(const int score)//判断有没有结束
{
	//撞到墙时
	if (m_Body[0].m_iX > KWIDTH - 4 || m_Body[0].m_iX < 1 || m_Body[0].m_iY>KHEIGHT - 2 || m_Body[0].m_iY < 1)
	{
		finmatt(score);
	}
	//撞到自己身体
	for (int i = 1; i < m_Body.size(); i++)
	{
		if (m_Body[0].m_iX == m_Body[i].m_iX && m_Body[0].m_iY == m_Body[i].m_iY)
		{
			finmatt(score);
		}
	}
	if (score == 45)
	{
		cout << "恭喜你通关了";
		Sleep(5000);
		finmatt(score);
	}
}
Dir Snake::gaifangxiang()
{
	if (_kbhit())			//改变蛇前进的方向;_kbbit()函数的作用是检查控制台窗口的按键是否被按下。
	{
		char temp = _getch();//_getch()函数的作用是从控制台中获取输入的字符，在获取输入的字符之后，并不会在控制台中显示该字符。
		switch (temp)		//如果临时变量的值为wasd中的一个，则赋值给key
		{
		case 'w'://up 
			if (m_Dir != Dir::DOWN)//判断想要移动方向与原本运动方向是否相反，相反则无效
				m_Dir = Dir::UP;
			break;
		case 's'://down
			if (m_Dir != Dir::UP)
				m_Dir = Dir::DOWN;
			break;
		case 'a'://leftxun'huan
			if (m_Dir != Dir::RIGHT)
				m_Dir = Dir::LEFT;
			break;
		case 'd'://right
			if (m_Dir != Dir::LEFT)
				m_Dir = Dir::RIGHT;
			break;
		case ' ':
			while (1)
				if (_kbhit() && _getch() == ' ')
					break;
		default:
			break;
		}
	}
	return m_Dir;
}
void Snake::move(food& food,int& score)//----------------------------------------------
{//实现蛇身的移动 body move
	static int sudu = 200;
	for (int i = m_Len - 1; i > 0; i--)
	{
		m_Body[i].m_iX = m_Body[i - 1].m_iX;
		m_Body[i].m_iY = m_Body[i - 1].m_iY;
	}
	m_Dir = gaifangxiang();//改变蛇头方向的函数
	switch (m_Dir)
	{
	case UP:
		m_Body[0].m_iX;
		m_Body[0].m_iY--;
		break;
	case DOWN:
		m_Body[0].m_iX;
		m_Body[0].m_iY++;
		break;
	case LEFT:
		m_Body[0].m_iX= m_Body[0].m_iX-2;
		m_Body[0].m_iY;
		break;
	case RIGHT:
		m_Body[0].m_iX= m_Body[0].m_iX+2;
		m_Body[0].m_iY;
		break;
	default:
		break;
	}
	gotoxy(KWIDTH,9);
	std::cout << "得分：" << score;
	gotoxy(KWIDTH, 11);
	std::cout << "关卡：" << (score / 5)+1;
	finishgame(score);//判断有没有结束
	if (m_Body[0].m_iX==food.getfoodm_x()&& m_Body[0].m_iY == food.getfoodm_y())//蛇吃到食物时
	{
		unit a(0,0,'*');
		m_Body.push_back(a);
		m_Len++;
		score++;
		food.setfood();
		if (sudu >= 120 && score % 5 == 0 )
		{
			sudu -= 20;
		}
	}
	for (int i = 0; i < m_Body.size();i++)//遍历蛇，判断蛇与食物有没有重合
	{
		if (m_Body[i].m_iX == food.getfoodm_x() && m_Body[i].m_iY == food.getfoodm_y())
		{
			food.setfood();
		}
	}
	gotoxy(KWIDTH, 13);
	std::cout << "速度：" << sudu;
	showSnake();
	Sleep(sudu);
	eraseSnake();
}
