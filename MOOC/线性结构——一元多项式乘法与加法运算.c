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
Poly PolySum(Poly L1, Poly L2)//写了以后L1L2会被改变
{
	Poly Sum = (Poly)malloc(sizeof(struct PolyNode));
	Poly last;
	Sum->Next = NULL;
	last = Sum;
	L1 = L1->Next;
	L2 = L2->Next;
	while (L1&&L2)
	{
		if (L1->expon > L2->expon)
		{
			Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
			p_new->expon = L1->expon;
			p_new->coef = L1->coef;
			if (p_new->coef == 0)
			{
				free(p_new);
				L1 = L1->Next;
				continue;
			}
			p_new->Next = NULL;
			last->Next = p_new;
			last = p_new;
			L1 = L1->Next;
		}
		else if(L1->expon < L2->expon)
		{
			Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
			p_new->expon = L2->expon;
			p_new->coef = L2->coef;
			if (p_new->coef == 0)
			{
				free(p_new);
				L2 = L2->Next;
				continue;
			}
			p_new->Next = NULL;
			last->Next = p_new;
			last = p_new;
			L2 = L2->Next;
		}
		else
		{
			Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
			p_new->coef = L1->coef + L2->coef;
			p_new->expon = L1->expon;
			if (p_new->coef==0)
			{
				free(p_new);
				L1 = L1->Next;
				L2 = L2->Next;
				continue;
			}
			p_new->Next = NULL;

			last->Next = p_new;
			last = last->Next;
			L1 = L1->Next;
			L2 = L2->Next;
		}

	}
	if (L1 == NULL)
		last->Next = L2;
	else if (L2 == NULL)
		last->Next = L1;
	if (Sum->Next == NULL)
	{
		Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
		p_new->coef = 0;
		p_new->expon = 0;
		p_new->Next = NULL;
		Sum->Next = p_new;
	}

	return Sum;
}
Poly MultiPoly(Poly L1, Poly L2) {
	Poly L=(Poly)malloc(sizeof(struct PolyNode));
	Poly L1_origin, L2_origin;
	L->Next = NULL;

	L1 = L1->Next;
	L2 = L2->Next;

	L1_origin = L1;
	L2_origin = L2;
	for (L2=L2_origin; L2; L2 = L2->Next)
	{
		Poly begin, last;
		begin = (Poly)malloc(sizeof(struct PolyNode));
		begin->Next = NULL;
		last = begin;
		for (L1=L1_origin; L1; L1 = L1->Next)
		{
			Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
			p_new->Next = NULL;
			p_new->coef = L1->coef*L2->coef;
			p_new->expon = L1->expon + L2->expon;
			if (p_new->coef == 0)
			{
				free(p_new);
				continue;
			}
			last->Next = p_new;
			last = p_new;
		}
		L = PolySum(begin, L);
	}

	if (L->Next == NULL)
	{
		Poly p_new = (Poly)malloc(sizeof(struct PolyNode));
		p_new->coef = 0;
		p_new->expon = 0;
		p_new->Next = NULL;
		L->Next = p_new;
	}
	return L;
}

int main()
{
	Poly P1, P2,Sum,Mult;
	P1 = (Poly)malloc(sizeof(struct PolyNode));
	P2 = (Poly)malloc(sizeof(struct PolyNode));
	P1 = Read();
	P2 = Read();
	Sum = PolySum(P1, P2);
	Mult = MultiPoly(P1, P2);

	Print(Mult);
	Print(Sum);
	

	return 0;
}
//小知识：typedef 需要以分号结尾
//小知识：如果那么写函数 会导致某一个（作为第一个元素的链表）被改造成新的链表，原因是因为 
//第一个可以通过他遍历新链表
//错误;误会题意 0多项式指全0 而不是单单最后一项为0
//错误：没想到特殊情况0 0 使用continue可能会有特殊情况