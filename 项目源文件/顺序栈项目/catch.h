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
