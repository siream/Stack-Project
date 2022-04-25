#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"
#include "struct.h"
#include "UI.h"
#include "seqlist.h"
#include "stack.h"

int main() {
	system("mode con cols=120 lines=40");		//设定控制台大小
	SetCursor(FALSE);								//隐藏光标
	Player player = Ready();									//开始界面
	Menu(&player);
}

