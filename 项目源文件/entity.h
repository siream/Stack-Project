void InitHero(HeroList*);
void InitDogface(DogfaceList*);
/*初始化玩家*/
Player InitPlayer(char name[nameLength]) {
	Player player;
	player.diamond = 0;
	strcpy_s(player.name, name);
	InitHero(&player.ownHero);
	InitHero(&player.unHero);
	InitDogface(&player.ownDogface);
	InitDogface(&player.unDogface);
	return player;
}

/*初始化属性*/
void InitArrtibute(Attribute* attribute) {
	attribute->ATK = 100;			//初始化攻击力
	attribute->DEF = 10;			//初始化防御力
	attribute->HP = 1000;			//初始化血量
	attribute->gold = 0;			//初始化金币
}
