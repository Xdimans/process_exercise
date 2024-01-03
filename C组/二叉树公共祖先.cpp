//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//typedef struct node
//{
//	char data;
//	struct node* lchild;
//	struct node* rchild;
//}Node;
//
//Node* creatTree(char tree[],int i)
//{
//	if (i <= strlen(tree) - 1&&tree[i]!='#')
//	{
//		Node* base = (Node*)malloc(sizeof(Node));
//		if (base == NULL)exit(0);
//		if(tree[i]!='#')
//			base->data = tree[i];
//		else
//			base->data = NULL;
//		base->lchild = creatTree(tree, 2 * i);
//		base->rchild = creatTree(tree, 2 * i + 1);
//		return base;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//bool judgeAn(Node* base, char a)
//{
//	if (base != NULL)
//	{
//		if (base->lchild != NULL || base->rchild != NULL)
//		{
//			if (base->lchild != NULL)
//			{
//				if (base->lchild->data == a)
//					return true;
//				if(judgeAn(base->lchild, a))
//				return true;	
//			}
//			if (base->rchild != NULL)
//			{
//				if (base->rchild->data == a)
//					return true;
//				if(judgeAn(base->rchild, a))
//					return true;
//			}
//			
//		}
//	}
//	return false;
//}
//bool judgeAn(char tree[],int i, char a)
//{
//	if (i <= strlen(tree) - 1 && tree[i] != '#')
//	{
//		if ((2*i<strlen(tree)&&tree[2*i] != '#') ||( (2 * i+1) < strlen(tree) && tree[2 * i + 1] != '#'))
//		{
//			if (2 * i < strlen(tree) && tree[2 * i] != '#')
//			{
//				if (tree[2 * i] == a)
//					return true;
//				if (judgeAn(tree, 2 * i, a))
//					return true;
//			}
//			if ((2 * i + 1) < strlen(tree) && tree[2 * i + 1] != '#')
//			{
//				if (tree[2 * i + 1] == a)
//					return true;
//				if (judgeAn(tree, 2 * i + 1, a))
//					return true;
//			}
//
//		}
//	}
//	return false;
//}
//int findAn(Node* base,char a,char b)
//{
//	if (base != NULL)
//	{
//		findAn(base->lchild, a, b);
//		findAn(base->rchild, a, b);
//		if (judgeAn(base, a) && judgeAn(base, b))
//		{
//			//a是H     b是E
//			bool flag1 = ((judgeAn(base->lchild, a) || base->lchild->data == a) + (judgeAn(base->lchild, b) || base->lchild->data == b) == 1);
//			bool flag2 = ((judgeAn(base->rchild, a) || base->rchild->data == a) + (judgeAn(base->rchild, b) || base->rchild->data == b) == 1);
//			bool flag = (flag1 && flag2);
//			if (flag)
//			{
//				printf("%c和%c的最近公共祖先是%c",a,b, base->data);
//			}
//			return true;
//		}
//
//			return false;
//	}
//	return false;
//}
//int findAn(char tree[],int i,char a,char b)
//{
//	if (i <= strlen(tree) - 1 && tree[i] != '#')
//	{
//		findAn(tree,2*i, a, b);
//		findAn(tree,2*i+1, a, b);
//		if (judgeAn(tree,i, a) && judgeAn(tree,i, b))
//		{
//			//a是H     b是E
//			bool flag1 = ((judgeAn(tree,2*i, a) || tree[2*i] == a) + (judgeAn(tree,2*i, b) || tree[2*i] == b) == 1);
//			bool flag2 = ((judgeAn(tree,2*i+1, a) || tree[2*i+1] == a) + (judgeAn(tree,2*i+1, b) || tree[2*i+1] == b) == 1);
//			bool flag = (flag1 && flag2);
//			if (flag)
//			{
//				printf("%c和%c的最近公共祖先是%c\n",a,b, tree[i]);
//			}
//			return true;
//		}
//
//		return false;
//	}
//	return false;
//}
//int main()
//{
//	char tree[50] = "0ABCDEFGH#########";
//	Node* base = creatTree(tree, 1);
//	findAn(tree, 1,  'H', 'E');//期望B
//	findAn(base, 'H', 'E');
//	return 0;
//}