/*获取小兵属性*/
Attribute catchAttribute(int i) {
	/*属性列表*/
	Attribute aError = {-1,-1,-1,-1};
	Attribute a1 = { 100,10,10,10 };
	/*返回属性*/
	switch (i) {
	case 1:return a1;
	default:return aError;
	}
}
/*获取小兵*/
Dogface catchDogface(int i) {
	/*小兵列表*/
	Dogface dError = { catchAttribute(-1),-1,-1 };
	Dogface d1 = { catchAttribute(1),1,10 };
	/*返回小兵*/
	switch (i) {
	case 1:return d1;
	default:return dError;
	}
}
/*获取英雄*/
Hero catchHero(int i) {
	/*英雄列表*/
	Hero hError = {-1,-1,ERROR,-1};
	Hero h1 = { 1,1,"胡桃",100};
	Hero h2 = { 2,2,"辽宁跑男",200 };
	Hero h3 = {3,3,"三姓家奴",300};
	/*返回英雄*/
	switch (i) {
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	default:return hError;
	}
}