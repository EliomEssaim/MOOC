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
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode *T);
bool Isomorphic(ElementType R1, ElementType R2);
int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1,R2))
		printf("Yes");
	else
		printf("No");

	return 0;
}
Tree BuildTree(struct TreeNode *T)
{
	int NumNode,root=Null;
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
bool Isomorphic(ElementType R1, ElementType R2) 
{
	
	if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R2 == Null )&& (R1 != Null)))
		return 0;

	if (T1[R1].Data != T2[R2].Data)
		return 0;
	
	


	
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	/* 如果两棵树左儿子都不为空并且数据还是一样的，对左儿子进行递归*/
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Data) == (T2[T2[R2].Left].Data)))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	/* 如果两棵树左儿子（一个空一个不空或者都不空）并且数据不一样，那么判断第一棵树的左（右）儿子是否跟第二棵树的右（左）儿子同构 */
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));


}
//忽略了空树 理解了其实就是节点不等于数值 数值才是比较的关键 这个程序的节点就是另一类的地址 比较两个树的地址毫无意义
