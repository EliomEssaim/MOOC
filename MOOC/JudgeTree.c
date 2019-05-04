#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"
#include "string.h"
typedef struct TreeNode *Tree;
struct TreeNode {
	int node;
	Tree left;
	Tree right;
	bool flag;
};
Tree NewNode(int val)
{
	Tree t;
	t = (Tree)malloc(sizeof(struct TreeNode));
	t->left = NULL;
	t->right = NULL;
	t->flag = 0;

	return t;
}
Tree Insert(Tree t, int data)//insert不熟悉：不够理解递归流程和思想
{
	if (t == NULL)
	{
		t = NewNode(data);
	}
	else
	{
		if (t->node > data)
			t->left = Insert(t->left, data);
		else 
			t->right = Insert(t->right, data);//如果相等也进入这个程序？？？？

	}
		
	return t;
}
Tree MakeTree(int n)
{
	Tree t;
	int val;
	//根节点不一致第一个要先拿出来 //反思1: 初始化不在这里
	scanf("%d", &val);
	t = NewNode(val);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", val);
		t = Insert(t, val);
	}
	return t;
}
int Check(Tree t, int data)
{
	if (!t->flag)
	{
		t->flag = 1;

	}
}
int main()
{
	int N, L;
	Tree T;
	scanf("%d", &N);
	while (N)
	{
		scanf("%d", &L);
		T = MakeTree(N);
		
		for (int i = 0; i < L; i++)
		{
			if (Judge())
				printf("Yes\n");
			else
				printf("No\n");
			ResetFlag();
		}
		FreeTree();//想不到= =，因为不限制次数所以每一轮判断后要清除数据
		scanf("%d", &N);
	}

/*	//读基准树
		准备：树的存储方式：链式 (数据类型为整数 其他为左右子树和flag)
		读入：先给根分配一个空间 读入N循环后判断 大于根则 丢给右小于反之 利用查找找到合适的位置递归返回自己的指针

	//		
	//比较两树 每读一个比较树查找一下 在基准树的位置 查过了用flag标记节点 如果下一次遇到了flag为0（未被搜索）则返回0 
	再设置一个小flag防止过早结束  最后清除所有flag输出结果
	//
*/
	return 0;
}
/*
反思1：写不出来-》建立一棵树莫得思路-》复现场景：大概就是一个一个放进去 太粗放的思考-》流程化思考：
能得到什么？
需要作出什么？
第一步？-》卡在这里-》对于当前场景的建树没有思路：-》没有建树的基本思路（模板）：无根之浮萍自然无处思考  可以不通过模板想出来吗？（2）-》 一定要独立手码一下结构
（2）：简单的可以不假思考的写出来 复杂的不行= = 。对我来说目前简单的就是小小的逻辑判断

搞不清楚这个函数要做什么这个函数存在的意义
*/