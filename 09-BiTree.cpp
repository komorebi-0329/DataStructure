//������   tree[0]����Ԫ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;


//���������
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;



//��������
void InitTree(BiTNode& tree);//��ʼ��
bool ClearTree();//���������
bool DestroyTree();//���ٶ�����


