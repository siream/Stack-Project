/*初始化表*/
void InitHero(HeroList* list) {
	list->length = 0;
}
/*求表长*/
int HeroLength(HeroList list) {
	return list.length;
}
/*判满表*/
int HeroFull(HeroList list) {
	if (list.length == heroNum)
		return TRUE;
	return FALSE;
}
/*判空表*/
int HeroEmpty(HeroList list) {
	if (list.length == 0)
		return TRUE;
	return FALSE;
}
/*插入*/
int HeroInsert(HeroList* list, int i, Hero hero) {
	if (HeroFull(*list))
		return FALSE;
	int j;
	for (j = HeroLength(*list);j <= i;j++)
		list->hero[j + 1] = list->hero[j];
	list->hero[j] = hero;
	list->length++;
	return TRUE;
}


/*初始化表*/
void InitDogface(DogfaceList* list) {
	list->length = 0;
}
/*求表长*/
int DogfaceLength(DogfaceList list) {
	return list.length;
}
/*判满表*/
int DogfaceFull(DogfaceList list) {
	if (list.length == dogfaceNum)
		return TRUE;
	return FALSE;
}
/*判空表*/
int DogfaceEmpty(DogfaceList list) {
	if (list.length == 0)
		return TRUE;
	return FALSE;
}
/*插入*/
int DogfaceInsert(DogfaceList* list, int i, Dogface dogface) {
	if (DogfaceFull(*list))
		return FALSE;
	int j;
	for (j = DogfaceLength(*list);j <= i;j++)
		list->dogface[j + 1] = list->dogface[j];
	list->dogface[j] = dogface;
	list->length++;
	return TRUE;
}