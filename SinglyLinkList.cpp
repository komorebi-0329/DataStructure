//������(��ͷ���)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//����
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


//��������
bool InitList(LinkList& L);//��ʼ�� 
LinkList List_TailInsert(LinkList& L);// β�巨����������
LinkList List_HeadInsert(LinkList& L); //ͷ�巨��������
bool InserNextNode(LNode* p, int e);//ָ���ڵ���
LNode* GetElem(LinkList L, int i);//��λ����  
bool ListInsert(LinkList& L, int i, int e);//��λ����  �ڵ�i-1���ڵ�����ڵ�e
bool InserPriorNode(LNode* p, int e);//ָ���ڵ�ǰ��
bool ListDelete(LinkList& L, int i, int& e);//��λɾ�� ɾ����i�Ľ�㲢��Ԫ��e����
bool DeleteNode(LNode* p);//ɾ��ָ���ڵ�
LNode* LocateElem(LinkList L, int e);//��ֵ���� ��L������Ϊe�Ľ�㷵��
int Length(LinkList L);//���



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



bool InitList(LinkList& L)//��ʼ�� 
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}

LinkList List_TailInsert(LinkList& L)// β�巨����������
{
	int x;		//�������
	InitList(L);
	LNode* s, * r = L;              //*rΪ��ͷָ��
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


LinkList List_HeadInsert(LinkList& L) //ͷ�巨��������
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

bool InserNextNode(LNode* p, int e)//ָ���ڵ���
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;	//�ڴ����ʧ��
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

LNode* GetElem(LinkList L, int i)//��λ����  
{
	if (i < 0)
		return NULL;
	LNode* p;		//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;		//��ǰָ����ǵڼ������
	p = L;			//Lָ��ͷ��㣬ͷ����ǵ�0���ڵ㣨�������ݣ�
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(LinkList& L, int i, int e)//��λ����  �ڵ�i-1���ڵ�����ڵ�e
{
	if (i < 1)
		return false;
	LNode* p = GetElem(L, i - 1);//��λ����  
	return(InserNextNode(p, e));
}


bool InserPriorNode(LNode* p, int e)//ָ���ڵ�ǰ��
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


bool ListDelete(LinkList& L, int i, int& e)//��λɾ�� ɾ����i�Ľ�㲢��Ԫ��e����
{
	if (i < 1)
		return false;
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next = NULL)	//��i-1���ڵ��Ѿ�û�������ڵ�
		return false;
	LNode* q = p->next;	//��ڵ�qָ��ɾ���ڵ�
	e = q->data;		//��ɾ���ڵ�����ݴ��ص�e
	p->next = q->next;	//���ڵ�ָ��ָ��ɾ���ڵ����һ���ڵ�
	free(q);			//�ͷ�ɾ���Ľ�㡤
	return true;
}

bool DeleteNode(LNode* p) //ɾ��ָ���ڵ�
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


LNode* LocateElem(LinkList L, int e)//��ֵ���� ��L������Ϊe�Ľ�㷵��
{
	LNode* p = L->next; //��ָ��pָ��L��ͷ��� 
	while (p != NULL && L->data != e)
	{
		p = p->next;
	}
	return p; //�ҵ��󷵻ؽ��ָ�룬���򷵻�null
}

int Length(LinkList L)//���
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

