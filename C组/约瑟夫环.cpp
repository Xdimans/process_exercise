#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
}Node;
Node* creatList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
		exit(0);
	head->next = NULL;
	head->prev = NULL;
	return head;
}
void write(Node* head)
{
	int n;
	printf("输入总长:");
	scanf("%d", &n);
	Node* tail = head;
	head->data = 0;
	for (int i = 1; i < n; i++)
	{
		Node* tmp= (Node*)malloc(sizeof(Node));
		if (tmp == NULL)
			exit(0);
		tmp->next = NULL;
		tmp->data = i;
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
	tail->next = head;
	head->prev = tail;
}
void judge(Node* head)
{
	int between;
	printf("\n输入间隔:");
	scanf("%d", &between);
	Node* tmp = head;
	while (tmp != NULL&&tmp->next!=tmp)
	{
		if (tmp->next != tmp)//如果说不是最后一个
		{
			printf("%d ", tmp->data);
			Node* dele = tmp;
			tmp = tmp->prev;
			tmp->next = dele->next;
			dele->next->prev = tmp;
			free(dele);
		}
		for (int i = 0; i < between; i++)
		{
			if (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			else
				break;
		}

	}
	printf("最后的人是%d", tmp->data);
	free(tmp);
}
int main()
{

	Node* base = creatList();
	Node* tmp = base;
	write(base);
	judge(base);
	return 0;
}