void InitFrame();

void ShopMenu(Player* player) {
	InitFrame();
	printf("\33[%d;%dH这是一个非常牛逼的商店界面！", 10, 45);
	getchar();
}
