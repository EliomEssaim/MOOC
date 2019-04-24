#pragma  warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;

#define MAXSIZE 1000000
struct Node {
	int Data;
	int Next;
}node[MAXSIZE];
int List_add[MAXSIZE];//写在main里面会导致堆栈异常
int main()
{
	int RevScale, num,First,add,tmp,i=0;
	int RevCnt;

	scanf("%d %d %d", &First, &num, &RevScale);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &add); 
		scanf("%d%d",&node[add].Data, &node[add].Next);
	}
	i = 0;
	tmp = First;
	while (tmp != -1)//这里写错成node[tmp].Next这样会导致最后一个元素无法录入
	{
		List_add[i++] = tmp;
		tmp = node[tmp].Next;
	}
	
	num = i;
	for (i = num / RevScale; i&&(RevScale <= num); i--)
	{
		reverse(&List_add[(i-1)*RevScale],&List_add[i * RevScale]);
	}
	RevCnt = num % RevScale;
	for (i = 0; i < num-1; i++)
		printf("%05d %d %05d\n", List_add[i], node[List_add[i]].Data, List_add[i + 1]);
	printf("%05d %d %d\n", List_add[i], node[List_add[i]].Data, -1);

	return 0;
}
//有多余结点不在链表上 
//意思是，我输入N个结点，但不是说这N个结点都在这个链表上。
//其中几个有可能是游离的（地址并不相连）。
//所以一开始的count和后面的链表的元素个数并不一定相等。
