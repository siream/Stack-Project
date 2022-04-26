#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"
#include "struct.h"
#include "UI.h"
#include "seqlist.h"
#include "stack.h"
#include "catch.h"

int main() {
	system("mode con cols=120 lines=40");		//设定控制台大小
	SetCursor(FALSE);								//隐藏光标
	Player player = Ready();									//开始界面
	Menu(&player);
}

/*初始化玩家*/
Player InitPlayer(char name[nameLength]) {
	Player player;
	player.diamond = 0;
	strcpy_s(player.name, name);
	InitHero(&player.ownHero);
	InitHero(&player.unHero);
	InitDogface(&player.ownDogface);
	InitDogface(&player.unDogface);
	return player;
}
