/*获取小兵属性*/
Attribute catchAttribute(int i) {
	/*属性列表*/
	/*生命值，攻击力，防御力，造价*/
	Attribute aError = { -1,-1,-1,-1 };
	Attribute a0 = { 0,0,0,0 };
	Attribute a1 = { 100,10,10,10 };
	Attribute a2 = { 200,10,10,10 };
	Attribute a3 = { 200,20,20 ,20 };
	/*返回属性*/
	switch (i) {
	case 0:return a0;
	case 1:return a1;
	case 2:return a2;
	case 3:return a3;
	default:return aError;
	}
}
/*获取小兵*/
Dogface catchDogface(int i) {
	/*小兵列表*/
	/*属性，ID，商店价格*/
	Dogface dError = { catchAttribute(-1),-1,-1 };
	Dogface d0 = { catchAttribute(0),0,0 };
	Dogface d1 = { catchAttribute(1),1,100 };
	Dogface d2 = { catchAttribute(2),2,200 };
	Dogface d3 = { catchAttribute(3),3,300 };
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
	/*英雄ID，技能ID，名字，商店价格*/
	Hero hError = { -1,-1,ERROR,-1 };
	Hero h0 = { 0,0,"NULL",0 };
	Hero h1 = { 1,1,"胡桃",100 };
	Hero h2 = { 2,2,"辽宁跑男",200 };
	Hero h3 = { 3,3,"三姓家奴",300 };
	/*返回英雄*/
	switch (i) {
	case 0:return h0;
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	default:return hError;
	}
}