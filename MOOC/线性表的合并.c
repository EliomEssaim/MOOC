#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L = (List)malloc(sizeof(struct Node));
	L = L1;
	while (L)
	{
		L = L->Next;
		printf("%d",L->Data);
		
	}
	//	L2 = Read();
	//    L = Merge(L1, L2);
	//    Print(L);
	//    Print(L1);
	//    Print(L2);
	return 0;
}
List Read() {
	List p = (List)malloc(sizeof(struct Node));
	List last = (List)malloc(sizeof(struct Node));
	p->Next = NULL;
	last = p;
	int n;
	scanf("%d", &n);
	while (n)
	{
		List p_new = (List)malloc(sizeof(struct Node));
		scanf("%d",&(p_new->Data));
		p_new->Next = NULL;
		last->Next = p_new;
		last = p_new;
		n--;
	}
	return p;
}
//小知识：结构的大小是其成员大小的最小公倍数（但要大于和）本质是结构体地址需要对齐 
//小知识;scanf("%d",&a)会忽略空格
//整个程序结束后程序所占有的资源都会被操作系统回收
