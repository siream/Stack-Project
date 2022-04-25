void InitFrame();//初始化框架

void ShopMenu(Hero* player) {
	InitFrame();
	printf("\33[%d;%dH这是一个非常牛逼的商店界面！", 10, 45);
	getchar();
}
//hero 英雄
void Inithero() {
	ShopMenu();
	if()
		printf("\33玩家尚无英雄");
	if () {
		printf("\33玩家已有英雄");
		printf("\33名称:");
		printf("\33ID（每个英雄拥有独立ID，用于比较）");
		printf("\33技能ID——————子函数catchSkill(),通过传入技能ID以及战斗时双方army栈生产对应效果");
		printf("\33价格————用钻石买");

	}
}

//Arms 兵种
void Arms() {
	ShopMenu();
	if()
		printf("\33玩家尚无兵种");
	if () {
		printf("\33玩家已有兵种");
		printf("\33攻击");
		printf("\33防御");
		printf("\33血量");
		printf("\33照价（战斗中使用金币的购买价格）");
		printf("\33 ID ————子函数catchDogface()，通过传入ID返回对应属性的小兵");
	}
}

//Diamonds 钻石
void Diamonds() {
	ShopMenu();
	printf("\33通过战斗获得，可以用来买东西");
}
