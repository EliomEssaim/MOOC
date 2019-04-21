#pragma warning(disable:4996)
#include <stdio.h>
#define MAXSIZE 100000
int MaxSubsequenceSum3(int A[], int left, int right);
int MaxSubsequenceSum4(int A[], int N, int *head, int *rear);
int main(void)
{
	int MaxSum;
	//	int ThisSum;
	int i;
	//	int j;
	int N, A[MAXSIZE];
	int head, rear;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
	{
		if (i != N - 1)
			scanf("%d ", &A[i]);
		else
			scanf("%d", &A[i]);
	}

	MaxSum = MaxSubsequenceSum4(A, N, &head, &rear);
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
	if (MaxSum >= 0)
		printf("%d %d %d", MaxSum, A[head], A[rear]);
	else
		printf("%d %d %d", 0, A[0], A[N-1]);
			
			
	return 0;
}
int MaxSubsequenceSum3(int A[], int left, int right)
{
	int center;
	int MaxLeftCrossing, MaxRightCrossing;
	int MaxLeft, MaxRight;
	int SumLeft, SumRight;
	int Max;
	MaxRightCrossing = MaxLeftCrossing = 0;
	SumLeft = SumRight = 0;
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
	for (int i = center + 1; i <= right; i++) {
		SumRight += A[i];
		if (SumRight >= MaxRightCrossing)
			MaxRightCrossing = SumRight;
	}
	Max = MaxLeft > MaxRight ? MaxLeft : MaxRight;
	Max = Max > (MaxLeftCrossing + MaxRightCrossing) ? Max : (MaxLeftCrossing + MaxRightCrossing);
	return Max;

}
int MaxSubsequenceSum4(int A[], int N,int *head,int *rear)
{
	int ThisSum, MaxSum;
	int head_tmp = 0;
	ThisSum = 0;
	MaxSum = -1;

	*head = 0;
	*rear = 0;
	for (int i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			*head = head_tmp;
			MaxSum = ThisSum;
			*rear = i;//尾检测
		}
			
		if (ThisSum < 0) {
			ThisSum = 0;//抛弃本列
			head_tmp = i + 1;
			
		}
			
	}
	return MaxSum;

}
//我的思考：检测 哪里是头 哪里是尾 什么时候更新
//优秀：在哪里会更新？这里写头尾
//考虑不周到 会有0 0在前头 输入最小