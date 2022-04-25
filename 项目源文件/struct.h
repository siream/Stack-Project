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

/*英雄*/
typedef struct {
	int	ID;							//英雄ID
	char name[nameLength];			//名字
}Hero;

/*玩家*/
typedef struct {
	char name[nameLength];			//玩家名称
	int gold;						//玩家金币

}Player;