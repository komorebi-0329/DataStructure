//������  
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include"09-BiTree.h"
using namespace std;


int main()
{
	int sum;
	BiTree t = (BiTree)malloc(sizeof(BiTNode));
	BiTree tree= CreateTree(t);


	cout << "ǰ�����" << endl;
	PreOrderTraverse(tree);
	cout << endl;
	cout << "�������" << endl;
	InOrderTraverse(tree);
	cout << endl;
	cout << "�������" << endl;
	PostOrderTraverse(tree);
	cout << endl;
	Root(tree);

	cout << "�������Ϊ" << TreeDepth(tree) << endl;//�����������
	sum = Sumleaf(tree);
	cout << "�����Ľڵ����Ϊ:" << sum << endl;

	DestroyTree(tree);
}



BiTree CreateTree(BiTree tree)//����һ��������
{
	char temp;
	scanf("%c", &temp);
	if (temp=='#')
		tree = NULL;
	else
	{
		tree = (BiTree)malloc(sizeof(BiTNode));
		(tree)->data = temp;
		tree->lchild = CreateTree(tree->lchild);//����������
		tree->rchild=CreateTree(tree->rchild);//����������
	}
	return tree;
}



bool DestroyTree(BiTree& tree)//���ٶ�����
{
	if (tree != NULL)
	{
		DestroyTree(tree->lchild);
		DestroyTree(tree->rchild);
		free(tree);
	}
	return true;
}

int TreeDepth(BiTree tree)//�����������
{
	int leftDepth, rightDepth;
	if (tree==NULL)
	{
		return 0;
	}
	else
	{
		leftDepth = TreeDepth(tree->lchild);
		rightDepth = TreeDepth(tree->rchild);
		if (leftDepth > rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;
	}
}

void Root(BiTree tree)//��ʾ���ڵ��ֵ
{
	printf("�����ĸ��ڵ�Ϊ%c\n", tree->data);

}

int Sumleaf(BiTree tree)
{
	int num;
	if (tree == NULL)
		return 0;
	else
		num = 1 + Sumleaf(tree->lchild) + Sumleaf(tree->rchild);
	return num;
}

void PreOrderTraverse(BiTree t)//ǰ����� �������ң�
{
	if (t == NULL)
		return;
	printf("%c", t->data);
	PreOrderTraverse(t->lchild);
	PreOrderTraverse(t->rchild);
}

void InOrderTraverse(BiTree t)//�������������ң�
{
	if (t == NULL)
		return;
	InOrderTraverse(t->lchild);
	printf("%c", t->data);
	InOrderTraverse(t->rchild);
}

void PostOrderTraverse(BiTree t)//������������Ҹ���
{
	if (t == NULL)
		return;
	PostOrderTraverse(t->lchild);
	PostOrderTraverse(t->rchild);
	printf("%c", t->data);
}
