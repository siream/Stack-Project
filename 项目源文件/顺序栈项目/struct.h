/*实体属性*/
typedef struct {
	int HP;			//生命值
	int ATK;		//攻击力
	int DEF;		//防御力
	int gold;		//造价
}Attribute;

/*小兵*/
typedef struct {
	char name[nameLength];	//名称
	Attribute attribute;	//属性
	int ID;					//ID
	int diamond;			//商店价格
}Dogface;

/*英雄*/
typedef struct {
	int	ID;							//英雄ID
	int IDskill;					//技能ID
	char name[nameLength];			//名字
	int diamond;					//商店价格
}Hero;

/*英雄顺序表*/
typedef struct {
	Hero hero[heroNum];
	int length;
}HeroList;

/*兵种顺序表*/
typedef struct {
	Dogface dogface[dogfaceNum];
	int length;
}DogfaceList;

/*玩家*/
typedef struct {
	char name[nameLength];			//玩家名称
	int diamond;					//玩家钻石
	HeroList ownHero;				//已有英雄
	HeroList unHero;				//未有英雄
	DogfaceList ownDogface;			//已有兵种
	DogfaceList unDogface;			//未有兵种
}Player;