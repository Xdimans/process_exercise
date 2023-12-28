#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define DATA_NUM 10 //十个个位数
#define DATA_CUT 4 //数字最多有几位
typedef struct node {
	char data[DATA_CUT+1];
	struct node* next;
}node;

void write(node* base, int n,char e[10][DATA_CUT+1])
{
	
	node* tail = base;
	base->next = NULL;
	strcpy(base->data, e[0]);
	for (int i = 1; i < n; i++)
	{
		node* tmp = (node*)malloc(sizeof(node));
		if (tmp == NULL) exit(0);
		tmp->next = NULL;
		strcpy(tmp->data, e[i]);
		tail->next = tmp;
		tail = tmp;
	}
}
void printLink(node* base)
{
	while (base != NULL) {
		bool flag = false;
		for (int i = 0; i < strlen(base->data); i++)
		{
			if (flag == false)
			{
				if (base->data[i] != '0')
				{
					printf("%c", base->data[i]);
					flag = true;
				}
			}
			else printf("%c", base->data[i]);
		}
		putchar(' ');
		base = base->next;
	}
	puts("");
}
void freeLink(node*& base)
{
	while (base != NULL)
	{
		node* tmp = base -> next;
		free(base);
		base = tmp;
	}
}
void sort(node*& base,int data_cut,int n)
{
	node* head[DATA_NUM];
	node* tail[DATA_NUM];
	node* resTail = NULL;
	for (int i = DATA_CUT-1; i >=0; i--)
	{
		for (int j = 0; j < DATA_NUM; j++)
		{
			head[j] = NULL;
			tail[j] = NULL;
		}
		while(base!=NULL)
		{
			int tmp = base->data[i] - '0';
			if (head[tmp] == NULL) {
				head[tmp] = base;
				tail[tmp] = base;
			}
			else {
				tail[tmp]->next = base;
				tail[tmp] = base;
			}
			base = base->next;

		}
		base = NULL;
		for (int j = 0; j < DATA_NUM; j++)
		{
			if (head[j] != NULL)
			{
				if (base == NULL)
				{
					base = head[j];
					resTail = tail[j];
				}
				else {
					resTail->next = head[j];
					resTail = tail[j];
				}
			}
		}
		resTail->next = NULL;
	}
}
int a[10] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
void printArray(int c[], int l, int r);
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void shell_sort(int a[],int r,int d)
{
	while (d > 0)
	{
		for (int i = d; i < r; i++)
		{
			int tmp = a[i];
			int j = i - d;
			while (j >= 0 && tmp < a[j])
			{
				a[j + d] = a[j];
				j -= d;
			}
			a[j+d] = tmp;
		}
		d /= 2;
	}
}
void quick_sort(int a[], int l, int r)
{
	if (l >= r) return;
	int i = l - 1;
	int j = r + 1;
	int mid = a[l + r >> 1];
	while (i < j)
	{
		do { i++; } while (a[i] < mid);

		do { j--; } while (a[j] > mid);

		if (i < j)
			swap(a[i], a[j]);
	}
	quick_sort(a, l, j);
	quick_sort(a, l + 1, r);
}
void sift(int a[], int now, int height) //大根堆
{
	int i = now;
	int j = 2 * now;
	while (j <= height)
	{
		if (j < height && a[j] < a[j + 1])
			j++;
		if (a[i] < a[j])
		{
			swap(a[i], a[j]);
			i = j;
			j *= 2;
		}
		else break;
	}
}
void sift_little(int a[], int now, int height) //小根堆
{
	int i = now;
	int j = 2 * now;
	while (j <= height)
	{
		if (j < height && a[j] > a[j + 1])
			j++;
		if (a[i] > a[j])
		{
			swap(a[i], a[j]);
			i = j;
			j *= 2;
		}
		else break;
	}
}
void heap_sort(int a[], int l, int r)
{
	for (int i = r/2; i >= 1; i--)
		sift(a, i, r);
	for (int i = r; i >= 2; i--)
	{
		swap(a[1], a[i]);
		sift(a, 1, i-1);
	}
}
void heap_sort_little(int a[], int l, int r)
{
	for (int i = r / 2; i >= 1; i--)
		sift_little(a, i, r);
	for (int i = r; i >=2; i--)
	{
		swap(a[1], a[i]);
		sift_little(a,1, i-1 );
	}
	for (int i = r; i >= l; i--)
		printf("%d ", a[i]);
	puts("");
}
void printArray(int c[],int l, int r)
{
	for (int i = l; i < r; i++)
	{
		printf("%d ", c[i]);
		c[i] = a[i];
	}

	puts("");
}
void merge_sort(int b[], int l, int r)
{
	if (l >= r) return;
	int index=0;
	int mid = l + r >> 1;
	int i = l;
	int j = mid + 1;
	merge_sort(b, l, mid);
	merge_sort(b, mid + 1, r);
	int* tmp = (int*)malloc(sizeof(int) * (12));
	if (tmp == NULL)exit(0);
	while (i <= mid && j <= r)
	{
		if (b[i] < b[j])
			tmp[index++] = b[i++];
		else
			tmp[index++] = b[j++];
	}
	while(i<=mid)
		tmp[index++] = b[i++];
	while(j<=r)
		tmp[index++] = b[j++];
	int m = 0;
	int p = l;
	for (; m < r-l+1; m++, p++)
		b[p] = tmp[m];
	free(tmp);
}
int main()
{
	int b[10] = { 6, 12, 458, 5, 4, 28, 19, 1230, 9, 47 };
	shell_sort(b, 10, 5);
	printArray(b,0, 10);
	
	quick_sort(b, 0, 9);
	printArray(b,0, 10);

	int c[11]={0, 6, 12, 458, 5, 4, 28, 19, 1230, 9, 47 };
	heap_sort(c, 1, 10);
	printArray(c, 1, 11);

	int d[11] = { 0, 6, 12, 458, 5, 4, 28, 19, 1230, 9, 47 };
	heap_sort_little(d, 1, 10);


	merge_sort(b, 0, 9);
	printArray(b, 0, 10);

	char e[10][DATA_CUT+1] = {"0006", "0012", "0458", "0005", "0004", "0028", "0019", "1230", "0009", "0047" };
	node* base = (node*)malloc(sizeof(node));
	if (base == NULL)return 0;
	write(base, 10, e);
	sort(base, DATA_CUT, 10);
	printLink(base);
	freeLink(base);
	return 0;
}