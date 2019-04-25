#pragma warning(disable:4996)
#include <stdio.h>
#include<iostream>
using namespace std;

#define MAXSIZE 1000
bool Rule1(int *List);
bool Rule2(int *List);
int StackCapacity, NumPush, NumPop;
int main()
{
	
	int *input;
	bool result[MAXSIZE];
	scanf("%d%d%d", &StackCapacity, &NumPush, &NumPop);
	input = (int*)malloc(NumPush * sizeof(int));
	for (int i = 0; i < NumPop; i++)
	{
		for (int j = 0; j < NumPush; j++)
			scanf("%d",&input[j]);
		result[i] = Rule1(input)&Rule2(input);
		 
	}

	for (int i = 0; i < NumPop; i++)
	{
		if (result[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	system("pause");
	return 0;
}
bool Rule1(int *List)
{
	for (int i = 0; i < NumPush - StackCapacity; i++)
	{
		if (List[i] > (StackCapacity + i))
			return 0;
		
	}
	return 1;
}
bool Rule2(int *List)
{
	bool flag=1;
	int LogicLast;
	
	
	for (int i = 0; i < NumPush - 1; i++)
	{
		LogicLast = List[i] - 1;
		for (int j = i-1; j >= 0; j--)
		{
			if (List[j] == LogicLast)
			{
				LogicLast--;
				j = i;
			}
		}

		
		
		if (List[i] > List[i+1] && List[i+1] != LogicLast)
			return 0;
			
	}
	return 1;
}
//��ʱ����
//ԭ��˼·һ��ʼû���
//�ҵ�˼·��
//���ù���������1������������������������ 2 ��ջ˳����ȷ
//1 2��ʱ���Ƚϳ�������2 �ʼû�и������ɫҪ��ôʵ��
//��һ���� ���inside��¼��һ�����ܵ�ֵ������������С��ǰ��ģ���ô��������ǿ���Ψһȷ���ģ�
//ʵ�����ȸ�inside��˳��ֵȻ���������ǰ�������ȡ�� �����޷�ʵ�ֻ��߸��Ӷȸ�
//������ʶ������û�б�Ҫ ֻҪȷ��һ��Ψһֵ�ͺ���

//dalao��˼·;
//ģ���ջ
//�Ƚ������� �γɴ�������
//Ȼ��1-7������ջ ���ջ���ʹ������еĶ���ͬ��
//���������Ԫ��pop��
//�ظ��������
//������������Ϊ��ʱ˵������Ч����
