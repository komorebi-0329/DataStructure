//˳��ջ
#define MaxSize 10
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


//����˳��ջ
typedef struct {
	int data[MaxSize];
	int top;
}Sqstack;

//����
bool InitStack(Sqstack&L);//��ʼ��˳��ջ
bool DestroyStack(Sqstack&L);//ע��˳��ջ
bool Push(Sqstack& L, int x);//��ջ
bool Pop(Sqstack& L, int& x);//��ջ
void  GetTop(Sqstack& L);//��ȡջ��
bool StackEmpty(Sqstack& L);//�жϿ�ջ
void PrintfStack(Sqstack& L);//����
void StackLength(Sqstack& L);//��ջ��



int main()
{
	Sqstack t;
	InitStack(t);
	Push(t,1);//��ջ
	Push(t, 2);//��ջ
	Push(t, 3);//��ջ
	Push(t, 4);//��ջ
	Push(t, 5);//��ջ
	PrintfStack(t);
	GetTop(t);
	StackLength(t);
	int x=0;
	if (Pop(t, x))
		cout << "success ����ջ��Ԫ��Ϊ"<<x<< endl;
	else
		cout << "fail" << endl;
	GetTop(t);
	
	DestroyStack(t);
	StackLength(t);
	if (StackEmpty(t))
		cout << "this stack is NULL" << endl;
	else
		cout << "This Stack have num" << endl;
}



bool InitStack(Sqstack& L)//��ʼ��˳��ջ
{
	L.top = -1;
	return true;
}


bool DestroyStack(Sqstack& L)//ע��˳��ջ
{
	L.top = -1;		//���߼�������˳��ջ �����ڴ�����Ȼ�������ݣ���ϵͳ������һ������
	return true;
}


bool Push(Sqstack& L, int x)//��ջ
{
	if (L.top == MaxSize)
		return false;	
	L.top = L.top + 1;
	L.data[L.top] = x;
	return true;
}


bool Pop(Sqstack& L, int& x)//��ջ
{
	if (L.top == -1)
		return false;
	x = L.data[L.top];
	L.top = L.top - 1;
	// x=L.data[L.top--];
	return true;
}


void  GetTop(Sqstack& L)//��ȡջ��
{
	if (L.top == -1)
		cout << "��ջΪ��"<< endl;
	int a = L.data[L.top];
	cout << "��ʱջ��Ԫ��Ϊ" << a << endl;
}


bool StackEmpty(Sqstack& L)//�жϿ�ջ
{
	if (L.top = -1)
		return true;
	else
		return false;
}

void PrintfStack(Sqstack& L)//����
{
	for (int  i = 0; i <MaxSize; i++)
	{		
		printf("Stack�е�%d��Ԫ��Ϊ%d\n", i, L.data[i]);
	}
}

void StackLength(Sqstack& L)//ջ��
{
	if (L.top == 0)
		cout << "��ջ" << endl;
	int a;
	a= L.top+1;
	cout << "��ʱջ��Ϊ" << a << endl;
}
