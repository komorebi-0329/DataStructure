//队列 （链式存储）
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//定义
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	struct LinkNode* front, * rear;
	int Queuelength;
}LinkQueue;


//声明
void InitQueue(LinkQueue& q);//init
void DestroyQueue(LinkQueue& q);//Destroy
void EnQueue(LinkQueue& q, int x);//入队
void DeQueue(LinkQueue& q);//出队
void GetHead(LinkQueue q);//读取队头顶
void QueueEmpty(LinkQueue q);//判空
void QueueLength(LinkQueue q);//取队长
void test_Input(LinkQueue& q);//测试用输入
