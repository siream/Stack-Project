void InitFrame();
int getHero(Player*, int);
int HeroLength(HeroList);
int DogfaceLength(DogfaceList);

void FightMenu(Player* player) {
	while (1) {
		InitFrame();
		int x;
		int y;
		printf("\33[36m\33[%d;%dH选择你的难度", 5, 10);
		for (int i = 1;i <= levelNum;i++) {
			x = 5 + 4 * i;
			y = 13;
			printf("\33[%d;%dH*=====*", x - 1, y);
			printf("\33[%d;%dH|  %d  |", x, y, i);
			printf("\33[%d;%dH*=====*", x + 1, y);
		}
		printf("\33[%d;%dH当前英雄：", 10, 40);
		for (int i = 0;i < HeroLength(player->ownHero);i++)
			printf("\33[%d;%dH%s", 12 + 2 * i, 40, player->ownHero.hero[i].name);
		printf("\33[%d;%dH当前小兵:", 18, 40);
		for (int i = 0;i < DogfaceLength(player->ownDogface);i++)
			printf("\33[%d;%dH%s", 20 + 2 * i, 40, player->ownDogface.dogface[i].name);
	}
}
