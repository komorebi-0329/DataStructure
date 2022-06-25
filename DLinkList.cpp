//双链表(带头节点)
#include<stdio.h>
#include<stdlib.h>
//定义双链表
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

//声明
bool InitDLinklist(DLinkList& L);//初始化双链表
bool Empty(DLinkList L);//判断表是否为空
bool InsertNextDNode(DNode* p, DNode* s);//在p节点后插入s
bool DeleteNextDNode(DNode* p);//删除p节点后的q节点
void DestoryList(DLinkList& L);//销毁双链表
void BTraversal(DLinkList L);//向后遍历双链表
void FTraversal(DNode* p);// 结点向前遍历(跳过头结点)


//int main()
//{
//	DLinkList L;
//	InitDLinklist(L);
//
//	if (Empty(L))
//		printf("双链表为空");
//	else
//		printf("双链表非空");
//
//}

bool InitDLinklist(DLinkList &L)//初始化双链表
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	L->prior = NULL;
	return true;
}	


bool Empty(DLinkList L)//判断表是否为空
{
	if (L->prior == NULL)
		return true;
	else
		return false;
}


bool InsertNextDNode(DNode* p, DNode* s)//在p节点后插入s
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next!=NULL)
	{
		p->next->prior = s;
	}
	s->prior = p;	
	p->next = s;
	return true;
}


bool DeleteNextDNode(DNode* p)//删除p节点后的q节点
{
	if (p == NULL)
		return false;
	DNode* q = p->next; //指针q指向p->next；
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next!=NULL)
		q->next->prior = p;
	free(q);
	return true;
}


void DestoryList(DLinkList &L)//销毁双链表
{
	while (L->next!=NULL)
		DeleteNextDNode(L);
	free(L);
	L = NULL;
}


void BTraversal(DLinkList L)//向后遍历双链表
{
	while (L->next!=NULL)
	{
		printf("%d", L->next->data);
		L = L->next;
	}
}

void FTraversal(DNode *p)//结点向前遍历(跳过头结点)
{
	while (p->prior != NULL)
	{
		printf("%d", p->prior->data);
		p = p->next;
	}
}


