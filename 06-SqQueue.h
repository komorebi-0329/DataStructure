//˳���
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXSIZE 10
using namespace std;


//����
typedef struct  SqQueue {
	int data[MAXSIZE];
	int front, rear; //��ͷָ�룬��βָ��
	int size;
}SqQueue;




//����
bool InitQueue(SqQueue& Q);//��ʼ��
void DestroyQueue(SqQueue& Q);//ע��
bool EnQueue(SqQueue& Q, int x);//���
bool DeQueue(SqQueue& Q, int& x);//����
void GetHead(SqQueue& Q);//��ȡ��ͷ��
bool QueueEmpty(SqQueue& Q);//�п�
int QueueLength(SqQueue& Q);//ȡ�ӳ�
void test_Scanf(SqQueue& Q);//�������