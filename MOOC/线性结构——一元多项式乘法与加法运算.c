#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct PolyNode *Poly;
struct PolyNode
{
	ElementType coef;
	ElementType expon;
	struct PolyNode *Next;//结构体内如果要声明 自己的指针需要完整的声明 不不能只是PolyNode *Next程序看不懂 没有typedef
};
Poly Read(void) {
	int n;
	Poly L = (Poly)malloc(sizeof(struct PolyNode));
	Poly last;
	L->Next = NULL;
	last = L;
	scanf("%d", &n);
	while (n)
	{
		Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
		scanf("%d%d", &p_new->coef,&p_new->expon);
		p_new->Next = NULL;
		last->Next = p_new;
		last = last->Next;
		n--;
	}

	return L;
}
void Print(Poly l)
{
	l = l->Next;
	while (l)
	{
		if(l->Next!=NULL)
			printf("%d %d ", l->coef, l->expon);
		else
			printf("%d %d\n", l->coef, l->expon);
		l = l->Next;
	}
}
int main()
{
	Poly P1, P2;
	P1 = (Poly)malloc(sizeof(struct PolyNode));
	P2 = (Poly)malloc(sizeof(struct PolyNode));
	P1 = Read();
	P2 = Read();
	printf("\n");
	Print(P1);
	Print(P2);
	return 0;
}
//小知识：typedef 需要以分号结尾
