#pragma warning(disable:4996)
#include<stdio.h>
#include<ostream>
using namespace std;
int main()
{
	int i=0;
	int a[3];
	int j = 3;
	while (j)
	{
		scanf("%d", &a[i]);
		i++;
		j--;
	}
	while (i < 3)
	{
		printf("%d", a[i]);
		i++;
	}

	system("pause");
	return 0;
}