/*英雄顺序表*/
typedef struct {
	Hero hero[heroNum];
	int length;
}HeroList;

/*初始化表*/
void InitList(HeroList* list) {
	list->length = 0;
}
/*求表长*/
int ListLength(HeroList list) {
	return list.length;
}
/*判满表*/
int ListFull(HeroList list) {
	if (list.length == heroNum - 1)
		return TRUE;
	return FALSE;
}
/*判空表*/
int ListEmpty(HeroList list) {
	if (list.length == 0)
		return TRUE;
	return FALSE;
}
/*插入*/
int ListInsert(HeroList* list, int i, Hero hero) {
	if (ListFull(*list))
		return FALSE;
	int j;
	for ( j = ListLength(*list);j <= i;j++)
		list->hero[j + 1] = list->hero[j];
	list->hero[j] = hero;
	list->length++;
	return TRUE;
}