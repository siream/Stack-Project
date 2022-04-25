#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"
#include "struct.h"
#include "UI.h"
#include "seqlist.h"
#include "stack.h"

int main() {
	system("mode con cols=120 lines=40");		//设定控制台大小
	SetCursor(FALSE);								//隐藏光标
	Player player = Ready();									//开始界面
	while (1) {
		Menu(&player);
		system("CLS");
		_getch();
	}
}

/*菜单界面*/
void Menu(Player* player) {
	int x = 15;				//菜单位置
	int y = 52;				//菜单位置
	int distance = 3;		//菜单间隔
	char choose;			//用户选择
	InitFrame();
	printf("\33[36m\33[%d;%dH尊贵的骑士：%s", 5, 10, player->name);
	printf("\33[%d;%dH您拥有的金币：%d", 6, 10, player->gold);
	printf("\33[36m\33[%d;%dH请选择你要做什么", 10, 49);
	printf("\33[34m\33[%d;%dH——————————————\33[0m", 11, 43);
	printf("\33[36m\33[%d;%dH请输入1-3\33[0m", 12, 52);
	printf("\33[36m\33[%d;%dHo————o", x - 1, y);
	printf("\33[%d;%dH|  战斗  |", x, y);
	printf("\33[%d;%dH*————*", x + 1, y);
	printf("\33[%d;%dHo————o", x + distance - 1, y);
	printf("\33[%d;%dH|  商店  |", x + distance, y);
	printf("\33[%d;%dH*————*", x + distance + 1, y);
	printf("\33[%d;%dHo————o", x + distance * 2 - 1, y);
	printf("\33[%d;%dH|  退出  |", x + distance * 2, y);
	printf("\33[%d;%dH*————*", x + distance * 2 + 1, y);
	choose = _getch();
	switch (choose) {
	case '1':FightMenu(player);break;
	case '2':ShopMenu(player);break;
	case '3':return;
	default:Error();break;
	}
}