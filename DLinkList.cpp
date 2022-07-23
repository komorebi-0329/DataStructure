//˫����(��ͷ�ڵ�)
#include<stdio.h>
#include<stdlib.h>
//����˫����
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

//����
bool InitDLinklist(DLinkList& L);//��ʼ��˫����
bool Empty(DLinkList L);//�жϱ��Ƿ�Ϊ��
bool InsertNextDNode(DNode* p, DNode* s);//��p�ڵ�����s
bool DeleteNextDNode(DNode* p);//ɾ��p�ڵ���q�ڵ�
void DestoryList(DLinkList& L);//����˫����
void BTraversal(DLinkList L);//������˫����
void FTraversal(DNode* p);// �����ǰ����(����ͷ���)


//int main()
//{
//	DLinkList L;
//	InitDLinklist(L);
//
//	if (Empty(L))
//		printf("˫����Ϊ��");
//	else
//		printf("˫����ǿ�");
//
//}

bool InitDLinklist(DLinkList &L)//��ʼ��˫����
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	L->prior = NULL;
	return true;
}	


bool Empty(DLinkList L)//�жϱ��Ƿ�Ϊ��
{
	if (L->prior == NULL)
		return true;
	else
		return false;
}


bool InsertNextDNode(DNode* p, DNode* s)//��p�ڵ�����s
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


bool DeleteNextDNode(DNode* p)//ɾ��p�ڵ���q�ڵ�
{
	if (p == NULL)
		return false;
	DNode* q = p->next; //ָ��qָ��p->next��
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next!=NULL)
		q->next->prior = p;
	free(q);
	return true;
}


void DestoryList(DLinkList &L)//����˫����
{
	while (L->next!=NULL)
		DeleteNextDNode(L);
	free(L);
	L = NULL;
}


void BTraversal(DLinkList L)//������˫����
{
	while (L->next!=NULL)
	{
		printf("%d", L->next->data);
		L = L->next;
	}
}

void FTraversal(DNode *p)//�����ǰ����(����ͷ���)
{
	while (p->prior != NULL)
	{
		printf("%d", p->prior->data);
		p = p->next;
	}
}


