#include<iostream>  
#include<stdio.h>  
#include<algorithm>    ///ʹ�õ�reverse ��ת����  
using namespace std;

#define MAXSIZE 1000010   ///���Ϊ��λ���ĵ�ַ  

struct node    ///ʹ��˳���洢data����һ��ַnext  
{
	int data;
	int next;
}node[MAXSIZE];

int List[MAXSIZE];   ///�洢���������ϵ�˳���  
int main()
{
	int First, n, k;
	cin >> First >> n >> k;   ///����ͷ��ַ �� n��k��  
	int Address, Data, Next;
	for (int i = 0; i < n; i++)
	{
		cin >> Address >> Data >> Next;
		node[Address].data = Data;
		node[Address].next = Next;
	}

	int j = 0;  ///j�����洢�ܹ���β�����Ľڵ���  
	int p = First;   ///pָʾ��ǰ���  
	while (p != -1)
	{
		List[j++] = p;
		p = node[p].next;
	}
	int i = 0;
	while (i + k <= j)   ///ÿk���ڵ���һ�η�ת  
	{
		reverse(&List[i], &List[i + k]);
		i = i + k;
	}
	for (i = 0; i < j - 1; i++)
		printf("%05d %d %05d\n", List[i], node[List[i]].data, List[i + 1]);
	printf("%05d %d -1\n", List[i], node[List[i]].data);
	return 0;

}
//����linux�˵�������push����
