//动态顺序表
#include <stdio.h>
#include<stdlib.h>
#define InitSize 10

//定义
typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;


//函数声明
void InitList(SeqList& L);//初始化
void  IncreaseSize(SeqList& L, int len);//动态扩展
bool ListInsert(SeqList& L, int i, int e); //按位插入   在顺序表L中的第i个位置插入数据e
bool ListDelete(SeqList& L, int i, int& e);//按位删除并将删除的元素返回
int GetElem(SeqList L, int i);//按位查找
int LocateElem(SeqList L, int e);//按值查找  i为数值，e为位数



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
//		printf("顺序表中第%d个元素为%d\n", i+1, L.data[i]);
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
//		printf("顺序表中第%d个元素为%d\n", i + 1, L.data[i]);
//	}
//	int o=GetElem(L, 1);
//	printf("%d\n",o);
//
//	int a = LocateElem(L, 99);
//	if (a == 0)
//		printf("fail");
//	else
//		printf("第%d个元素为8",a);
//	return 0;
//}



void InitList(SeqList& L)//初始化
{
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}


void  IncreaseSize(SeqList& L, int len)//动态扩展
{
	int* p = L.data;//指针p指向顺序表L
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}

bool ListInsert(SeqList& L, int i, int e) //按位前置插入(被插入元素向后移动)在顺序表L中的第i个位置前插数据e
{
	if (i<1 || i>L.length + 1) //非法输入
		return false;
	if (L.length >=L.MaxSize)  //表长不够
		return false;
	for (int j=L.length; j>=i;j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}


bool ListDelete(SeqList& L, int i, int& e)//按位删除（将删除后的元素向前）并将删除的元素返回
{
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j=i;j<L.length;j++) 
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

int GetElem(SeqList L, int i)//按位查找
{
	return L.data[i - 1];
}

int LocateElem(SeqList L, int e)//按值查找  i为数值，e为位数
{
	for (int j = 0;  j<L.length; j++)
	{
		if (L.data[j] == e)
			return j+1;
		return 0;
	}
}



