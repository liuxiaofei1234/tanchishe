#include<iostream>
#include"unit.h"
using namespace std;
unit::unit(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}
unit::~unit()
{
}
void unit::show()
{
	gotoxy(m_iX, m_iY);
	cout << m_cPic;
}
void unit::erase()
{
	gotoxy(m_iX, m_iY);
	cout << " ";
}
void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;
	position.Y = y;
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);
}