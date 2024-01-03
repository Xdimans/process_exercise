//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//bool judge(char * a)
//{
//	int length = strlen(a) - 1;
//	char b[50];
//	int index = 0;
//	int i = 0;
//	for(int j=0;j<=length;j++)
//	{
//		if (a[j] != (char)('a' + j))
//		{
//			b[index++] = 'a'+j;
//		}
//		else if (a[j] == (char)('a' + j))
//			i++;
//	}
//	while (index >0 && i <=length )
//	{
//		if (b[index-1] ==a[i])
//		{
//			index--;
//		}
//		i++;
//	}
//	if (index == 0)
//		return true;
//	return false;
//}
///*
//aebcd
//
//abcde
//
//*/
//int main()
//{
//	char a[100];
//	scanf("%s", a);
//	if (judge(a))
//		printf("是合法的出栈序列");
//	else printf("不是合法的出栈序列");
//	return 0;
//}