Hero catchHero(int);

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
	for (j = HeroLength(*list)-1;j > i-1;j--)
		list->hero[j+1] = list->hero[j];
	list->hero[i] = hero;
	list->length++;
	return TRUE;
}

/*排序*/
void HeroSeq(HeroList* list) {
	if (HeroEmpty(*list))
		return;
	Hero temp;
	for (int i = 0;i < list->length;i++)
		for (int j = i + 1;j < list->length;j++) {
			if (list->hero[j].ID < list->hero[i].ID) {
				temp = list->hero[i];
				list->hero[i] = list->hero[j];
				list->hero[j] = temp;
			}
			if (list->hero[i].ID==0) {
				temp = list->hero[i];
				list->hero[i] = list->hero[j];
				list->hero[j] = temp;
			}
		}
}
/*删除*/
Hero HeroDelete(HeroList* list, int i) {
	Hero out = list->hero[i - 1];
	list->hero[i - 1] = catchHero(0);
	HeroSeq(list);
	list->length--;
	return out;
}
/*获得兵种*/
int getHero(Player* player, int i) {
	HeroInsert(&player->ownHero, 0, HeroDelete(&player->unHero, i));
	HeroSeq(&player->ownHero);
	return 0;
}