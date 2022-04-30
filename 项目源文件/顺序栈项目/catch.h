int StackPush(Army*, Dogface);
void InitStack(Army* army);
int StackPop(Army* army, Dogface* dogface);
/*获取小兵*/
Dogface catchDogface(int i) {
	/*小兵列表*/
	/*名称,属性(生命值，攻击力，防御力，造价)，ID，商店价格*/
	Dogface dError = { "ERROR", {-1,-1,-1,-1},-1,-1 };
	Dogface d0 = { "NULL",{0,0,0,0},0,0 };
	Dogface d1 = { "刀刀姬",{100,15,10,10},1,100 };
	Dogface d2 = { "小蘑菇",{200,10,10,20},2,200 };
	Dogface d3 = { "笨蛋小上仙",{200,20,20,50},3,300 };
	Dogface d4 = { "幼体猫猫头",{200,25,20,60},4,500 };
	Dogface d5 = { "猫猫头",{300,20,30,70},5,700 };
	Dogface d6 = { "基础猫猫头",{400,30,30,90},6,800 };
	Dogface d7 = { "强化猫猫头",{600,40,35,110},7,1000 };
	Dogface d8 = { "精英猫猫头",{1000,50,40,150},8,1400 };
	Dogface d9 = { "终极猫猫头",{2000,100,90,500},9,2000 };
	/*返回小兵*/
	switch (i) {
	case 0:return d0;
	case 1:return d1;
	case 2:return d2;
	case 3:return d3;
	case 4:return d4;
	case 5:return d5;
	case 6:return d6;
	case 7:return d7;
	case 8:return d8;
	case 9:return d9;
	default:return dError;
	}
}
/*获取英雄*/
Hero catchHero(int i) {
	/*英雄列表*/
	/*英雄ID，技能ID，名字，商店价格，技能消耗*/
	Hero hError = { -1,-1,"ERROR",-1,0 };
	Hero h0 = { 0,0,"NULL",0 ,0 };
	Hero h1 = { 1,1,"胡桃",100,30 };
	Hero h2 = { 2,2,"辽宁跑男",200,40 };
	Hero h3 = { 3,3,"三姓家奴",300,50 };
	Hero h4 = { 4,4,"赑屃",400,60 };
	Hero h5 = { 5,5,"杀疯辣",600,70 };
	Hero h6 = { 6,6,"护城河",800,80 };
	Hero h7 = { 7,7,"招财猫猫",1200,90 };
	Hero h8 = { 8,8,"v1龙摆尾",1600,100 };
	Hero h9 = { 9,9,"这把算我赢",2000,500 };
	/*返回英雄*/
	switch (i) {
	case 0:return h0;
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	case 4:return h4;
	case 5:return h5;
	case 6:return h6;
	case 7:return h7;
	case 8:return h8;
	case 9:return h9;
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
		while (StackPush(&army, catchDogface(0)));
	};break;
	case 1: {
		while (StackPush(&army, catchDogface(1)));
	};break;
	case 2: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(1));
		while (StackPush(&army, catchDogface(2)));
	};break;
	case 3: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(2));
		while (StackPush(&army, catchDogface(3)));
	}
	case 4: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(3));
		while (StackPush(&army, catchDogface(4)));
	}
	case 5: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(4));
		while (StackPush(&army, catchDogface(5)));
	}
	case 6: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(5));
		while (StackPush(&army, catchDogface(6)));
	}
	case 7: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(6));
		while (StackPush(&army, catchDogface(7)));
	}
	case 8: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(7));
		while (StackPush(&army, catchDogface(8)));
	}
	case 9: {
		for (i = 0;i < armyLength / 2;i++)
			StackPush(&army, catchDogface(8));
		while (StackPush(&army, catchDogface(9)));
	}
	default: {
		while (StackPush(&army, catchDogface(-1)));
	};break;
	}
	/*返回关卡army栈*/
	return army;
}
/*获取技能*/
void catchSkill(Army* player, Army* mob, int i, int* HP, int* gold) {
	Dogface x;
	gold -= catchHero(i).gold;
	switch (i) {
	case 1: {
		player->dogface[player->top].attribute.HP += 100;
		printf("\33[33m\33[%d;%dH你使用了技能，己方生命值增加100！", 25, 40);
	};return;
	case 2: {
		mob->dogface[mob->top].attribute.HP -= 100;
		printf("\33[33m\33[%d;%dH你使用了技能，敌方生命值降低100！", 25, 40);
	};return;
	case 3: {
		StackPop(player, &x);
		StackPop(mob, &x);
		printf("\33[33m\33[%d;%dH你使用了技能，双方小兵同归于尽！", 25, 40);
	};return;
	case 4: {
		player->dogface[player->top].attribute.DEF *= 2;
		printf("\33[33m\33[%d;%dH你使用了技能，己方小兵防御力翻倍！", 25, 40);
	};return;
	case 5: {
		player->dogface[player->top].attribute.HP /= 2;
		player->dogface[player->top].attribute.ATK *= 2;
		printf("\33[33m\33[%d;%dH你使用了技能，己方小兵以血量换取攻击！", 25, 40);
	};return;
	case 6: {
		*HP += 100;
		printf("\33[33m\33[%d;%dH你使用了技能，城堡增加100生命值！", 25, 40);
	}return;
	case 7: {
		*gold += 180;
		printf("\33[33m\33[%d;%dH你使用了技能，获得180金币！", 25, 40);
	};return;
	case 8: {
		StackPop(mob, &x);
		StackPop(mob, &x);
		printf("\33[33m\33[%d;%dH你使用了技能，敌方两个小兵死亡！", 25, 40);
	}return;
	case 9: {
		while (StackPop(mob, &x));
		printf("\33[33m\33[%d;%dH你使用了技能，赢了！                ", 25, 40);
	}return;
	default:return;
	}
}