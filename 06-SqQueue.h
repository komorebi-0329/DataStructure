//顺序队
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXSIZE 10
using namespace std;


//定义
typedef struct  SqQueue {
	int data[MAXSIZE];
	int front, rear; //队头指针，队尾指针
	int size;
}SqQueue;




//声明
bool InitQueue(SqQueue& Q);//初始化
void DestroyQueue(SqQueue& Q);//注销
bool EnQueue(SqQueue& Q, int x);//入队
bool DeQueue(SqQueue& Q, int& x);//出队
void GetHead(SqQueue& Q);//读取队头顶
bool QueueEmpty(SqQueue& Q);//判空
int QueueLength(SqQueue& Q);//取队长
void test_Scanf(SqQueue& Q);//测试入队