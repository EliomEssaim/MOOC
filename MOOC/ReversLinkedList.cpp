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
int main()
{
	int RevScale, num,First,add,tmp,i=0;
	int List_add[MAXSIZE];
	scanf("%d %d %d", &First, &num, &RevScale);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &add); 
		scanf("%d%d",&node[add].Data, &node[add].Next);
	}
	i = 0;
	tmp = First;
	while (node[tmp].Next != -1)
	{
		List_add[i++] = tmp;
		tmp = node[tmp].Next;
	}
	for (i = num % RevScale; i; i--)
	{
		reverse(List_add+(i-1)*RevScale,List_add+(i-1)* RevScale);
	}
	for (int i = 0; i < num; i++)
		printf("%d %d %d", List_add[i], node[List_add[i]].Data, List_add[i + 1]);
	system("pause");
	return 0;
}
