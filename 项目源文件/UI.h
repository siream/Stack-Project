#include "entity.h"
#include "shop.h"
#include "fight.h"
void SetCursor(int);				//设置光标
void JumpCursor(short, short);		//跳转光标至指定位置

void InitFrame();					//初始化游戏边框

void Ready(Hero* hero);				//开始界面

void Menu(Hero* hero);				//菜单界面

void Error();						//错误界面

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
	InitHero(hero, 0, name);
	SetCursor(FLASE);
}

/*菜单界面*/
void Menu(Hero* player) {
	int x = 15;			//菜单位置
	int y = 52;			//菜单位置
	int distance = 3;		//菜单间隔
	char choose;		//用户选择
	InitFrame();
	printf("\33[36m\33[%d;%dH尊贵的骑士：%s", 5, 10, player->name);
	printf("\33[%d;%dH您拥有的金币：%d", 6, 10, player->attribute.gold);
	printf("\33[36m\33[%d;%dH请选择你要做什么", 10, 49);
	printf("\33[34m\33[%d;%dH——————————————\33[0m", 11, 43);
	printf("\33[36m\33[%d;%dH请输入1-3\33[0m", 12, 52);
	printf("\33[36m\33[%d;%dHo————o", x - 1, y);
	printf("\33[%d;%dH|  战斗  |", x, y);
	printf("\33[%d;%dH*————*", x + 1, y);
	printf("\33[%d;%dHo————o", x + distance - 1, y);
	printf("\33[%d;%dH|  商店  |", x + distance, y);
	printf("\33[%d;%dH*————*", x + distance + 1, y);
	printf("\33[%d;%dHo————o", x + distance * 2-1, y);
	printf("\33[%d;%dH|  退出  |", x + distance * 2, y);
	printf("\33[%d;%dH*————*", x + distance * 2+1, y);
	choose = _getch();
	switch (choose) {
	case '1':FightMenu(player);break;
	case '2':ShopMenu(player);break;
	case '3':return ;
	default:Error();break;
	}
}

/*初始化游戏边框*/
void InitFrame() {
	system("CLS");
	int color1 = 30;		//边框前景色(范围30-37)
	int color2 = 43;		//边框后景色（范围40-47）
	char top[3] = "¤";		//上下边框材质
	char side[3] = "||";	//左右边框材质
	for (int i = 1;i < COL;i++)
		for (int j = 1;j <= ROW;j++) {
			if (i == 1 || i == COL - 1)
				printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, side);
			else
				if (j == 1 || j == ROW)
					printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, top);
		}
}

/*错误界面*/
void Error() {
	int x=ROW/2-3;
	int y=46;
	printf("\33[31m\33[%d;%dH*——————————*",x,y);
	printf("\33[%d;%dH|！！！！！！！！！！|",x+1,y);
	printf("\33[%d;%dH|！请输入正确的选项！|",x+2,y);
	printf("\33[%d;%dH|！！！！！！！！！！|",x+3,y);
	printf("\33[%d;%dH*——————————*", x+4, y);
}