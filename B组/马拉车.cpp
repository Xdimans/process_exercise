#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
char A[11] = "ABCBACCABC";
int main()
{
	char B[25];//�洢���ݱ���
	int C[25];//�洢����Ĵ�
	B[0] = '$';
	int index = 1;
	for (int i = 0; i < strlen(A)-1; i++)
	{
		B[index++] = A[i];
		B[index++] = '$';
	} //��������֮����԰�
	B[index] = '/0';
	int max = 0;
	int l = 0, r = -1;//�洢�������ĵ�һ�����Ĵ��������յ�
	for (int i = 0; i < index; i++)
	{
		int j = l + r - i; //���������һ�����Ĵ����ĵĶԳƵ�
		if (i > r) //���˵��ǰ���ݵ�λ�ó��������ĵ�һ�����Ĵ����յ�
		{
			C[i] = 1;
			while (B[i - C[i]] == B[i + C[i]])
				C[i]++;
			l = i - C[i] + 1;
			r = i + C[i] - 1;
			if (C[i] > max)
				max = C[i];
		}
		else if (j>=0&&j - C[j] >= l) //�����ǰ��ĶԳƵ�Ļ��Ĵ�����ȫ����������һ�����Ĵ����ڲ�
		{
			C[i] = C[j];

		}
		else //�����ǰ��ĶԳƵ�Ļ��Ĵ���һ���ֳ���������һ�����Ĵ��ı۳���Χ
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
	printf("����Ĵ�����:%d", max - 1);
	return 0;
}