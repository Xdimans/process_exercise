#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define MAX_SIZE 500
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
int main()
{
	int n;
	int cut = 0;
	scanf("%d", &n);
	int a[MAX_SIZE];
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int d = 2;
	while (d <= n)
	{
		for (int i = 0; i + d <= n; i += d)
		{
			for (int j = i; j < i + d; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					cut++;
				}
			}
		}
		d++;
	}
	printf("%d", cut);
	return 0;
}