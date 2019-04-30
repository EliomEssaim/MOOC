#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"
#include "string.h"
#define MaxTree 10
#define ElementType int 
#define Tree int
#define Null -1
typedef struct TreeNode {
	ElementType Data;
	Tree Left;
	Tree Right;
}TNode;
TNode T1[MaxTree];
TNode Queue[MaxTree];
int first = -1, last = -1;
void Push(TNode tn);
TNode Pop();
void LevelScan(int root);
Tree BuildTree(struct TreeNode *T);
int n;
int main()
{
	int R1;
	R1 = BuildTree(T1);
	LevelScan(R1);
	return 0;
}
Tree BuildTree(struct TreeNode *T)
{
	int NumNode, root = Null;
	char cl, cr;
	scanf("%d", &NumNode);
	bool *inside = (bool*)malloc(sizeof(bool)*NumNode);
	memset(inside, 1, NumNode);
	n = NumNode;
	for (int i = 0; i < NumNode; i++)
	{
		T[i].Data = i;
		scanf("\n%c %c", &cl, &cr);//�س���ǰ��Ե��س�
		if (cl != '-')
		{
			T[i].Left = cl - '0';
			inside[T[i].Left] = 0;
		}
		else
			T[i].Left = Null;
		if (cr != '-')
		{
			T[i].Right = cr - '0';
			inside[T[i].Right] = 0;
		}
		else
			T[i].Right = Null;

	}
	for (int i = 0; i < NumNode; i++)
		if (inside[i] != 0)
		{
			root = i;
			break;
		}


	return root;
}

void Push(TNode treeNode)
{
	Queue[++last] = treeNode;
}

TNode Pop()
{
	return Queue[++first];
}
void LevelScan(int root)
{
	int leaves[MaxTree];
	int k = 0;
	Push(T1[root]);
	for (int i = 0; i < n; i++)
	{
		TNode tn = Pop();
		//���Ӻ��Һ��Ӷ�������ʱ����Ҷ�ڵ��ֵ���浽�����У����ڸ�ʽ����ӡ
		if (tn.Left == -1 && tn.Right == -1)
			leaves[k++] = tn.Data;
		if (tn.Left != -1)
			Push(T1[tn.Left]);
		if (tn.Right != -1)
			Push(T1[tn.Right]);
	}
	for (int i = 0; i < k - 1; i++)
		printf("%d ", leaves[i]);
	printf("%d\n", leaves[k - 1]);
}