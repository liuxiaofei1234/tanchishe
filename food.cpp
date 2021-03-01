#include<iostream>
#include<ctime>
#include"food.h"
food::~food() {}
food::food(int x , int y , char c)
{
	m_iX = x;
	m_iY = y;
	m_cPic = c;
}
void food::setfood()
{
		srand((int)time(NULL));
	L1:
		m_iX = KLEFT - 1 + rand() % (KWIDTH - 4);
		m_iY = KUP - 1 +rand()%(KHEIGHT-2);

		if (m_iX % 2)		//如果食物的x坐标不是偶数则重新确定食物的坐标
			goto L1;

		gotoxy(m_iX, m_iY);	//在确认好的位置输出食物
		cout << '#';
}