//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//void change(char*& str)
//{
//	while (*str == ' ')
//		str = str+1;
//	int i = strlen(str) - 1;
//	while (i>=1 &&*(str+i) == ' ')
//	{
//		i--;
//	}
//	str[i+1] = '\0';
//	i = 0;
//	int cut = 0;
//	while (i <= strlen(str)-1)
//	{
//		while (*(str + i) == *(str + i + 1) && *(str + i) == ' ')
//		{
//			i++;
//			cut++;
//		}
//		str[i-cut] = str[i];
//		i++;
//	}
//	str[i - cut] = '\0';
//	printf("%s", str);
//}
///*
//              This      is   an example sentence.                  
//This is an example sentence.
//
//     Hello    world!    
//Hello world!
//*/
//int main()
//{
//	char *str=(char*)malloc(sizeof(char)*100);
//	char *tmp = str;
//	scanf("%[^\n]", str);
//	change(str);
//	free(tmp);
//	return 0;
//}