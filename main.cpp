#include"food.h"
#include"unit.h"
#include"wall.h"
#include"csnake.h"
#include<conio.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
void HideCursor()			//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	//GetStdHandle(STD_OUTPUT_HANDLE)：固定输出句柄
}
void start()
{
	unit::gotoxy(70, 25);
	cout << "an shui yi jian jin ru you xi xuanzhe jiemian";
	unit::gotoxy(70, 26);
	system("pause");//文字 "请按任意键继续"   是system("pause")：的效果
}
int main()
{
	if(MessageBox(GetForegroundWindow(),L"是否开始游戏",L"贪吃蛇",MB_OKCANCEL)==1)
	{
		HideCursor();
		int x;
		wall a;
		a.initwall();
		a.drawwall(); 
		food b;
		b.setfood();
		Snake nake;
		int fenshu = 0;
		while (true)
		{
			nake.move(b,fenshu);
		}
		return 0;
	}
	cout << "好好学习" << endl;
}