#include"food.h"
#include"unit.h"
#include"wall.h"
#include"csnake.h"
#include<conio.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
void HideCursor()			//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void SetColor(int colorID)//�����ı���ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	//GetStdHandle(STD_OUTPUT_HANDLE)���̶�������
}
void start()
{
	unit::gotoxy(70, 25);
	cout << "an shui yi jian jin ru you xi xuanzhe jiemian";
	unit::gotoxy(70, 26);
	system("pause");//���� "�밴���������"   ��system("pause")����Ч��
}
int main()
{
	if(MessageBox(GetForegroundWindow(),L"�Ƿ�ʼ��Ϸ",L"̰����",MB_OKCANCEL)==1)
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
	cout << "�ú�ѧϰ" << endl;
}