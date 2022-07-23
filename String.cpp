#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//���嶯̬�ַ���
typedef struct {
	char* ch;
	int length;
}HString;

//���ַ��� ch[0]��������

//��������
bool InitString(HString& S, int len);//��ʼ��
bool StrEmpty(HString S);	//�жϱ��
void PrintfString(HString s); //��ӡ�ַ���
void StrAssign(HString& s, char *chars);	//��ֵ
void StrCopy(HString& s, HString l);	//�����ַ���
int StrLength(HString s);	//��
bool ClearString(HString& s);	//����ַ���
bool DestroyString(HString& s);	//ע���ַ���
void Concat(HString& T, HString a, HString b);	//�����ַ���ab
bool Substring(HString& sub, HString s, int pos, int len);//���Ӵ� ��sub���� ����S�е�pos���ַ���len���Ӵ�
int Index(HString s, HString t);//��λ����  ����S���д����Ӵ�t��λ��
int Simple_Index(HString s, HString t);//��λ����  �����㷨
int Kmp_Search(HString s, HString t);//��λ����  KMP�㷨
void Get_Next(HString T, int next[]);//ȡ��next����
int StrCompare(HString s, HString t);//�Ƚϴ�С 



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
//	cout<<"�Ӵ�λ��Ϊ��"<< Kmp_Search(s1, s2)<<endl;//��λ����  ����S���д����Ӵ�t��λ��
//
//	/*if (StrEmpty(S))
//		printf("�ַ���Ϊ��\n");
//	else
//		cout << "�ַ�����Ϊ�գ��ұ�Ϊ" << StrLength(S) << endl;
//	PrintfString(S);*/
//}

//��ʼ��
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

void PrintfString(HString s) //��ӡ�ַ���
{
	if (s.length == 0)
		cout << "�ַ���Ϊ��\n";
	for (int i = 1; i < s.length+1; i++)
	{
		printf("��%d��Ԫ��Ϊ:%c\n", i, s.ch[i]);
	}
}

//�жϱ��
bool StrEmpty(HString S)
{
	if (S.length == 0)
		return true;
	else
		return false;
}

void StrAssign(HString& s, char *chars)//��ֵ
{
	int i, j;
	for (i = 1; i < strlen(chars)+1; i++)
		s.ch[i] = chars[i-1];
	for (j = i; j < s.length; j++)
		s.ch[j] = '\0';
	s.length = strlen(chars);
}

void StrCopy(HString& s, HString l)//�����ַ���
{
	int i, j;
	for ( i = 1; i < l.length+1; ++i)
		s.ch[i] = l.ch[i];
	for ( j = i; j < s.length+1; ++j)
		s.ch[j] = '\0';
	s.length = l.length;
}

int StrLength(HString s)//��
{
	return s.length;
}

bool ClearString(HString& s)//����ַ���
{
	if (s.length == NULL)
		return false;
	for (int i = 1; i < s.length; i++)
		s.ch[i] = '\0';
	s.length == 0;
	return true;
}

bool DestroyString(HString& s)//ע���ַ���
{
	free(s.ch);
	s.length = 0;
	return true;
}

void Concat(HString& T, HString a, HString b)//�����ַ���ab
{
	int i;
	for (i = 1; i < a.length+1; i++)
		T.ch[i] = a.ch[i];
	for (int j = 1; j < b.length+1; j++,i++)
		T.ch[i] = b.ch[j];
	T.length = a.length + b.length;
}

bool Substring(HString& sub, HString s, int pos, int len)//���Ӵ� ��sub���� ����S�е�pos���ַ���len���Ӵ�
{
	if (pos + len-1 > s.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		sub.ch[i - pos + 1] = s.ch[i];
	sub.length = len;
	return true;
}

int Index(HString s, HString t)//��λ����  ����S���д����Ӵ�t��λ��
{
	int i = 1, n = StrLength(s), m = StrLength(t);
	HString sub;
	InitString(sub, 255);
	while (i<=n-m+1)
	{
		Substring(sub, s, i, m);
			if (StrCompare(sub, t) != 0)
				i++;
			else return i; //�����Ӵ�λ��
	}
	return 0; //S�в�������t��ȵ��Ӵ�
}

int Simple_Index(HString s, HString t)//��λ����  �����㷨
{
	int k = 1; //kΪλ�ñ���
	int i=k, j=1;    //jΪģʽ����ָ��
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

int Kmp_Search(HString s, HString str)//��λ����  KMP�㷨
{
	int i = 1, j = 1;  //iΪ����ָ��   jΪģʽ��ָ��
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

void Get_Next(HString T, int next[])//ȡ��next����
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i<T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i, ++j;	//��pi=pj����next[j+1]=next[j]+1
			next[i] = j;
		}
		else
			//����ʹj=next[j],ѭ������
			j = next[j];
	}
}

int StrCompare(HString s, HString t)//�Ƚϴ�С 
{
	for (int i=1;i<=s.length&&i<=t.length;i++)
	{
		if (s.ch != t.ch)
			return s.ch[i] - t.ch[i];
	}
	return s.length - t.length;
}