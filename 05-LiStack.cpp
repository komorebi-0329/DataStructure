#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"05-LiStack.h"

using namespace std;

int main()
{
	LiStack L;
	InitStack(L);
	Push(L, 1);
	Push(L, 2);
	Push(L, 3);
	Push(L, 4);
	Push(L, 5);
	GetTop(L);
	StackEmpty(L);
	StackLength(L);
	int a;
	Pop(L, a);
	cout << "被出栈的数为" << a << endl;
	GetTop(L);
	DestroyStack(L);
	StackEmpty(L);
	StackLength(L);
}


bool InitStack(LiStack& L)//初始化链栈
{
	L = (LiStack)malloc(sizeof(StackTop));
	if (L == NULL)
		return false;
	L->top = NULL;
	L->Stacklength = 0;
	return true;
}


void DestroyStack(LiStack& L)//注销链栈
{
	while (L->top!=NULL)
	{
		int x;
		Pop(L, x);
		cout << "被出栈的元素为" << x << endl;
	}
	cout << "链栈已被注销" << endl;
}


bool Push(LiStack& L, int x)//进栈
{
	LinkNode *tem = (LinkNode*)malloc(sizeof(LinkNode));
	if (tem == NULL)
		return false;
	tem->data = x;
	tem->next = L->top;
	L->top = tem;
	L->Stacklength++;
}


bool Pop(LiStack& L, int& x)//出栈
{
	LinkNode* p;
	if (L->top == NULL)
		return false;
	x = L->top->data;
	p = L->top;
	L->top = p->next;
	free(p);
	L->Stacklength--;
	return true;
}


void  GetTop(LiStack& L)//读取栈顶
{
	if (L->top == NULL)
		cout << "now Stack is null" << endl;
	int tem = L->top->data;
	cout << "now StackTop is " << tem << endl;
}


void StackEmpty(LiStack& L)//判断空栈
{
	if (L->top == NULL)
		cout << "this stack is null" << endl;
	else
		cout << "this stack is no null" << endl;
}


void StackLength(LiStack& L)//求栈长
{
	int tem = L->Stacklength;
	cout << "此时栈长为：" << tem << endl;
}