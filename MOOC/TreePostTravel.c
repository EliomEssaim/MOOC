//��Ҫ���յ�֪ʶ��
//1����ν���һ����ջ���Լ���Ӧ�Ĳ����� ���� push pop �ж��� �жϿ�
//2����������ĵݹ�ʵ��
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"
#include "string.h"
 
#define Error -1;

typedef int Position;
typedef int ElementType;
typedef struct SNode *Stack;
int *pre,*in;
int flag = 0;//����������λ���
struct SNode
{
	ElementType *Data;
	int Maxsize;
	Position top;
};
Stack CreateStack(int size)
{
	Stack s=(Stack)malloc(sizeof(struct SNode));//�ṹ��ָ��ʹ���ȱ��ȳ�ʼ���ռ�
	s->Data = (ElementType)malloc(sizeof(ElementType)*size);
	s->Maxsize = size;
	s->top = -1;
}
bool IsFull(Stack sta)
{
	return sta->Maxsize == sta->top + 1;
}
bool Push(Stack sta, ElementType data)
{
	if (IsFull(sta))
		return 0;
	else
		sta->Data[++(sta->top)] = data;//ʹ��++���ṹ���ʱ��ע���������
	return 1;
}
bool IsEmpty(Stack sta)
{
	return sta->top == -1;
}
ElementType Pop(Stack sta)
{
	if (IsEmpty(sta))
		return 0;
	else
		return sta->Data[(sta->top)--];
}
void Clear(Stack sta)
{
	sta->top = -1;
}
void Post(int root, int start, int end)
{
	if (start > end)
		return;
	int i=0;
	while (pre[root] != in[i]) i++;
	post(root + 1, start, i - 1);
	post(root + 1 + i - start, i + 1, end);

	if (!flag)
	{
		printf("%d", pre[root]);
		flag = 1;
	}
	else
		printf(" %d", pre[root]);//�ո�ǰ��
}
int main()
{

	return 0;
}

