//���� ����ʽ�洢��
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"07-LinkQueue.h"
using namespace std;


int main()
{
	LinkQueue q;
	InitQueue(q);
	test_Input(q);
	
	GetHead(q);
	DeQueue(q);
	GetHead(q);
	
	QueueLength(q);
	
	DeQueue(q);
	
	QueueEmpty(q);
	DestroyQueue(q);
	QueueEmpty(q);
	QueueLength(q);
}



void InitQueue(LinkQueue& q)//init(��ͷ�ڵ�)
{
	q.front =q.rear= (LinkNode*)malloc(sizeof(LinkNode));
	q.front->next = NULL;
	q.Queuelength = 0;
}


void DestroyQueue(LinkQueue& q)//Destroy
{
	while (q.front!=q.rear)
	{
		DeQueue(q);
	}
	cout << "�ö����Ѿ���ע��" << endl;
}


void EnQueue(LinkQueue& q, int x)//���
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)
		cout << "�ڴ治��" << endl;
	p->data = x;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.Queuelength++;
	cout<<"��ӳɹ�"<< endl;
}


void DeQueue(LinkQueue& q)//����
{
	int a;
	if (q.front == q.rear)
	{
		cout << "�������Ϊ��" << endl;
		return;
	}
	LinkNode* p = q.front->next; //ͷ������һ���ڵ�
	a = p->data;	//��ֵ
	q.front->next = p->next;//���ӽڵ�
	if (q.rear==p)	//if����ڵ������һ���ڵ�
		q.rear = q.front;	//��ͷ��βָ�붼ָ��ͷ�ڵ�
	q.Queuelength--;
	free(p);
	cout << "���ӳɹ�,���ӵ�����Ϊ��"<<a << endl;
}


void GetHead(LinkQueue q)//��ȡ��ͷ��
{
	cout <<"��ʱ��ͷΪ��" <<q.front->next->data << endl;
}


void QueueEmpty(LinkQueue q)//�п�(��ͷ)
{
	if (q.front == q.rear)
		cout << "����Ϊ��" << endl;
	else
		cout << "���зǿ� " << endl;
}


void QueueLength(LinkQueue q)//ȡ�ӳ�
{
	cout << "�˶��г���Ϊ��" << q.Queuelength << endl;
}

void test_Input(LinkQueue& q)
{
	int a=NULL;
	while (a!=999)
	{
		cout << "������������ݣ���999������" << endl;
		cin >> a;
		if (a == 999)
			return;
		EnQueue(q, a);
	}
}

