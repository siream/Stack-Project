
/*初始化属性*/
void InitArrtibute(Attribute* attribute) {
	attribute->ATK = 100;			//初始化攻击力
	attribute->DEF = 10;			//初始化防御力
	attribute->HP = 1000;			//初始化血量
	attribute->gold = 0;			//初始化金币
}

/*初始化英雄*/
void InitHero(Hero* hero, int i, char name[nameLength]) {
	hero->army.ID = i;					//初始化 ID
	hero->army.top = -1;				//初始化军队
	InitArrtibute(&hero->attribute);	//初始化属性
	strcpy_s(hero->name, name);			//初始化名称
}

