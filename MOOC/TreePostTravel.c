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
	s->Data = (ElementType*)malloc(sizeof(ElementType)*size);
	s->Maxsize = size;
	s->top = -1;

	return s;
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
	Post(root + 1, start, i - 1);
	Post(root + 1 + i - start, i + 1, end);

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
	int num,da;
	int ipre, iin;
	ipre = 0;
	iin = 0;
	char str[10];
	Stack S;
	scanf("%d", &num);
	S = CreateStack(num);
	pre = (ElementType*)malloc(sizeof(ElementType)*num);
	in = (ElementType*)malloc(sizeof(ElementType)*num);
	for (int j = 0; j < num*2; j++)
	{
		scanf("%s", str);//怎么只读取第二个字符 直接读字符串
		if (str[1] == 'u')
		{
			scanf("%d", &da);//怎么读取数字？
			pre[ipre++] = da;
			Push(S, da);
		}
		else if (str[1] == 'o')
		{
			in[iin++] = Pop(S);
		}
			
	}

	Post(0, 0, num - 1);

	return 0;
}

//scanf以空格作为结尾 要想输入带空格的字符串可以用gets（以回车 tab作为结束）