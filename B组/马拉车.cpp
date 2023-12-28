#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
char A[11] = "ABCBACCABC";
int main()
{
	char B[25];//存储数据本身
	int C[25];//存储最长回文串
	B[0] = '$';
	int index = 1;
	for (int i = 0; i < strlen(A)-1; i++)
	{
		B[index++] = A[i];
		B[index++] = '$';
	} //这样操作之后可以把
	B[index] = '/0';
	int max = 0;
	int l = 0, r = -1;//存储的是左侧的第一个回文串的起点和终点
	for (int i = 0; i < index; i++)
	{
		int j = l + r - i; //相对于左侧第一个回文串中心的对称点
		if (i > r) //如果说当前数据的位置超过了左侧的第一个回文串的终点
		{
			C[i] = 1;
			while (B[i - C[i]] == B[i + C[i]])
				C[i]++;
			l = i - C[i] + 1;
			r = i + C[i] - 1;
			if (C[i] > max)
				max = C[i];
		}
		else if (j>=0&&j - C[j] >= l) //如果当前点的对称点的回文串被完全包裹在左侧第一个回文串的内部
		{
			C[i] = C[j];

		}
		else //如果当前点的对称点的回文串有一部分超出了左侧第一个回文串的臂长范围
		{
			C[i] = j - l+1;
			while (B[i - C[i]] == B[i + C[i]])
				C[i]++;
			l = i - C[i] + 1;
			r = i + C[i] - 1;
			if (C[i] > max)
				max = C[i];
		}
	}
	for (int i = 0; i < index; i++)
	{
		printf("%c ", B[i]);
	}
	puts("");
	for (int i = 0; i < index; i++)
		printf("%d ", C[i]);
	puts("");
	printf("最长回文串长度:%d", max - 1);
	return 0;
}