#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define Elemtype int 
using namespace std;


//����
typedef struct LinkNode {
	Elemtype data;
	struct LinkNode* next;
	int top;
}LinkNode;

typedef struct StackTop{
	LinkNode* top;
	int Stacklength;
}*LiStack;



//����
bool InitStack(LiStack& L);//��ʼ����ջ
void DestroyStack(LiStack& L);//ע����ջ
bool Push(LiStack& L, int x);//��ջ
bool Pop(LiStack& L, int& x);//��ջ
void  GetTop(LiStack& L);//��ȡջ��
void StackEmpty(LiStack& L);//�жϿ�ջ
void StackLength(LiStack& L);//��ջ��