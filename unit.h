#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '*');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);
public:
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH = 70;
	const static int KHEIGHT = 20;
	int m_iX;
	int m_iY;
	char m_cPic;
};
