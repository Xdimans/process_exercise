//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//#define MAX_SIZE 12
//char b[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//typedef struct stack {
//	int stack[MAX_SIZE];
//	int length;
//}Stack;
//Stack* initStack()
//{
//	Stack* a;
//	a = (Stack*)malloc(sizeof(Stack));
//	if (a == NULL)
//		exit(0);
//	a->length = 0;
//	return a;
//}
//bool isEmpty(Stack* a)
//{
//	return a->length == 0;
//}
//bool isFull(Stack* a)
//{
//	return a->length >= MAX_SIZE;
//}
//bool push(Stack* a, int tmp)
//{
//	if (isFull(a)) return false;
//	a->stack[(a->length)++] = tmp;
//	return true;
//}
//bool pop(Stack* a, int& tmp)
//{
//	if (isEmpty(a)) return false;
//	tmp = a->stack[a->length - 1];
//	(a->length)--;
//	return true;
//}
//bool getTop(Stack* a, int& tmp)
//{
//	if (isEmpty(a))return false;
//	else tmp = a->stack[a->length - 1];
//	return true;
//}
//void deleteStack(Stack* a)
//{
//	delete a;
//}
//void change(int number,int n)
//{
//	Stack * a=initStack();
//	int tmp = number % n;
//	number /= n;
//	push(a, tmp);
//	while (number>0)
//	{
//		tmp = number % n;
//		number /= n;
//		push(a, tmp);
//	}
//	while (!isEmpty(a))
//	{
//		pop(a, tmp);
//		if (n == 16)
//			printf("%c", b[tmp]);
//		else
//		printf("%d", tmp);
//	}
//}
//int main()
//
//{
//	int n;
//	scanf("%d", &n);
//	printf("二进制"); change(n, 2); printf(",");
//	printf("八进制"); change(n, 8); printf(",");
//	printf("十六进制"); change(n, 16); printf("。");
//	return 0;
//}