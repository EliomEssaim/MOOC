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
		scanf("\n%c %c %c", &T[i].Data, &cl, &cr);//�س���ǰ��Ե��س�
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
	/* �������������Ӷ���Ϊ�ղ������ݻ���һ���ģ�������ӽ��еݹ�*/
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Data) == (T2[T2[R2].Left].Data)))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	/* �������������ӣ�һ����һ�����ջ��߶����գ��������ݲ�һ������ô�жϵ�һ���������ң������Ƿ���ڶ��������ң��󣩶���ͬ�� */
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));


}
//�����˿��� �������ʵ���ǽڵ㲻������ֵ ��ֵ���ǱȽϵĹؼ� �������Ľڵ������һ��ĵ�ַ �Ƚ��������ĵ�ַ��������
//�������洢��ʽ�����ڵ���ɵĽṹ�幹������ ���±���Ϊ��ַ��α��ÿ���ṹ������������int��ָʾ����������α��ַ
//�ж�ͬ�������õݹ�ķ�ʽ������С�ݹ鵥λ���ҳ��� �ȳ��ݹ���ֹ���� �����¾����ݹ�
//д���� 1���г���/2�������������
//С֪ʶ��sanf����д��\n����Ե���������ĵ�һ���س�����ʹ��������� �����Ҫ�Ե��س��ҽ���scanf��ô����дһ��scanf�Ե���