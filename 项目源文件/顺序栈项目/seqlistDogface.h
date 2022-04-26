Dogface catchDogface(int);
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
	for (j = DogfaceLength(*list);j > i;j++)
		list->dogface[j + 1] = list->dogface[j];
	list->dogface[j] = dogface;
	list->length++;
	return TRUE;
}

/*排序*/
void DogfaceSeq(DogfaceList* list) {
	Dogface temp;
	for (int i = 0;i < list->length;i++)
		for (int j = i + 1;j < list->length;j++)
			if (list->dogface[j].ID < list->dogface[i].ID) {
				temp = list->dogface[i];
				list->dogface[i] = list->dogface[j];
				list->dogface[j] = temp;
			}
}
/*删除*/
Dogface DogfaceDelete(DogfaceList* list, int i) {
	Dogface out = list->dogface[i - 1];
	list->dogface[i - 1] = catchDogface(0);
	return out;
}
/*获得英雄*/
void getDogface(Player* player, int i) {
	DogfaceInsert(&player->ownDogface, 0, DogfaceDelete(&player->unDogface, i));
	DogfaceSeq(&player->ownDogface);
}