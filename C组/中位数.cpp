//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//void merge(double* arr1, double* arr2,int n)
//{
//	double* a = (double*)malloc(sizeof(double) * 100);
//	if (a == NULL)exit(0);
//	int index = 0;
//	int i = 0;
//	int j = 0;
//	while (i < n && j < n)
//	{
//		if (arr1[i] < arr2[j])
//			a[index++] = arr1[i++];
//		else a[index++] = arr2[j++];
//	}
//	while (i < n)
//		a[index++] = arr1[i++];
//
//	while (j < n)
//		a[index++] = arr2[j++];
//	double tmp = ((a[n] + a[n - 1]) / 2);
//	printf("%.1lf", tmp);
//}
//void Known(double* arr1, double* arr2, int n)
//{
//	if (n == 1)
//	{
//		printf("%.1lf", (arr1[0] + arr2[0]) / 2);
//	}
//	if (n > 1)
//	{
//		double mid1;
//		double mid2;
//		if (n % 2 == 1) //�����������
//		{
//			mid1 = arr1[n / 2];
//			mid2 = arr2[n / 2];
//		
//		}
//		else
//		{
//			mid1 = (arr1[n / 2] + arr1[n / 2 - 1]) / 2;
//			mid2 = (arr2[n / 2] + arr2[n / 2 - 1]) / 2;
//		}
//			if (mid1 > mid2)//���mid1����mid2����ô�޳�arr1�д���mid1�Ĳ���,�޳�arr2��С��mid2�Ĳ���
//			{
//				Known(arr1 + (n / 2), arr2, n - n / 2);
//			}
//			else if(mid2>mid1)
//				Known(arr1, arr2 + (n / 2), n - n / 2);
//			else
//			{
//				printf("%.1lf", mid1);
//				return;
//			}
//
//
//	}
//}
///*
//5
//1 3 5 7 9
//2 4 6 8 10
//
//
//5
//11 13 15 17 19
//2 4 6 8 20
//
//*/
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	double arr1[50];
//	double arr2[50];
//	for (int i = 0; i < n; i++)
//		scanf("%lf", &arr1[i]);
//	for (int i = 0; i < n; i++)
//		scanf("%lf", &arr2[i]);
//	puts("");
//	Known(arr1, arr2, 5);
//	return 0;
//}