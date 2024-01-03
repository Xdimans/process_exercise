//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//void getNext(int*& next,char * kid)
//{
//	int i = 0;
//	int j = -1;
//	next[0] = -1;
//	while (i < strlen(kid))
//	{
//		if (j == -1 || kid[i] == kid[j])
//		{
//			next[++i] = ++j;
//		}
//		else
//			j = next[j];
//	}
//}
///*
//ababcabcacbab
//agcac
//
//ababcabcacbab
//abcac
//
//
//hello world
//world
//
//*/
//int main()
//{
//	char par[50];
//	char kid[50];
//	int* next = (int*)malloc(sizeof(int) * 50);
//	scanf("%[^\n]", par);
//	getchar();
//	scanf("%[^\n]", kid);
//	getNext(next,kid);
//	int i = 0;
//	int j = 0;
//	while (i < (int)strlen(par) && j < (int)strlen(kid))
//	{
//		if (j == -1||par[i] == kid[j])
//		{
//			i++;
//			j++;
//		}
//		else
//			j = next[j];
//	}
//	if (j < (int)strlen(kid))
//		printf("²»ÊÇ×Ó´®");
//	else
//	printf("%d", i - j);
//	return 0;
//}