//队列（顺序存储）
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


bool InitQueue(SqQueue& Q)//初始化
{
	Q.front = Q.rear = 0;
	Q.size = 0;
	return true;
}


void DestroyQueue(SqQueue& Q)//注销
{
	Q.front = Q.rear = Q.size = 0;
	cout << "success DestroyQueue" << endl;
}
bool EnQueue(SqQueue& Q, int x)//入队
{
	if (Q.size == MAXSIZE)
		return false;		//队列已满
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1)%MAXSIZE;//构成循环队列
	Q.size++;
	return true;
}


bool DeQueue(SqQueue& Q, int& x)//出队
{
	if (Q.size == 0)
		return false; //该队列为空
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}


void GetHead(SqQueue& Q)//读取队头顶
{
	if (Q.size == 0)
	{
		cout << "this Queue is NULL" << endl;
		return;
	}
	int x = Q.data[Q.front];
	cout << "this QueueHead num is" << x << endl;
}


bool QueueEmpty(SqQueue& Q)//判空
{
	if (Q.size == 0)
		return true;
	else
		return false;
}


int QueueLength(SqQueue& Q)//取队长
{
	return Q.size;
}

void test_Scanf(SqQueue &Q)
{
	int a=0;
	while (a!=999)
	{
		cout << "请输入要入队的元素:(999结束):\t";
		cin >> a;
		if (a == 999)
			return;
		if (EnQueue(Q, a))
			cout << "入队成功" << endl;
		else
			cout << "队列已满" << endl;
	}	
}