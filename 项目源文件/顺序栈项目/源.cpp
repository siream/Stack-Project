#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"
#include "struct.h"
#include "UI.h"
#include "seqlistHero.h"
#include "seqlistDogface.h"


int main() {
	system("mode con cols=120 lines=40");			//设定控制台大小
	SetCursor(FALSE);								//隐藏光标
	Player player = Ready();						//开始界面
	Menu(&player);
}

/*初始化玩家*/
Player InitPlayer(char name[nameLength]) {
	Player player;
	player.diamond = 0;
	strcpy_s(player.name, name);
	InitHero(&player.ownHero);
	InitHero(&player.unHero);
	for (int i = 0;i < heroNum;i++)
		HeroInsert(&player.unHero, i, catchHero(i+1));
	InitDogface(&player.ownDogface);
	InitDogface(&player.unDogface);
	for (int i = 0;i < dogfaceNum;i++)
		DogfaceInsert(&player.unDogface, i, catchDogface(i+1));
	return player;
}
