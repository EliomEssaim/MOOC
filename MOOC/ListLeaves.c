#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"
#include "string.h"
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
	ElementType Data;
	Tree Left;
	Tree Right;
}T1[MaxTree];
struct Queue {
	struct TreeNode Data[MaxTree];
	int head, rear;
	int size ;
	int usage;
}Q;

void InitQ(void);
int EnterQ(struct TreeNode Node);
struct TreeNode*DepartQ(void);
Tree BuildTree(struct TreeNode *T);
bool LevelScan(Tree R);
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
	for (int i = 0; i < NumNode; i++)
	{
		scanf("\n%c %c %c", &T[i].Data, &cl, &cr);//回车放前面吃掉回车
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
void InitQ(void)
{
	Q.size = MaxTree;
	Q.usage = 0;
	Q.head = 0;
	Q.rear = 0;
 
}
int EnterQ(struct TreeNode Node)
{
	if (++Q.usage > Q.size)
	{
		--Q.usage;
		return 0;
	}
	Q.Data[Q.head%Q.size] = Node;//实现循环
	Q.head = (Q.head + 1) % Q.size;
	return 1;

}
struct TreeNode*DepartQ(void)
{
	if (--Q.usage <= 0)
	{
		Q.usage++;
		return (struct TreeNode*)0;
	}
	if (++Q.rear > Q.size)
		return &Q.Data[(Q.rear - 1) % Q.size];
	else
		return &Q.Data[Q.rear - 1];
}
bool LevelScan(Tree R)
{
	EnterQ(T1[R]);
}