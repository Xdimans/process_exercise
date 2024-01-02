//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int cnt[4] = { 0,0,0,0 };
//		while (n >= 25)
//		{
//			cnt[0]++;
//			n -= 25;
//		}
//		printf("%d个 25 分",cnt[0]);
//		if (n > 0)
//		{
//			printf("和");
//
//
//			while (n >= 10)
//			{
//				cnt[1]++;
//				n -= 10;
//			}
//			printf(" %d 个 10 分", cnt[1]);
//			if (n > 0)
//			{
//				printf("和");
//
//
//				while (n >= 5)
//				{
//					cnt[2]++;
//					n -= 5;
//				}
//				printf(" %d 个 5 分", cnt[2]);
//				if (n > 0)
//				{
//					printf("和");
//
//
//					while (n >= 1)
//					{
//						cnt[3]++;
//						n -= 1;
//					}
//					printf(" %d 个 1 分", cnt[2]);
//				}
//			}
//		}
//		printf("硬币。");
//	return 0;
//}