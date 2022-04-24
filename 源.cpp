#include<stdio.h>
#include<conio.h>
#include<Windows.h>

#include "define.h"
#include "struct.h"
#include "UI.h"

int main(){
	system("mode con cols=120 lines=40");		//设定控制台大小
	SetCursor(FALSE);								//隐藏光标
	Hero player;
	Ready(&player);									//开始界面
	Menu(player);
}