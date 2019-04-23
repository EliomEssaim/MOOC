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
	struct Node *p;
	int List_add[MAXSIZE];
	scanf("%d %d % d", &First, &num, &RevScale);

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &add, &node[add].Data, &node[add].Next);
	}
	p = node;
	tmp = First;
	while (node[tmp].Next != -1)
	{
		List_add[i++] = tmp;
		tmp = node[tmp].Next;
	}
	for(int i=num%RevScale;i;i--)


	system("pause");
	return 0;
}
