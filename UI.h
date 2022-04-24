#include<stdio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"


void SetCursor(int);				//设置光标
void JumpCursor(short, short);		//跳转光标至指定位置

void InitFrame();					//初始化游戏边框

void Ready(Hero* hero);				//开始界面

void Menu(Hero hero);				//菜单界面

/*设置光标*/
/*传入FALSE则隐藏光标*/
/*传入TRUE则显示光标*/
void SetCursor(int i) {
	CONSOLE_CURSOR_INFO cursor{ 1,i };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
/*跳转光标至指定坐标*/
/*x为第几行，y为第几列，从1开始*/
void JumpCursor(short y, short x) {
	COORD pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*开始界面*/
void Ready(Hero* hero) {
	char name[nameLength];
	InitFrame();
	printf("\33[%d;%dH欢迎进入游戏", 12, 50);
	printf("\33[%d;%dH请输入你的名字", 13, 49);
	SetCursor(TRUE);
	JumpCursor(14, 52);
	gets_s(name);
	strcpy_s(hero->name, name);
}

/*菜单界面*/
void Menu(Hero hero) {
	InitFrame();
	printf("\33[%d;%dH尊贵的骑士：%s", 5, 20, hero.name);
	printf("\33[%d;%dH您拥有的金币：%d", 6, 20, hero.attribute.gold);
	getchar();
}

/*初始化游戏边框*/
void InitFrame() {
	system("CLS");
	int color1 = 30;		//边框前景色(范围30-37)
	int color2 = 43;		//边框后景色（范围40-47）
	for (int i = 1;i < COL;i++)
		for (int j = 1;j <= ROW;j++) {
			if (i == 1 || i == COL - 1)
				printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, TOP);
			else
				if (j == 1 || j == ROW)
					printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, SIDE);
		}
}

