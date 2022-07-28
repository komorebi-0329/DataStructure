//队列 （链式存储）
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



void InitQueue(LinkQueue& q)//init(带头节点)
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
	cout << "该队列已经被注销" << endl;
}


void EnQueue(LinkQueue& q, int x)//入队
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)
		cout << "内存不足" << endl;
	p->data = x;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.Queuelength++;
	cout<<"入队成功"<< endl;
}


void DeQueue(LinkQueue& q)//出队
{
	int a;
	if (q.front == q.rear)
	{
		cout << "这个队列为空" << endl;
		return;
	}
	LinkNode* p = q.front->next; //头结点的下一个节点
	a = p->data;	//赋值
	q.front->next = p->next;//连接节点
	if (q.rear==p)	//if这个节点是最后一个节点
		q.rear = q.front;	//队头队尾指针都指向头节点
	q.Queuelength--;
	free(p);
	cout << "出队成功,出队的数据为："<<a << endl;
}


void GetHead(LinkQueue q)//读取队头顶
{
	cout <<"此时队头为：" <<q.front->next->data << endl;
}


void QueueEmpty(LinkQueue q)//判空(带头)
{
	if (q.front == q.rear)
		cout << "队列为空" << endl;
	else
		cout << "队列非空 " << endl;
}


void QueueLength(LinkQueue q)//取队长
{
	cout << "此队列长度为：" << q.Queuelength << endl;
}

void test_Input(LinkQueue& q)
{
	int a=NULL;
	while (a!=999)
	{
		cout << "请输入入队数据：（999结束）" << endl;
		cin >> a;
		if (a == 999)
			return;
		EnQueue(q, a);
	}
}

