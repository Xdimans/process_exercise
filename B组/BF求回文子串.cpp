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
		//���˸�������ֹ�±�Խ��
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
	printf("��������������Ӵ��ĳ���:%d\n", max1*2-1);
	//��������max1�������  ����-�������+1��Ϊ����l��r�ĳ�����Ҫ*2-1
	printf("ż������������Ӵ��ĳ���:%d\n", max2);

	printf("������Ӵ��ĳ���:%d", max1 > max2 ? max1 : max2);
	return 0;
}