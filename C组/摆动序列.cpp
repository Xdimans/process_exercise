//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//#define MAX_SIZE 500
//int main()
//{
//	int arr[MAX_SIZE];
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	int flag = -1;
//	int length = 1;
//	for (int i = 1; i < n; i++)
//	{
//		if (flag==-1)
//		{
//			if (arr[i] > arr[i - 1])
//			{
//				length++;
//				flag = 1;
//			}
//			if (arr[i] < arr[i - 1])
//			{
//				length++;
//				flag = 0;
//			}
//		}
//		if (arr[i] > arr[i - 1] && flag == 0)
//		{
//			length++;
//			flag = 1;
//		}
//		if (arr[i] < arr[i - 1] && flag == 1)
//		{
//			length++;
//			flag = 0;
//		}
//	}
//	if (length == n)
//		printf("�ǰڶ����С�");
//	else
//	{
//		printf("�ǰڶ����У���Ҫɾ�� %d ��Ԫ�ء�", n - length);
//	}
//	return 0;
//}