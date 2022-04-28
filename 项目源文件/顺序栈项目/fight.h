#include "catch.h"
#include "stack.h"

#define DEATH 114514

void Error();						//错误界面
void InitFrame();					//初始化边框
int HeroLength(HeroList);			//英雄表长
int DogfaceLength(DogfaceList);		//小兵表长

int Fight(Player, int);					//战斗
void Menu(Player, char);			//操作列表
void home(int HP);						//城堡
void entity(Army player, Army mob);		//实体
void fighting(Army*, Army*, int*);		//战斗计算
int Death(Army*, Army*, int*);			//死亡

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
	char choosech;		//选择
	int choose;
	char menu = 'b';	//菜单
	/*双方army栈*/
	Army playerArmy;
	InitStack(&playerArmy);
	Army mobArmy = catchArmy(level);
	/*玩家*/
	int gold = 20;		//金币
	int HP = 5000;		//血量
	int i = 1;
	/*坐标信息*/
	int xy[13][13] = { { 0 },{0} };
	InitFrame();
	Menu(player, menu);
	printf("\33[36m\33[%d;%dH金币:%-10d", 29, 12, gold);
	while (1) {
		while (i--) {
			if (_kbhit()) {
				choosech = _getch();
				if (choosech > '0' && choosech <= '9') {
					choose = choosech - 48;
					if (menu == 'a') {
						if (choose <= player.ownHero.length)
							if (gold >= player.ownHero.hero[choose-1].gold) {
								gold -= player.ownHero.hero[choose - 1].gold;
								catchSkill(&playerArmy, &mobArmy, choose);////使用技能
								printf("\33[36m\33[%d;%dH金币:%-10d", 29, 12, gold);
								goto entity;
							}
							else
								break;////金币不足
						else
							break;////没有英雄
					}
					else {
						if (choose <= player.unDogface.length)
							if (!StackFull(playerArmy))
								if (gold >= player.unDogface.dogface[choose-1].attribute.gold) {
									gold -= player.unDogface.dogface[choose-1].attribute.gold;
									StackPush(&playerArmy, player.unDogface.dogface[choose-1]);
									printf("\33[36m\33[%d;%dH金币:%-10d", 29, 12, gold);
									goto entity;
								}
								else
									break;////金币不足
							else
								break;////栈满
						else
							break;////没有小兵
					}
				}
				else if (choosech == '0') {
					gold++;
					printf("\33[36m\33[%d;%dH金币:%-10d", 29, 12, gold);
				}
				else
					if (menu == 'a')
						menu = 'b';
					else
						menu = 'a';
				break;
			}
			if (i == 20000) {
				printf("\33[31m\33[%d;%dH                                           ", 25, 40);
				printf("\33[31m\33[%d;%dH                                           ", 26, 40);
			}
		}
		if (i <= 0) {
			i = 40000;
			fighting(&playerArmy, &mobArmy, &HP);
			Death(&playerArmy, &mobArmy, &HP);
			home(HP);
			if (HP <= 0)
				return 1;
			if (StackEmpty(mobArmy))
				return 0;
		entity:
			entity(playerArmy, mobArmy);
			continue;
		}
		else {
			Menu(player, menu);
			continue;
		}
	}
}
/*操作列表*/
void Menu(Player player, char menu) {
	if (menu == 'a') {
		printf("\33[36m\33[%d;%dH你的英雄", 30, 12);
		for (int i = 0;i < heroNum;i++) {
			printf("\33[%d;%dH|*  %d.%-10s  金币：%d  *|", 32 + 2 * (i / 3), 12 + 30 * (i % 3), i + 1, player.unHero.hero[i].name, player.unHero.hero[i].gold);
		}
	}
	else if (menu == 'b') {
		printf("\33[36m\33[%d;%dH你的小兵", 30, 12);
		for (int i = 0;i < dogfaceNum;i++) {
			printf("\33[36m\33[%d;%dH|*  %d.%-10s  金币：%d  *|\33[0m", 32 + 2 * (i / 3), 12 + 30 * (i % 3), i + 1, player.unDogface.dogface[i].name, player.unDogface.dogface[i].attribute.gold);
		}
	}
}

/*城堡*/
void home(int HP) {
	int x = 15;
	int y = 10;
	printf("\33[31m\33[%d;%dH      ▇       \33[0m", x, y + 1);
	printf("\33[%d;%dH      丨      ", x + 1, y);
	printf("\33[%d;%dH     _/\\_     ", x + 2, y);
	printf("\33[%d;%dH   _ |__| _   ", x + 3, y);
	printf("\33[%d;%dH_  |~~田~~|  _", x + 4, y);
	printf("\33[%d;%dH|~~ 田  田 ~~|", x + 5, y);
	printf("\33[%d;%dH~~~~~~~~~~~~~~~~", x + 6, y - 1);
	printf("\33[%d;%dH     城堡     ", x + 7, y);
	printf("\33[%d;%dH     %4d     ", x + 8, y, HP);
}

