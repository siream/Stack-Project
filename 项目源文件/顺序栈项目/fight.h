void Error();						//错误界面
void InitFrame();					//初始化边框
int HeroLength(HeroList);			//英雄表长
int DogfaceLength(DogfaceList);		//小兵表长

int Fight(Player, int);			//战斗

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
int Fight(Player player, int choose) {

	while (1) {
		InitFrame();
		printf("\33[%d;%dH你的英雄",30,10);
		for (int i = 0;i < 1;i++) {
			printf("\33[%d;%dH\\============/",31,10+i*20);
			printf("\33[%d;%dH|*%10s*|",32,10+i*20,player.unHero.hero[0].name);
			printf("\33[%d;%dH/============\\",33,10+i*20);
		}
		_getch();
	}
}