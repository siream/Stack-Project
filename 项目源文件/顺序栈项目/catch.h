
/*获取小兵*/
Dogface catchDogface(int i) {
	/*小兵列表*/
	/*名称,属性(生命值，攻击力，防御力，造价)，ID，商店价格*/
	Dogface dError = { "ERROR", {-1,-1,-1,-1},-1,-1 };
	Dogface d0 = { "NULL",{0,0,0,0},0,0 };
	Dogface d1 = { "刀刀姬",{100,10,10,10},1,100 };
	Dogface d2 = { "小蘑菇",{200,10,10,20},2,200 };
	Dogface d3 = { "笨蛋小上仙",{200,20,20,50},3,300 };
	/*返回小兵*/
	switch (i) {
	case 0:return d0;
	case 1:return d1;
	case 2:return d2;
	case 3:return d3;
	default:return dError;
	}
}
/*获取英雄*/
Hero catchHero(int i) {
	/*英雄列表*/
	/*英雄ID，技能ID，名字，商店价格，技能消耗*/
	Hero hError = { -1,-1,"ERROR",-1,-1 };
	Hero h0 = { 0,0,"NULL",0 ,0};
	Hero h1 = { 1,1,"胡桃",100,10 };
	Hero h2 = { 2,2,"辽宁跑男奥",200,20 };
	Hero h3 = { 3,3,"三姓家奴",300,30 };
	/*返回英雄*/
	switch (i) {
	case 0:return h0;
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	default:return hError;
	}
}
/*获取关卡*/
Army catchArmy(int i) {
	Army army;
	InitStack(&army);
	/*填充关卡army栈*/
	switch (i) {
	case 0: {
		while (!StackPush(&army, catchDogface(0)));
	};break;
	case 1: {
		while (!StackPush(&army, catchDogface(1)));
	};break;
	case 2: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(1));
		while (!StackPush(&army, catchDogface(2)));
	};break;
	default: {
		while (!StackPush(&army, catchDogface(-1)));
	};break;
	}
	/*返回关卡army栈*/
	return army;
}
/*获取技能*/
void catchSkill(Army* player, Army* mob, int i) {

}