void Error();						//错误界面
void InitFrame();					//初始化边框
int HeroLength(HeroList);			//英雄表长
int DogfaceLength(DogfaceList);		//小兵表长

int Fight(Player, int);					//战斗
void Menu(Player player, char menu);	//操作列表
/*关卡选择*/
void FightMenu(Player* player) {
	char choosech;
	int choose;
	while (1) {
		InitFrame();
		int x;
		int y;
		printf("\33[36m\33[%d;%dH选择你的关卡", 5, 10);
		for (int i = 0;i < levelNum;i++) {
			x = 11 + 8 * ((i) % 3);
			y = 13 + ((i / 3) * 20);
			printf("\33[%d;%dH\\=============/", x - 2, y);
			printf("\33[%d;%dH|*           *|", x - 1, y);
			printf("\33[%d;%dH|    【%1d】    |", x, y, i + 1);
			printf("\33[%d;%dH|*           *|", x + 1, y);
			printf("\33[%d;%dH/=============\\", x + 2, y);
		}
		choosech = _getch();
		choose = choosech - 48;
		if (choose<1 || choose>levelNum) {
			Error();
			continue;
		}
		if (Fight(*player, choose))
			continue;
	}
}
/*战斗*/
int Fight(Player player, int level) {
	char choosech;
	int choose;
	char menu = 'b';
	int i = 400;
	InitFrame();
	Menu(player, menu);
	while (1) {
		if (i < 0)
			i = 400;
		while (i--) {
			printf("\33[%d;%dH%d", 20 + (i % 10), 20, i);
			if (_kbhit()) {
				choosech = _getch();
				if (choosech > '0' && choosech <= '9') {
					choose = choosech - 48;
				}
				else
					if (menu == 'a') {
						menu = 'b';
						Menu(player, menu);
					}
					else {
						menu = 'a';
						Menu(player, menu);
					}
			}

		}
	}
}
/*操作列表*/
void Menu(Player player, char menu) {
	if (menu == 'a') {
		printf("\33[%d;%dH你的英雄", 30, 12);
		for (int i = 0;i < 9;i++) {
			printf("\33[%d;%dH%d.%-10s 金币：%d", 32 + 2 * (i / 3), 12 + 24 * (i % 3), i + 1, player.unHero.hero[1].name, player.unHero.hero[1].gold);
		}
	}
	else if (menu == 'b') {
		printf("\33[%d;%dH你的小兵", 30, 12);
		for (int i = 0;i < 9;i++) {
			printf("\33[%d;%dH%d.%-10s 金币：%d", 32 + 2 * (i / 3), 12 + 24 * (i % 3), i + 1, player.unDogface.dogface[2].name, player.unDogface.dogface[2].attribute.gold);
		}
	}
}
