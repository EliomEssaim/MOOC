#pragma warning(disable:4996)
#include <stdio.h>
#define MAXSIZE 100000
int MaxSubsequenceSum3(int A[],int left,int right);
int main(void)
{
	int MaxSum;
//	int ThisSum;
	int i;
//	int j;
	int N, A[MAXSIZE];
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
	{
		if (i != N - 1)
			scanf("%d ", &A[i]);
		else
			scanf("%d", &A[i]);
	}

	MaxSum = MaxSubsequenceSum4(A,N);
	//for (i = 0; i < N; i++)
	//{
	//	ThisSum = 0;
	//	for (j = i; j < N; j++)
	//	{
	//		ThisSum += A[j];
	//		if (ThisSum > MaxSum)
	//			MaxSum = ThisSum;
	//	}
	//}
	printf("%d", MaxSum);
	return 0;
}
int MaxSubsequenceSum3(int A[],int left,int right)
{
	int center;
	int MaxLeftCrossing, MaxRightCrossing;
	int MaxLeft, MaxRight;
	int SumLeft, SumRight;
	int Max;
	MaxRightCrossing = MaxLeftCrossing= 0;
	SumLeft = SumRight= 0;
	if (left == right)
	{
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	}
	center = (left + right) / 2;
	MaxLeft = MaxSubsequenceSum3(A, left, center);
	MaxRight = MaxSubsequenceSum3(A, center + 1, right);//center要加1 这样元素才不会重合
	for (int i = center; i >= left; i--) {
		SumLeft += A[i];
		if (SumLeft >= MaxLeftCrossing)
			MaxLeftCrossing = SumLeft;
	}
	for (int i = center+1; i <= right; i++) {
		SumRight += A[i];
		if (SumRight >= MaxRightCrossing)
			MaxRightCrossing = SumRight;
	}
	Max = MaxLeft > MaxRight ? MaxLeft : MaxRight;
	Max = Max > (MaxLeftCrossing + MaxRightCrossing) ? Max : (MaxLeftCrossing + MaxRightCrossing);
	return Max;
	
}
int MaxSubsequenceSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	ThisSum = 0;
	MaxSum = 0;
	for (int i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		if (ThisSum < 0)
		ThisSum = 0;//抛弃本列
	}
	return MaxSum;
	
}