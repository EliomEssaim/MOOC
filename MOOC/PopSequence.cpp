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
//耗时长：
//原因：思路一开始没想好
//我的思路：
//设置规则两条：1输入的数不超过数组的容纳量 2 出栈顺序正确
//1 2耗时都比较长尤其是2 最开始没有搞清楚角色要怎么实现
//第一次想 搞个inside记录下一个可能的值（后面的数如果小于前面的，那么后面的数是可以唯一确定的）
//实现是先给inside按顺序赋值然后如果遇到前面的数就取消 后来无法实现或者复杂度高
//最后才意识到根本没有必要 只要确定一个唯一值就好了

//dalao的思路;
//模拟堆栈
//先接受序列 形成待测序列
//然后将1-7依次入栈 如果栈顶和待测序列的顶相同则将
//待测的序列元素pop走
//重复这个流程
//当最后待测序列为空时说明是有效序列
