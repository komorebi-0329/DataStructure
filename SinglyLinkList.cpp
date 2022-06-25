#define _CRT_SECURE_NO_WARNINGS
//单链表(带头结点)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//定义
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


//声明函数
bool InitList(LinkList& L);//初始化 
LinkList List_TailInsert(LinkList& L);// 尾插法创建单链表
LinkList List_HeadInsert(LinkList& L); //头插法创建链表
bool InserNextNode(LNode* p, int e);//指定节点后插
LNode* GetElem(LinkList L, int i);//按位查找  
bool ListInsert(LinkList& L, int i, int e);//按位插入  在第i-1个节点后插入节点e
bool InserPriorNode(LNode* p, int e);//指定节点前插
bool ListDelete(LinkList& L, int i, int& e);//按位删除 删除第i的结点并将元素e带回
bool DeleteNode(LNode* p);//删除指定节点
LNode* LocateElem(LinkList L, int e);//按值查找 将L链表中为e的结点返回
int Length(LinkList L);//求表长



//int main()
//{
//	LinkList L;
//	List_TailInsert(L);
//	//List_HeadInsert(L);
//	LNode* x = GetElem(L, 3);
//	printf("%d\n", x->data);
//	InserPriorNode(x, 998999);
//	LNode* y = GetElem(L, 2);
//	printf("%d\n", y->data);
//	printf("%d\n", y->next->data);
//}



bool InitList(LinkList& L)//初始化 
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}

LinkList List_TailInsert(LinkList& L)// 尾插法创建单链表
{
	int x;		//输入变量
	InitList(L);
	LNode* s, * r = L;              //*r为表头指针
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}


LinkList List_HeadInsert(LinkList& L) //头插法创建链表
{
	LNode* s;
	int x;
	InitList(L);
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

bool InserNextNode(LNode* p, int e)//指定节点后插
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;	//内存分配失败
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

LNode* GetElem(LinkList L, int i)//按位查找  
{
	if (i < 0)
		return NULL;
	LNode* p;		//指针p指向当前扫描到的结点
	int j = 0;		//当前指向的是第几个结点
	p = L;			//L指向头结点，头结点是第0个节点（不存数据）
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(LinkList& L, int i, int e)//按位插入  在第i-1个节点后插入节点e
{
	if (i < 1)
		return false;
	LNode* p = GetElem(L, i - 1);//按位查找  
	return(InserNextNode(p, e));
}


bool InserPriorNode(LNode* p, int e)//指定节点前插
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}


bool ListDelete(LinkList& L, int i, int& e)//按位删除 删除第i的结点并将元素e带回
{
	if (i < 1)
		return false;
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next = NULL)	//第i-1个节点已经没有其他节点
		return false;
	LNode* q = p->next;	//另节点q指向删除节点
	e = q->data;		//将删除节点的数据带回到e
	p->next = q->next;	//将节点指针指向删除节点的下一个节点
	free(q);			//释放删除的结点·
	return true;
}

bool DeleteNode(LNode* p) //删除指定节点
{
	if (p == NULL)
		return false;
	LNode* q = p->next;
	if (p->next == NULL)
		return false;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true;
}


LNode* LocateElem(LinkList L, int e)//按值查找 将L链表中为e的结点返回
{
	LNode* p = L->next; //将指针p指向L的头结点 
	while (p != NULL && L->data != e)
	{
		p = p->next;
	}
	return p; //找到后返回结点指针，否则返回null
}

int Length(LinkList L)//求表长
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

