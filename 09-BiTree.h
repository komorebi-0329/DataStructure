//二叉树
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//定义树
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BitNode, *BiTree;


//函数声明
BiTree CreateTree(BiTree tree);//创建一个二叉树   前序遍历
bool DestroyTree(BiTree& tree);//销毁二叉树
int TreeDepth(BiTree tree);//返回树的深度
void Root(BiTree tree);//显示根节点的值
int Sumleaf(BiTree tree);//节点个数
void PreOrderTraverse(BiTree t);//前序遍历 （根左右）
void InOrderTraverse(BiTree t);//中序遍历（左根右）
void PostOrderTraverse(BiTree t);//后序遍历（左右根）
