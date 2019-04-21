#pragma warning(disable:4996) 
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();

	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}
List ReadInput()
{
	int count = 0;
	scanf("%d", &count);
	ElementType a;
	int i = 1;
	List num;
	while (i <= count)
	{
		scanf("%d", &a);
		num->Data[i] = a;
		num->Last = i;
		i++;
	}
	return num;
}
Position BinarySearch(List L, ElementType X)
{
	int i;
	i = L->Last / 2;
	while (L->Data[i] != X)
	{
		if (i == 0) return NotFound;
		if ((L->Data[i] > X))
			i = i / 2;
		else
			i = (i + L->Last+1) / 2;

	}
	return i;
}