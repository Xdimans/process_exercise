//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//typedef struct node
//{
//	int data;
//	struct node* next;
//}Node;
//Node* creat()
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	if (head == NULL)
//		exit(0);
//	head->data = -1;
//	head->next = NULL;
//	return head;
//}
//void write(Node*& head)
//{
//	int n;
//	scanf("%d", &n);
//	Node* tail = head;
//	for (int i = 0; i < n; i++)
//	{
//		Node* tmp = creat();
//		if (i != n - 1)
//		{
//			scanf("%d �� ", &tmp->data);
//		}
//		else scanf("%d", &tmp->data);
//		tail->next = tmp;
//		tail = tmp;
//	}
//}
//Node* devide(Node*& head)
//{
//	Node* head2 = creat();
//	Node* head1 = head2;
//	Node* tmp = head->next;
//	while (tmp!=NULL&&tmp->next!= NULL)
//	{
//			head1->next = tmp->next;
//			tmp->next = tmp->next->next;
//			head1->next->next = NULL;
//		head1 = head1->next;
//		tmp = tmp->next;
//	}
//	return head2;
//}
//void printList(Node* head)
//{
//	Node* tmp = head->next;
//	while (tmp != NULL)
//	{
//		printf("%d", tmp->data);
//		if (tmp->next != NULL)
//			printf(" �� ");
//		tmp = tmp->next;
//	}
//	puts("");
//}
//void freeList(Node*& head)
//{
//	while (head != NULL)
//	{
//		Node* next = head->next;
//		free(head);
//		head = next;
//	}
//}
///*
//10
//1 �� 2 �� 3 �� 4 �� 5 �� 6 �� 7 �� 8 �� 9 �� 10
//
//10
//11 �� 12 �� 13 �� 14 �� 15 �� 16 �� 17 �� 18 �� 19 �� 20
//
//*/
//int main()
//{
//	Node* head = creat();
//	write(head);
//	Node* head1 = devide(head);
//	printf(" L1 = ");
//	printList(head);
//	printf(" L2 = ");
//	printList(head1);
//	freeList(head);
//	freeList(head1);
//	return 0;
//}