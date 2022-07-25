#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define Elemtype int 
using namespace std;


//定义
typedef struct LinkNode {
	Elemtype data;
	struct LinkNode* next;
	int top;
}LinkNode;

typedef struct StackTop{
	LinkNode* top;
	int Stacklength;
}*LiStack;



//声明
bool InitStack(LiStack& L);//初始化链栈
void DestroyStack(LiStack& L);//注销链栈
bool Push(LiStack& L, int x);//进栈
bool Pop(LiStack& L, int& x);//出栈
void  GetTop(LiStack& L);//读取栈顶
void StackEmpty(LiStack& L);//判断空栈
void StackLength(LiStack& L);//求栈长