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
int List_add[MAXSIZE];//д��main����ᵼ�¶�ջ�쳣
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
	while (tmp != -1)//����д���node[tmp].Next�����ᵼ�����һ��Ԫ���޷�¼��
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
//�ж����㲻�������� 
//��˼�ǣ�������N����㣬������˵��N����㶼����������ϡ�
//���м����п���������ģ���ַ������������
//����һ��ʼ��count�ͺ���������Ԫ�ظ�������һ����ȡ�
