//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//typedef struct node
//{
//	int data;
//	struct node* next;
//	struct node* prev;
//}Node;
//Node* creatList()
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL)
//		exit(0);
//	head->prev = NULL;
//	head->next = NULL;
//	return head;
//}
//void write(Node* head)
//{
//	int n;
//	scanf("%d", &n);
//
//	Node* tail = head;
//	for (int i = 0; i < n; i++)
//	{
//		Node* tmp= (Node*)malloc(sizeof(Node));
//		if (tmp == NULL)
//			exit(0);
//		tmp->next = NULL;
//		tmp->prev = NULL;
//		scanf("%d", &tmp->data);
//		tail->next = tmp;
//		tmp->prev = tail;
//		tail = tmp;
//	}
//}
//bool judge(Node* par, Node* kid)
//{
//	if (par != NULL && kid != NULL)
//	{
//		bool res = false;
//		Node* i = par->next;
//		Node* j = kid->next;
//		if (i == NULL || j == NULL)
//		{
//			res = false;
//			goto link;
//		}
//		while (i != NULL && j!= NULL)
//		{
//			if (i->data == j->data)
//			{
//				i = i->next;
//				j = j->next;
//			}
//			else
//				break;
//			
//		}
//		if (j == NULL)
//			res = true;
//		link:
//		if (res == true)
//			return res;
//		else
//		{
//			return judge(par->next, kid);
//		}
//	}
//	return false;
//}
//void freeList(Node* head)
//{
//	while (head != NULL)
//	{
//		Node* next = head->next;
//		free(head);
//		head = next;
//	}
//}
///*
//5
//1 2 3 4 5
//2
//2 3
//
//4
//1 3 5 7
//3
//1 2 3
//
//*/
//int main()
//{
//
//	Node* par = creatList();
//	Node* kid = creatList();
//	write(par);
//	write(kid);
//	if (judge(par, kid) == true)
//		printf("是子序列");
//	else
//		printf("不是子序列");
//	freeList(par);
//	freeList(kid);
//	return 0;
//}