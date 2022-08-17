//��ջ(��׺ת��׺���ʽ)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"05-LiStack.h"

using namespace std;

//int main()
//{
//	char str[50];
//	LiStack L;
//	gets_s(str);	//gets()���������Ӽ��̶�ȡ�ַ���ֱ�����з�����,�����з��ᱻ��������ĩβ���'\0'�ַ�
//	InfixTOSuffix(L, str);
//	//ExpressionCount(L, str); (char����ֵת������)
//	return 0;
//}
 
void ExpressionCount(LiStack& L, char str[])//���ʽ����
{
	int i = 0;
	int a,b,sum;
	InitStack(L);
	while (str[i]!='\0')
	{
		if (isdigit(str[i]))   //isdigit�����ж��Ƿ�Ϊ������
		{
			Push(L, str[i]);
			i++;
		}
		else if (str[i]=='+')
		{
			Pop(L, a);
			Pop(L, b);
			sum = b+a;
			Push(L, sum);
			i++;
		}
		else if (str[i] == '-')
		{
			Pop(L, a);
			Pop(L, b);
			sum = b - a;
			Push(L, sum);
			i++;
		}
		else if (str[i] == '*')
		{
			Pop(L, a);
			Pop(L, b);
			sum = b * a;
			Push(L, sum);
			i++;
		}
		else if (str[i] == '/')
		{
			Pop(L, a);
			Pop(L, b);
			sum = b / a;
			Push(L, sum);
			i++;
		}
	}
	GetTop(L);
}

void InfixTOSuffix(LiStack& L, char str[])//��׺ת��׺���ʽ
{
	int i = 0;
	int e;		//���ڳ�ջ���ı���
	InitStack(L);
	while (str[i] != '\0') //��������
	{
		while (isdigit(str[i]))//���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� 
		{
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ���������������Ŵ���ѹջ����Ϊ��
		����Ҫ��������ƥ��ʱ���������������ȼ��͵������ѹ��ջ��*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (!StackLength(L))		//�����ǰ��Ϊ0   !0 =1  ִ���������;  �෴ֻҪ��������  !0=1
			{
				Push(L, str[i]);	//����+�� or ��-�� ��ջ
			}
			else
			{
				do
				{
					Pop(L, e);
					if (e == '(')
					{
						Push(L, e);
					}
					else
					{
						printf("%c ", e);		//��ջ�� �����׺���ʽ
					}
				} while (StackLength(L) && e != '(');

				Push(L, str[i]);  //����ǰ���������ջ
			}
		}
		/*������������ʱ����������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
		������ֻ��������ӡ��������Ҳ��ѹջ��*/
		else if (str[i] == ')')
		{
			Pop(L, e);
			while (e != '(')
			{
				printf("%c ", e);
				Pop(L, e);
			}
		}
		/*�ˡ����������Ŷ������ȼ��ߵģ�ֱ��ѹջ*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
		{
			Push(L, str[i]);
		}

		else if (str[i] == '\0')
		{
			break;
		}

		else
		{
			printf("\n�����ʽ����\n");
			return;
		}
		i++;
	}
	/*����ջ��ʣ�����������ε�ջ��ӡ*/
	while (StackLength(L))
	{
		Pop(L, e);
		printf("%c ", e);
	}
}



bool InitStack(LiStack& L)//��ʼ����ջ
{
	L = (LiStack)malloc(sizeof(StackTop));
	if (L == NULL)
		return false;
	L->top = NULL;
	L->Stacklength = 0;
	return true;
}


void DestroyStack(LiStack& L)//ע����ջ
{
	while (L->top != NULL)
	{
		int x;
		Pop(L, x);
		cout << "����ջ��Ԫ��Ϊ" << x << endl;
	}
	cout << "��ջ�ѱ�ע��" << endl;
}


bool Push(LiStack& L, int x)//��ջ
{
	LinkNode* tem = (LinkNode*)malloc(sizeof(LinkNode));
	if (tem == NULL)
		return false;
	tem->data = x;
	tem->next = L->top;
	L->top = tem;
	L->Stacklength++;
}


bool Pop(LiStack& L, int& x)//��ջ
{
	LinkNode* p;
	if (L->top == NULL)
		return false;
	x = L->top->data;
	p = L->top;
	L->top = p->next;
	free(p);
	L->Stacklength--;
	return true;
}


void  GetTop(LiStack& L)//��ȡջ��
{
	if (L->top == NULL)
		cout << "now Stack is null" << endl;
	int tem = L->top->data;
	printf("now StackTop is %d", tem);
	//cout << "now StackTop is " << tem << endl;
}


void StackEmpty(LiStack& L)//�жϿ�ջ
{
	if (L->top == NULL)
		cout << "this stack is null" << endl;
	else
		cout << "this stack is no null" << endl;
}


int StackLength(LiStack& L)//��ջ��
{
	int tem = L->Stacklength;
	return tem;
}
