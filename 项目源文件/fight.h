void InitFrame();

void FightMenu(Hero* player) {
	InitFrame();
	printf("\33[%d;%dH这是一个非常牛逼的战斗界面！",10,45);
	getchar();
}
