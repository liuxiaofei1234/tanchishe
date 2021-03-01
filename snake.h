#include"unit.h"
#include<iostream>
#include<vector>
#include<conio.h>
typedef enum
{
	KUP,
	KDOWN,
	KLEFT,
	KRIGHT
}Dir;
class snake
{
public:
	snake(int x = 40, int y = 15, char pic = '*', int len = 4, int speed = 500, Dir dir = KUP);
	virtual~snake();
	void move();
	void showsnake();
	void erasesnake();
	Dir keyboard();
public:
	int m_headx;
	int m_heady;
	int m_len;
	int m_speed;
	int m_pic;
	Dir m_dir;
	vector<unit> m_body;
};