#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct PolyNode *Poly;
struct PolyNode
{
	ElementType coef;
	ElementType expon;
	struct PolyNode *Next;//�ṹ�������Ҫ���� �Լ���ָ����Ҫ���������� ������ֻ��PolyNode *Next���򿴲��� û��typedef
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
Poly PolySum(Poly L1, Poly L2)//д���Ժ�L1L2�ᱻ�ı�
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
//С֪ʶ��typedef ��Ҫ�ԷֺŽ�β
//С֪ʶ�������ôд���� �ᵼ��ĳһ������Ϊ��һ��Ԫ�ص�������������µ�����ԭ������Ϊ 
//��һ������ͨ��������������
//����;������� 0����ʽָȫ0 �����ǵ������һ��Ϊ0
//����û�뵽�������0 0 ʹ��continue���ܻ����������