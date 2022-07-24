//二叉树   tree[0]不存元素
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;


//定义二叉链
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;



//函数声明
void InitTree(BiTNode& tree);//初始化
bool ClearTree();//清除二叉树
bool DestroyTree();//销毁二叉树


