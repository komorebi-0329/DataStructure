//链栈(中缀转后缀表达式)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"05-LiStack.h"

using namespace std;

//int main()
//{
//	char str[50];
//	LiStack L;
//	gets_s(str);	//gets()函数用来从键盘读取字符串直到换行符结束,但换行符会被丢弃，在末尾添加'\0'字符
//	InfixTOSuffix(L, str);
//	//ExpressionCount(L, str); (char中数值转换问题)
//	return 0;
//}
 
void ExpressionCount(LiStack& L, char str[])//表达式计算
{
	int i = 0;
	int a,b,sum;
	InitStack(L);
	while (str[i]!='\0')
	{
		if (isdigit(str[i]))
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

void InfixTOSuffix(LiStack& L, char str[])//中缀转后缀表达式
{
	int i = 0;
	int e;		//用于出栈带的变量
	InitStack(L);
	while (str[i] != '\0') //从左往右
	{
		while (isdigit(str[i]))//过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 
		{
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和右括号匹配时弹出。弹出后将优先级低的运算符压入栈中*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (!StackLength(L))		//如果当前表长为0   !0 =1  执行下面代码;  相反只要有数就是  !0=1
			{
				Push(L, str[i]);	//将“+” or “-” 入栈
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
						printf("%c ", e);		//出栈且 加如后缀表达式
					}
				} while (StackLength(L) && e != '(');

				Push(L, str[i]);  //将当前的运算符入栈
			}
		}
		/*当遇到右括号时，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if (str[i] == ')')
		{
			Pop(L, e);
			while (e != '(')
			{
				printf("%c ", e);
				Pop(L, e);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
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
			printf("\n输入格式错误！\n");
			return;
		}
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
	while (StackLength(L))
	{
		Pop(L, e);
		printf("%c ", e);
	}
}



bool InitStack(LiStack& L)//初始化链栈
{
	L = (LiStack)malloc(sizeof(StackTop));
	if (L == NULL)
		return false;
	L->top = NULL;
	L->Stacklength = 0;
	return true;
}


void DestroyStack(LiStack& L)//注销链栈
{
	while (L->top != NULL)
	{
		int x;
		Pop(L, x);
		cout << "被出栈的元素为" << x << endl;
	}
	cout << "链栈已被注销" << endl;
}


bool Push(LiStack& L, int x)//进栈
{
	LinkNode* tem = (LinkNode*)malloc(sizeof(LinkNode));
	if (tem == NULL)
		return false;
	tem->data = x;
	tem->next = L->top;
	L->top = tem;
	L->Stacklength++;
}


bool Pop(LiStack& L, int& x)//出栈
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


void  GetTop(LiStack& L)//读取栈顶
{
	if (L->top == NULL)
		cout << "now Stack is null" << endl;
	int tem = L->top->data;
	printf("now StackTop is %d", tem);
	//cout << "now StackTop is " << tem << endl;
}


void StackEmpty(LiStack& L)//判断空栈
{
	if (L->top == NULL)
		cout << "this stack is null" << endl;
	else
		cout << "this stack is no null" << endl;
}


int StackLength(LiStack& L)//求栈长
{
	int tem = L->Stacklength;
	return tem;
}
