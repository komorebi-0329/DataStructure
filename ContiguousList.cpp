//��̬˳���
#include <stdio.h>
#include<stdlib.h>
#define InitSize 10

//����
typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;


//��������
void InitList(SeqList& L);//��ʼ��
void  IncreaseSize(SeqList& L, int len);//��̬��չ
bool ListInsert(SeqList& L, int i, int e); //��λ����   ��˳���L�еĵ�i��λ�ò�������e
bool ListDelete(SeqList& L, int i, int& e);//��λɾ������ɾ����Ԫ�ط���
int GetElem(SeqList L, int i);//��λ����
int LocateElem(SeqList L, int e);//��ֵ����  iΪ��ֵ��eΪλ��



//int main()
//{
//	SeqList L;
//	InitList(L);
//	IncreaseSize(L, 5);
//	
//	for (int i = 0; i < 10; i++)
//	{
//		L.data[i] = i + 1;
//		L.length++;
//	}
//	
//	ListInsert(L, 1, 8);
//	
//	for (int i = 0; i < 15; i++)
//	{
//		printf("˳����е�%d��Ԫ��Ϊ%d\n", i+1, L.data[i]);
//	}
//	int e = -1;
//	if (ListDelete(L, 1, e))
//	{
//		printf("Delete num is %d\n", e);
//	}
//	else
//	{
//		printf("Delete fail\n");
//	}
//		
//	for (int i = 0; i < 15; i++)
//	{
//		printf("˳����е�%d��Ԫ��Ϊ%d\n", i + 1, L.data[i]);
//	}
//	int o=GetElem(L, 1);
//	printf("%d\n",o);
//
//	int a = LocateElem(L, 99);
//	if (a == 0)
//		printf("fail");
//	else
//		printf("��%d��Ԫ��Ϊ8",a);
//	return 0;
//}



void InitList(SeqList& L)//��ʼ��
{
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}


void  IncreaseSize(SeqList& L, int len)//��̬��չ
{
	int* p = L.data;//ָ��pָ��˳���L
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}

bool ListInsert(SeqList& L, int i, int e) //��λǰ�ò���(������Ԫ������ƶ�)��˳���L�еĵ�i��λ��ǰ������e
{
	if (i<1 || i>L.length + 1) //�Ƿ�����
		return false;
	if (L.length >=L.MaxSize)  //������
		return false;
	for (int j=L.length; j>=i;j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}


bool ListDelete(SeqList& L, int i, int& e)//��λɾ������ɾ�����Ԫ����ǰ������ɾ����Ԫ�ط���
{
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j=i;j<L.length;j++) 
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

int GetElem(SeqList L, int i)//��λ����
{
	return L.data[i - 1];
}

int LocateElem(SeqList L, int e)//��ֵ����  iΪ��ֵ��eΪλ��
{
	for (int j = 0;  j<L.length; j++)
	{
		if (L.data[j] == e)
			return j+1;
		return 0;
	}
}



