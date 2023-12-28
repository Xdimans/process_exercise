#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
char A[11] = "ABCBACCABC";
int main()
{
	int B[11];
	int n = 10;
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < 11; i++)
	{
		B[i] = 0;
		//加了个条件防止下标越界
		while (i-B[i]>=0&&i+B[i]<11&&A[i - B[i]] == A[i + B[i]])
			B[i]++;
		if (B[i] > max1)
			max1 = B[i];
	}
	for (int i = 0; i < 11; i++)
	{
		int tmp = 1;
		if (i < 10)
		{
			int nexti = i + 1;
			tmp++;
			while (i-tmp/2>=0&&i+tmp/2<11&&A[i - tmp / 2] == A[nexti + tmp / 2])
				tmp += 2;
		}
		if (tmp > max2)
			max2 = tmp;
	}
	printf("奇数串的最长回文子串的长度:%d\n", max1*2-1);
	//奇数串的max1代表的是  中心-左侧坐标+1，为了求l到r的长度需要*2-1
	printf("偶数串的最长回文子串的长度:%d\n", max2);

	printf("最长回文子串的长度:%d", max1 > max2 ? max1 : max2);
	return 0;
}