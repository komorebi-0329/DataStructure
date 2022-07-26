//���У�˳��洢��
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"06-SqQueue.h"
using namespace std;



//int main()
//{
//	int a, b;
//	SqQueue Q;
//	InitQueue(Q);
//	test_Scanf(Q);
//	DeQueue(Q, a);
//	cout << "dequeue num is\t" << a << endl;
//	GetHead(Q);
//	if (QueueEmpty(Q))
//		cout << "this queue is null\t" << endl;
//	else
//		cout << "this queue is no null\t" << endl;
//	 b = QueueLength(Q);	
//	 cout << "this queue len is" << b << endl;
//	DestroyQueue(Q);
//	GetHead(Q);
//	if (QueueEmpty(Q))
//		cout << "this queue is null\t" << endl;
//	else
//		cout << "this queue is no null\t" << endl;
//	b = QueueLength(Q);
//	cout << "this queue len is" << b << endl;
//}


bool InitQueue(SqQueue& Q)//��ʼ��
{
	Q.front = Q.rear = 0;
	Q.size = 0;
	return true;
}


void DestroyQueue(SqQueue& Q)//ע��
{
	Q.front = Q.rear = Q.size = 0;
	cout << "success DestroyQueue" << endl;
}
bool EnQueue(SqQueue& Q, int x)//���
{
	if (Q.size == MAXSIZE)
		return false;		//��������
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1)%MAXSIZE;//����ѭ������
	Q.size++;
	return true;
}


bool DeQueue(SqQueue& Q, int& x)//����
{
	if (Q.size == 0)
		return false; //�ö���Ϊ��
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}


void GetHead(SqQueue& Q)//��ȡ��ͷ��
{
	if (Q.size == 0)
	{
		cout << "this Queue is NULL" << endl;
		return;
	}
	int x = Q.data[Q.front];
	cout << "this QueueHead num is" << x << endl;
}


bool QueueEmpty(SqQueue& Q)//�п�
{
	if (Q.size == 0)
		return true;
	else
		return false;
}


int QueueLength(SqQueue& Q)//ȡ�ӳ�
{
	return Q.size;
}

void test_Scanf(SqQueue &Q)
{
	int a=0;
	while (a!=999)
	{
		cout << "������Ҫ��ӵ�Ԫ��:(999����):\t";
		cin >> a;
		if (a == 999)
			return;
		if (EnQueue(Q, a))
			cout << "��ӳɹ�" << endl;
		else
			cout << "��������" << endl;
	}	
}