//二叉树  
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


	cout << "前序遍历" << endl;
	PreOrderTraverse(tree);
	cout << endl;
	cout << "中序遍历" << endl;
	InOrderTraverse(tree);
	cout << endl;
	cout << "后序遍历" << endl;
	PostOrderTraverse(tree);
	cout << endl;
	Root(tree);

	cout << "树的深度为" << TreeDepth(tree) << endl;//返回树的深度
	sum = Sumleaf(tree);
	cout << "该树的节点个数为:" << sum << endl;

	DestroyTree(tree);
}



BiTree CreateTree(BiTree tree)//创建一个二叉树
{
	char temp;
	scanf("%c", &temp);
	if (temp=='#')
		tree = NULL;
	else
	{
		tree = (BiTree)malloc(sizeof(BiTNode));
		(tree)->data = temp;
		tree->lchild = CreateTree(tree->lchild);//构造左子树
		tree->rchild=CreateTree(tree->rchild);//构造右子树
	}
	return tree;
}



bool DestroyTree(BiTree& tree)//销毁二叉树
{
	if (tree != NULL)
	{
		DestroyTree(tree->lchild);
		DestroyTree(tree->rchild);
		free(tree);
	}
	return true;
}

int TreeDepth(BiTree tree)//返回树的深度
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

void Root(BiTree tree)//显示根节点的值
{
	printf("该树的根节点为%c\n", tree->data);

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

void PreOrderTraverse(BiTree t)//前序遍历 （根左右）
{
	if (t == NULL)
		return;
	printf("%c", t->data);
	PreOrderTraverse(t->lchild);
	PreOrderTraverse(t->rchild);
}

void InOrderTraverse(BiTree t)//中序遍历（左根右）
{
	if (t == NULL)
		return;
	InOrderTraverse(t->lchild);
	printf("%c", t->data);
	InOrderTraverse(t->rchild);
}

void PostOrderTraverse(BiTree t)//后序遍历（左右根）
{
	if (t == NULL)
		return;
	PostOrderTraverse(t->lchild);
	PostOrderTraverse(t->rchild);
	printf("%c", t->data);
}
