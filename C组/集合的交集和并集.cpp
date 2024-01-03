//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//#define MAX_SIZE 50
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
//	head->prev = head;
//	head->next = head;
//	return head;
//}
//void write(Node*& head)
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
//	tail->next = head;
//	head->prev = tail;
//}
//void getInter(Node* a,Node* b) { //交集
//	Node* A = a->next;
//	int arr[MAX_SIZE * 2];
//	int index = 0;
//	while (A!= a)
//	{
//		Node* tmp = b->next;
//		while (tmp!= b)
//		{
//			if (A->data == tmp->data)
//				arr[index++] = A->data;
//			tmp = tmp->next;
//
//		}
//		A = A->next;
//	}
//	printf("{");
//	for (int i = 0; i < index; i++)
//	{
//		if (i != index - 1)
//			printf("%d ,", arr[i]);
//		else printf("%d ", arr[i]);
//	}
//	printf("}");
//}
//void getUnion(Node* a, Node* b) {//并集
//	int arr[MAX_SIZE * 2];
//	int index = 0;
//	Node* A = a->next;
//	while (A!= a)
//	{
//		arr[index++] = A->data;
//		A = A->next;
//	}
//	Node* B = b->next;
//	while (B!= b)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			if (arr[i] == B->data)
//				goto link;
//		}
//		arr[index++] = B->data;
//	link:
//		B = B->next;
//	}
//	printf("{");
//	for (int i = 0; i < index; i++)
//	{
//		if (i != index - 1)
//			printf("%d ,", arr[i]);
//		else printf("%d ", arr[i]);
//	}
//	printf("}");
//}
//void freeList(Node* head)
//{
//	head->prev->next = NULL;
//	head->prev = NULL;
//	while (head ->next!=NULL)
//	{
//		Node* next = head->next;
//		free(head);
//		head = next;
//	}
//}
///*
//5
//1 2 3 4 5
//5
//3 4 5 6 7
//
//
//5
//8 9 10 11 12
//5
//10 11 12 13 14
//
//*/
//
//int main()
//{
//
//	Node* par = creatList();
//	Node* kid = creatList();
//	write(par);
//	write(kid);
//	getInter(par, kid);
//	getUnion(par, kid);
//	freeList(par);
//	freeList(kid);
//	return 0;
//}