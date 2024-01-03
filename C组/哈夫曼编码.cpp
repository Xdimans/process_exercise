//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<bits/stdc++.h>
//#define ElemType char
//#define MAX_SIZE 20
//typedef struct node
//{
//	int parent;
//	char data;
//	double weight;
//	int leftChild;
//	int rightChild;
//} HT;
//typedef struct code
//{
//	int start;
//	char code[MAX_SIZE];
//}HC;
//void creatTree(HT ht[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ht[i].parent = -1;
//		ht[i].leftChild = -1;
//		ht[i].rightChild = -1;
//	}
//
//	for (int i = n; i < 2 * n - 1; i++)
//	{
//		double minL = 1000000, minR = 10000000;
//		int minNodeLeft = -1, minNodeRight = -1;
//		for (int j = 0; j < i; j++) {
//			if (ht[j].parent == -1)
//			{
//				if (ht[j].weight < minL)
//				{
//					minR = minL; minNodeRight = minNodeLeft;
//					minL = ht[j].weight; minNodeLeft = j;
//				}
//				else if (ht[j].weight < minR)
//				{
//					minR = ht[j].weight; minNodeRight = j;
//				}
//			}
//		}
//		ht[i].weight = minR + minL;
//		ht[i].leftChild = minNodeLeft;
//		ht[i].rightChild = minNodeRight;
//		ht[i].parent = -1;
//		ht[minNodeLeft].parent = i;
//		ht[minNodeRight].parent = i;
//
//	}
//}
//void creatCode(HT ht[], HC hc[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		HC tmp;
//		tmp.start = n;
//		int c = i;
//		int p = ht[i].parent;
//		while (p != -1)
//		{
//			if (ht[p].leftChild == c)
//				tmp.code[tmp.start--] = '0';
//			else
//				tmp.code[tmp.start--] = '1';
//			c = p;
//			p = ht[p].parent;
//		}
//		tmp.start++;
//		hc[i] = tmp;
//	}
//}
//void printCode(HC hc, int n)
//{
//	for (int i = hc.start; i <= n; i++)
//		printf("%c", hc.code[i]);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	HT ht[MAX_SIZE];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &(ht[i].weight));
//		ht[i].data = 'a' + i;
//	}
//	creatTree(ht, n);
//	HC hc[MAX_SIZE];
//	creatCode(ht, hc, n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%c:", ht[i].data);
//		printCode(hc[i], n);
//		puts("");	
//	}
//	return 0;
//}
//