/*实体*/
void entity(Army player, Army mob) {
	int x = 20;
	int y = 30;
	int z = 35;
	printf("\33[0m\33[%d;%dH剩余小兵：%2d", x - 3, y - 5, player.top + 1);
	printf("\33[%d;%dH剩余小兵：%2d", x - 3, y + z + 8, mob.top + 1);
	if (StackEmpty(player)) {
		printf("\33[%d;%dH|     ×     |", x, y);
		printf("\33[%d;%dH|     无     |", x + 1, y);
		printf("\33[%d;%dH|    NULL    |", x + 2, y);
	}
	else {
		printf("\33[%d;%dH|     〇     |", x, y);
		switch (strlen(player.dogface[player.top].name)) {
		case 2:printf("\33[%d;%dH|     %-2s     |", x + 1, y, player.dogface[player.top].name);break;
		case 4:printf("\33[%d;%dH|    %-4s    |", x + 1, y, player.dogface[player.top].name);break;
		case 6:printf("\33[%d;%dH|   %-6s   |", x + 1, y, player.dogface[player.top].name);break;
		case 8:printf("\33[%d;%dH|  %-8s  |", x + 1, y, player.dogface[player.top].name);break;
		case 10:printf("\33[%d;%dH| %-10s |", x + 1, y, player.dogface[player.top].name);break;
		}
		printf("\33[%d;%dH|生命值：%-4d|", x + 2, y, player.dogface[player.top].attribute.HP);
	}
	if (StackEmpty(mob)) {
		printf("\33[%d;%dH|     ×     |", x, y + z);
		printf("\33[%d;%dH|     无     |", x + 1, y + z);
		printf("\33[%d;%dH|    NULL    |", x + 2, y + z);
	}
	else {
		printf("\33[%d;%dH|     〇     |", x, y + z);
		switch (strlen(mob.dogface[mob.top].name)) {
		case 2:printf("\33[%d;%dH|     %-2s     |", x + 1, y + z, mob.dogface[mob.top].name);break;
		case 4:printf("\33[%d;%dH|    %-4s    |", x + 1, y + z, mob.dogface[mob.top].name);break;
		case 6:printf("\33[%d;%dH|   %-6s   |", x + 1, y + z, mob.dogface[mob.top].name);break;
		case 8:printf("\33[%d;%dH|  %-8s  |", x + 1, y + z, mob.dogface[mob.top].name);break;
		case 10:printf("\33[%d;%dH| %-10s |", x + 1, y + z, mob.dogface[mob.top].name);break;
		}
		printf("\33[%d;%dH|生命值：%-4d|", x + 2, y + z, mob.dogface[mob.top].attribute.HP);
	}
}
/*战斗计算*/
void fighting(Army* player, Army* mob, int* HP) {
	if (StackEmpty(*player)) {
		*HP -= mob->dogface[mob->top].attribute.ATK;
		printf("\33[31m\33[%d;%dH城池无人值守，被攻击造成%d伤害！", 25, 40, mob->dogface[mob->top].attribute.ATK);
		printf("\33[31m\33[%d;%dH城池无人值守，被攻击造成%d伤害！", 26, 40, mob->dogface[mob->top].attribute.ATK);
	}
	else {
		int playerHP = player->dogface[player->top].attribute.HP;
		int mobHP = mob->dogface[mob->top].attribute.HP;
		/*敌方受到伤害*/
		mob->dogface[mob->top].attribute.HP -= (int)((1 - (mob->dogface[mob->top].attribute.DEF / 100.0)) * player->dogface[player->top].attribute.ATK);
		printf("\33[33m\33[%d;%dH%s发挥神勇，对%s造成%d伤害！", 25, 40, player->dogface[player->top].name, mob->dogface[mob->top].name, (int)((1 - (mob->dogface[mob->top].attribute.DEF / 100.0)) * player->dogface[player->top].attribute.ATK));
		/*玩家受到伤害*/
		player->dogface[player->top].attribute.HP -= (int)((1 - (player->dogface[player->top].attribute.DEF / 100.0)) * mob->dogface[mob->top].attribute.ATK);
		printf("\33[31m\33[%d;%dH%s发挥神勇，对%s造成%d伤害！\33[0m", 26, 40, mob->dogface[mob->top].name, player->dogface[player->top].name, (int)((1 - (player->dogface[player->top].attribute.DEF / 100.0)) * mob->dogface[mob->top].attribute.ATK));
	}
}
/*死亡*/
int Death(Army* player, Army* mob, int* HP) {
	Dogface a;
	if (player->dogface[player->top].attribute.HP <= 0)
		StackPop(player, &a);
	if (mob->dogface[mob->top].attribute.HP <= 0)
		StackPop(mob, &a);
	if (*HP <= 0)
		return DEATH;
	return 0;
}