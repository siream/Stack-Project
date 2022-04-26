void InitFrame();

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
		printf("\33[%d;%dH当前英雄：",10,40);
		printf("\33[%d;%dH当前兵种：",15,40);
		_getch();
	}
}
