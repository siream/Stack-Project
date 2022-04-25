/*实体属性*/
typedef struct {
	int HP;			//生命值
	int ATK;		//攻击力
	int DEF;		//防御力
	int gold;		//金币
}Attribute;

/*小兵*/
typedef struct {
	Attribute attribute;	//属性
	int type;				//类型
}Dogface;

/*军队*/
typedef struct {
	int ID;							//军队序号
	Dogface dogface[armyLength];	//小兵
	int top;						//栈顶
}Army;

/*英雄*/
typedef struct {
	Attribute attribute;			//属性
	Army army;						//军队
	char name[nameLength];			//名字
}Hero;