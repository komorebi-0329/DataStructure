//������
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//������
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BitNode, *BiTree;


//��������
BiTree CreateTree(BiTree tree);//����һ��������   ǰ�����
bool DestroyTree(BiTree& tree);//���ٶ�����
int TreeDepth(BiTree tree);//�����������
void Root(BiTree tree);//��ʾ���ڵ��ֵ
int Sumleaf(BiTree tree);//�ڵ����
void PreOrderTraverse(BiTree t);//ǰ����� �������ң�
void InOrderTraverse(BiTree t);//�������������ң�
void PostOrderTraverse(BiTree t);//������������Ҹ���
