//��ջ
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"05-LiStack.h"

using namespace std;

//int main()
//{
//	LiStack L;
//	InitStack(L);
//	Push(L, 1);
//	Push(L, 2);
//	Push(L, 3);
//	Push(L, 4);
//	Push(L, 5);
//	GetTop(L);
//	StackEmpty(L);
//	StackLength(L);
//	int a;
//	Pop(L, a);
//	cout << "����ջ����Ϊ" << a << endl;
//	GetTop(L);
//	DestroyStack(L);
//	StackEmpty(L);
//	StackLength(L);
//}


bool InitStack(LiStack& L)//��ʼ����ջ
{
	L = (LiStack)malloc(sizeof(StackTop));
	if (L == NULL)
		return false;
	L->top = NULL;
	L->Stacklength = 0;
	return true;
}


void DestroyStack(LiStack& L)//ע����ջ
{
	while (L->top!=NULL)
	{
		int x;
		Pop(L, x);
		cout << "����ջ��Ԫ��Ϊ" << x << endl;
	}
	cout << "��ջ�ѱ�ע��" << endl;
}


bool Push(LiStack& L, int x)//��ջ
{
	LinkNode *tem = (LinkNode*)malloc(sizeof(LinkNode));
	if (tem == NULL)
		return false;
	tem->data = x;
	tem->next = L->top;
	L->top = tem;
	L->Stacklength++;
}


bool Pop(LiStack& L, int& x)//��ջ
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


void  GetTop(LiStack& L)//��ȡջ��
{
	if (L->top == NULL)
		cout << "now Stack is null" << endl;
	int tem = L->top->data;
	cout << "now StackTop is " << tem << endl;
}


void StackEmpty(LiStack& L)//�жϿ�ջ
{
	if (L->top == NULL)
		cout << "this stack is null" << endl;
	else
		cout << "this stack is no null" << endl;
}


void StackLength(LiStack& L)//��ջ��
{
	int tem = L->Stacklength;
	cout << "��ʱջ��Ϊ��" << tem << endl;
}