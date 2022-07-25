//顺序栈
#define MaxSize 10
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


//定义顺序栈
typedef struct {
	int data[MaxSize];
	int top;
}Sqstack;

//声明
bool InitStack(Sqstack&L);//初始化顺序栈
bool DestroyStack(Sqstack&L);//注销顺序栈
bool Push(Sqstack& L, int x);//进栈
bool Pop(Sqstack& L, int& x);//出栈
void  GetTop(Sqstack& L);//读取栈顶
bool StackEmpty(Sqstack& L);//判断空栈
void PrintfStack(Sqstack& L);//遍历
void StackLength(Sqstack& L);//求栈长



int main()
{
	Sqstack t;
	InitStack(t);
	Push(t,1);//进栈
	Push(t, 2);//进栈
	Push(t, 3);//进栈
	Push(t, 4);//进栈
	Push(t, 5);//进栈
	PrintfStack(t);
	GetTop(t);
	StackLength(t);
	int x=0;
	if (Pop(t, x))
		cout << "success 被出栈的元素为"<<x<< endl;
	else
		cout << "fail" << endl;
	GetTop(t);
	
	DestroyStack(t);
	StackLength(t);
	if (StackEmpty(t))
		cout << "this stack is NULL" << endl;
	else
		cout << "This Stack have num" << endl;
}



bool InitStack(Sqstack& L)//初始化顺序栈
{
	L.top = -1;
	return true;
}


bool DestroyStack(Sqstack& L)//注销顺序栈
{
	L.top = -1;		//从逻辑上销毁顺序栈 物理内存中仍然保存数据，当系统结束后一并销毁
	return true;
}


bool Push(Sqstack& L, int x)//进栈
{
	if (L.top == MaxSize)
		return false;	
	L.top = L.top + 1;
	L.data[L.top] = x;
	return true;
}


bool Pop(Sqstack& L, int& x)//出栈
{
	if (L.top == -1)
		return false;
	x = L.data[L.top];
	L.top = L.top - 1;
	// x=L.data[L.top--];
	return true;
}


void  GetTop(Sqstack& L)//读取栈顶
{
	if (L.top == -1)
		cout << "此栈为空"<< endl;
	int a = L.data[L.top];
	cout << "此时栈顶元素为" << a << endl;
}


bool StackEmpty(Sqstack& L)//判断空栈
{
	if (L.top = -1)
		return true;
	else
		return false;
}

void PrintfStack(Sqstack& L)//遍历
{
	for (int  i = 0; i <MaxSize; i++)
	{		
		printf("Stack中第%d个元素为%d\n", i, L.data[i]);
	}
}

void StackLength(Sqstack& L)//栈长
{
	if (L.top == 0)
		cout << "空栈" << endl;
	int a;
	a= L.top+1;
	cout << "此时栈长为" << a << endl;
}
