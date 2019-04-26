#include <stdio.h>
#include <stdbool.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
	ElementType Data;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuilTree(void);
bool Isomorphic(ElementType T1, ElementType T2);

int main()
{
	Tree T1, T2;
	T1 = BuilTree;
	T2 = BuilTree;
	if (Isomorphic)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}