//串   ch[0]废弃不用
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//定义动态字符串
typedef struct {
	char* ch;
	int length;
}HString;


//声明函数
bool InitString(HString& S, int len);//初始化
bool StrEmpty(HString S);	//判断表空
void PrintfString(HString s); //打印字符串
void StrAssign(HString& s, char *chars);	//赋值
void StrCopy(HString& s, HString l);	//复制字符串
int StrLength(HString s);	//表长
bool ClearString(HString& s);	//清空字符串
bool DestroyString(HString& s);	//注销字符串
void Concat(HString& T, HString a, HString b);	//连接字符串ab
bool Substring(HString& sub, HString s, int pos, int len);//求子串 用sub带回 主串S中第pos个字符起长len的子串
int Index(HString s, HString t);//定位操作  返回S串中存在子串t的位置
int Simple_Index(HString s, HString t);//定位操作  朴素算法
int Kmp_Search(HString s, HString t);//定位操作  KMP算法
void Get_Next(HString T, int next[]);//取得next数组
int StrCompare(HString s, HString t);//比较大小 



//int main()
//{
//	HString s1,s2,S;
//	InitString(s1, 255);
//	InitString(s2, 255);
//	InitString(S, 255);
//	char teststr[] = "ABCDE6";
//	StrAssign(s1, teststr);
//	char teststr2[] = "CDE6";
//	StrAssign(s2, teststr2);
//	//StrCopy(s1, s2);	
//	//Concat(S, s1, s2);
//	//Substring(S, s1, 2, 5);
//
//
//	cout<<"子串位置为："<< Kmp_Search(s1, s2)<<endl;//定位操作  返回S串中存在子串t的位置
//
//	/*if (StrEmpty(S))
//		printf("字符串为空\n");
//	else
//		cout << "字符串不为空，且表长为" << StrLength(S) << endl;
//	PrintfString(S);*/
//}

//初始化
bool InitString(HString &S,int len)
{
	S.ch = (char*)malloc(len * sizeof(char));
	if (S.ch == NULL)
		return false;	
	for (int i = 1; i < len; i++)
		S.ch[i] = '\0';
	S.length = 0;
	return true;
}

void PrintfString(HString s) //打印字符串
{
	if (s.length == 0)
		cout << "字符串为空\n";
	for (int i = 1; i < s.length+1; i++)
	{
		printf("第%d个元素为:%c\n", i, s.ch[i]);
	}
}

//判断表空
bool StrEmpty(HString S)
{
	if (S.length == 0)
		return true;
	else
		return false;
}

void StrAssign(HString& s, char *chars)//赋值
{
	int i, j;
	for (i = 1; i < strlen(chars)+1; i++)
		s.ch[i] = chars[i-1];
	for (j = i; j < s.length; j++)
		s.ch[j] = '\0';
	s.length = strlen(chars);
}

void StrCopy(HString& s, HString l)//复制字符串
{
	int i, j;
	for ( i = 1; i < l.length+1; ++i)
		s.ch[i] = l.ch[i];
	for ( j = i; j < s.length+1; ++j)
		s.ch[j] = '\0';
	s.length = l.length;
}

int StrLength(HString s)//表长
{
	return s.length;
}

bool ClearString(HString& s)//清空字符串
{
	if (s.length == NULL)
		return false;
	for (int i = 1; i < s.length; i++)
		s.ch[i] = '\0';
	s.length == 0;
	return true;
}

bool DestroyString(HString& s)//注销字符串
{
	free(s.ch);
	s.length = 0;
	return true;
}

void Concat(HString& T, HString a, HString b)//连接字符串ab
{
	int i;
	for (i = 1; i < a.length+1; i++)
		T.ch[i] = a.ch[i];
	for (int j = 1; j < b.length+1; j++,i++)
		T.ch[i] = b.ch[j];
	T.length = a.length + b.length;
}

bool Substring(HString& sub, HString s, int pos, int len)//求子串 用sub带回 主串S中第pos个字符起长len的子串
{
	if (pos + len-1 > s.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		sub.ch[i - pos + 1] = s.ch[i];
	sub.length = len;
	return true;
}

int Index(HString s, HString t)//定位操作  返回S串中存在子串t的位置
{
	int i = 1, n = StrLength(s), m = StrLength(t);
	HString sub;
	InitString(sub, 255);
	while (i<=n-m+1)
	{
		Substring(sub, s, i, m);
			if (StrCompare(sub, t) != 0)
				i++;
			else return i; //返回子串位置
	}
	return 0; //S中不存在与t相等的子串
}

int Simple_Index(HString s, HString t)//定位操作  朴素算法
{
	int k = 1; //k为位置变量
	int i=k, j=1;    //j为模式串的指向
	while (i<=s.length&&j<=t.length)
	{
		if (s.ch[i] == t.ch[j])
		{
			i++; 
			j++;
		}
		else
		{
			k++;
			i = k;
			j = 1;
		}
	}
	if (j > t.length)
		return k;
	else
		return 0;
}


int Kmp_Search(HString s, HString str)//定位操作  KMP算法
{
	int i = 1, j = 1;  //i为主串指向   j为模式串指向
	int next[255];
	Get_Next(str, next);
	while (i<=s.length && j<=str.length)
	{
		if (j == 0 || s.ch[i] == str.ch[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > str.length)
		return i - str.length;
	else
		return 0;
}


void Get_Next(HString T, int next[])//取得next数组
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i<T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i, ++j;	//若pi=pj，则next[j+1]=next[j]+1
			next[i] = j;
		}
		else
			//否则使j=next[j],循环继续
			j = next[j];
	}
}

int StrCompare(HString s, HString t)//比较大小 
{
	for (int i=1;i<=s.length&&i<=t.length;i++)
	{
		if (s.ch != t.ch)
			return s.ch[i] - t.ch[i];
	}
	return s.length - t.length;
}