#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"
#include "string.h"
typedef struct TreeNode *Tree;
struct TreeNode {
	int node;
	Tree left;
	Tree right;
	bool flag;
};
Tree NewNode(int val)
{
	Tree t;
	t = (Tree)malloc(sizeof(struct TreeNode));
	t->left = NULL;
	t->right = NULL;
	t->flag = 0;

	return t;
}
Tree Insert(Tree t, int data)//insert����Ϥ���������ݹ����̺�˼��
{
	if (t == NULL)
	{
		t = NewNode(data);
	}
	else
	{
		if (t->node > data)
			t->left = Insert(t->left, data);
		else 
			t->right = Insert(t->right, data);//������Ҳ����������򣿣�����

	}
		
	return t;
}
Tree MakeTree(int n)
{
	Tree t;
	int val;
	//���ڵ㲻һ�µ�һ��Ҫ���ó��� //��˼1: ��ʼ����������
	scanf("%d", &val);
	t = NewNode(val);
	for (int i = 1; i < n; i++)
	{
		scanf("%d",&val);
		t = Insert(t, val);
	}
	return t;
}
int Check(Tree t, int data)
{
	if (t->flag)
	{
		if (data > t->node)
			return Check(t->right, data);
		else if (data < t->node)
			return Check(t->left, data);
		else
			return 0;
	}
	else
	{
		if (data == t->node)
		{
			t->flag = 1;
			return 1;
		}
		else
			return 0;
	}
}
int Judge(Tree t, int N)
{
	int i, flag = 0,val;
	
	scanf("%d", &val);
	if (t->node != val)
		flag = 1;
	else
		t->flag = 1;
	for (i = 1; i < N; i++)
	{
		scanf("%d", &val);
		if(!flag&&(!Check(t,val))) flag=1; 
	}
	if (flag) return 0;
	else return 1;
}
void ResetT(Tree T)
{
	if (T->left) ResetT(T->left);
	else if (T->right) ResetT(T->right);
	else
		T->flag = 0;
}
void FreeTree(Tree T)
{
	if (T->left) ResetT(T->left);
	else if (T->right) ResetT(T->right);
	else
		free(T);
}
int main()
{
	int N, L;
	Tree T;
	scanf("%d", &N);
	while (N)
	{
		scanf("%d", &L);
		T = MakeTree(N);
		
		for (int i = 0; i < L; i++)
		{
			if (Judge(T,N))
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T);
		}
		FreeTree(T);//�벻��= =����Ϊ�����ƴ�������ÿһ���жϺ�Ҫ�������
		scanf("%d", &N);
	}

/*	//����׼��
		׼�������Ĵ洢��ʽ����ʽ (��������Ϊ���� ����Ϊ����������flag)
		���룺�ȸ�������һ���ռ� ����Nѭ�����ж� ���ڸ��� ������С�ڷ�֮ ���ò����ҵ����ʵ�λ�õݹ鷵���Լ���ָ��

	//		
	//�Ƚ����� ÿ��һ���Ƚ�������һ�� �ڻ�׼����λ�� �������flag��ǽڵ� �����һ��������flagΪ0��δ���������򷵻�0 
	������һ��Сflag��ֹ�������  ����������flag������
	//
*/
	return 0;
}
/*
��˼1��д������-������һ����Ī��˼·-�����ֳ�������ž���һ��һ���Ž�ȥ ̫�ַŵ�˼��-�����̻�˼����
�ܵõ�ʲô��
��Ҫ����ʲô��
��һ����-����������-�����ڵ�ǰ�����Ľ���û��˼·��-��û�н����Ļ���˼·��ģ�壩���޸�֮��Ƽ��Ȼ�޴�˼��  ���Բ�ͨ��ģ��������𣿣�2��-�� һ��Ҫ��������һ�½ṹ
��2�����򵥵Ŀ��Բ���˼����д���� ���ӵĲ���= = ��������˵Ŀǰ�򵥵ľ���СС���߼��ж�

�㲻����������Ҫ��ʲô����������ڵ�����
*/