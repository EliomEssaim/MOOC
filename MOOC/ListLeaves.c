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
}T1[MaxTree], T2[MaxTree];
struct Queqe
{
	int head;
	int rear;
	int usage;
	int size;
};
Tree BuildTree(struct TreeNode *T);
int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	
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
