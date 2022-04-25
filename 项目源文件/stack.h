/*敌方军队*/
typedef struct {
	Dogface dogface[armyLength];	//小兵
	int top;						//栈顶
}Army;

/*初始化栈*/
void InitStack(Army* army) {
	army->top = -1;
}
/*求栈长*/
int StackLength(Army army) {
	return army.top + 1;
}
/*判满栈*/
int StackFull(Army army) {
	if (army.top == armyLength - 1)
		return TRUE;
	return FALSE;
}
/*判空栈*/
int StackEmpty(Army army) {
	if (army.top == -1)
		return TRUE;
	return FALSE;
}
/*入栈*/
int StackInsert(Army* army) {
	
}
