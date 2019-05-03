//需要掌握的知识：
//1、如何建立一个堆栈？以及对应的操作集 创建 push pop 判断满 判断空
//2、后序遍历的递归实现
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
int flag = 0;//用来控制行位输出
struct SNode
{
	ElementType *Data;
	int Maxsize;
	Position top;
};
Stack CreateStack(int size)
{
	Stack s=(Stack)malloc(sizeof(struct SNode));//结构体指针使用先必先初始化空间
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
		sta->Data[++(sta->top)] = data;//使用++给结构体的时候注意加上括号
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
		printf(" %d", pre[root]);//空格前置
}
int main()
{

	return 0;
}

