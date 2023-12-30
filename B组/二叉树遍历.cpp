#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define ElemType int
#define MAX_SIZE 500
typedef struct node
{
	ElemType data;
	int lchild;
	int rchild;
} BTNode;
typedef struct stack {
	BTNode stack[MAX_SIZE];
	int length;
}Stack;
Stack* initStack()
{
	Stack* a;
	a = (Stack*)malloc(sizeof(Stack));
	if (a == NULL)
		exit(0);
	a->length = 0;
	return a;
}
bool isEmpty(Stack* a)
{
	return a->length == 0;
}
bool isFull(Stack* a)
{
	return a->length >= MAX_SIZE;
}
bool push(Stack* a, BTNode tmp)
{
	if (isFull(a)) return false;
	a->stack[(a->length)++] = tmp;
	return true;
}
bool pop(Stack* a, BTNode& tmp)
{
	if (isEmpty(a)) return false;
	tmp = a->stack[a->length - 1];
	(a->length)--;
	return true;
}
bool getTop(Stack* a, BTNode& tmp)
{
	if (isEmpty(a))return false;
	else tmp = a->stack[a->length - 1];
	return true;
}
void deleteStack(Stack* a)
{
	delete a;
}
void creatNode(BTNode base[])
{
	int n;
	scanf("%d", &n);
	base[0].data = base[0].lchild = base[1].rchild = 0;
	for (int i = 0; i < n; i++)
	{
		int Base, left, right;
		scanf("%d %d %d", &Base, &left, &right);
		base[Base].data = Base;
		if(left==-1)
			base[Base].lchild = 0;
		else
			base[Base].lchild = left;
		if(right==-1)
			base[Base].rchild = 0;
		else
			base[Base].rchild = right;

	}
}
void prePrint(BTNode base[])
{
	printf("先序遍历序列:");
	BTNode tmp;
	Stack* a = initStack();
	if (base[1].data!=0)
	{
		push(a, base[1]);
		while (!isEmpty(a))
		{
			pop(a, tmp);
			printf("%d ", tmp.data);
			if (tmp.rchild != 0)
				push(a, base[tmp.rchild]);
			if (tmp.lchild != 0)
				push(a, base[tmp.lchild]);
		}
	}
	puts("");
	deleteStack(a);
}
void midPrint(BTNode base[]) {
	printf("中序遍历序列:");
	BTNode tmp = base[1];
	Stack* a = initStack();

	while (tmp.data!=0 || !isEmpty(a))
	{
		while (tmp.data != 0)
		{
			push(a, tmp);
			tmp = base[tmp.lchild];
		}

		if (!isEmpty(a))
		{
			pop(a, tmp);
			printf("%d ", tmp.data);
			tmp = base[tmp.rchild];
		}
	}
	puts("");
	deleteStack(a);
}
void postPrint(BTNode* base)
{
	printf("后序遍历序列:");
	BTNode tmp = base[1];
	int pre;
	bool flag = false;
	Stack* a = initStack();
	do {
		while (tmp.data!= 0)
		{
			push(a, tmp);
			tmp = base[tmp.lchild];
		}
		pre = 0;
		flag = true;//应该处理栈顶
		while (!isEmpty(a) && flag)
		{
			getTop(a, tmp);
			if (tmp.rchild == pre)
			{
				printf("%d ", tmp.data);
				pop(a, tmp);
				pre = tmp.data;
			}
			else
			{
				tmp = base[tmp.rchild];
				flag = false;
			}
		}

	} while (!isEmpty(a));
	puts("");
	deleteStack(a);
}
/*
8
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1
6 -1 -1
7 -1 -1
8 -1 -1

*/
	int main()
		 {
	BTNode base[MAX_SIZE];
	creatNode(base);
	prePrint(base);
	midPrint(base);
	postPrint(base);
	return 0;
}