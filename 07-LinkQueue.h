//���� ����ʽ�洢��
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//����
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	struct LinkNode* front, * rear;
	int Queuelength;
}LinkQueue;


//����
void InitQueue(LinkQueue& q);//init
void DestroyQueue(LinkQueue& q);//Destroy
void EnQueue(LinkQueue& q, int x);//���
void DeQueue(LinkQueue& q);//����
void GetHead(LinkQueue q);//��ȡ��ͷ��
void QueueEmpty(LinkQueue q);//�п�
void QueueLength(LinkQueue q);//ȡ�ӳ�
void test_Input(LinkQueue& q);//����������
