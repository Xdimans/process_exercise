#define _CRT_SECURE_NO_WARNINGSs
#include<bits/stdc++.h>
#define MAX_SIZE 12
typedef struct box
{
	int x;
	int y;
	int nexti;
	int oldvisit[MAX_SIZE][MAX_SIZE];
}Queen;
typedef struct node
{
	Queen queen[MAX_SIZE];
	int length;
}Stack;
Stack* initStack()
{
	Stack* a = (Stack*)malloc(sizeof(Stack));
	if (a == NULL) exit(0);
	a->length = 0;
	return a;
}
bool isFull(Stack* a)
{
	return a->length == MAX_SIZE;
}
bool isEmpty(Stack* a)
{
	return a->length == 0;
}
bool push(Stack* a, Queen b)
{
	if (isFull(a))
		return false;
	a->queen[a->length++] = b;
	return true;
}
bool pop(Stack* a, Queen& b)
{
	if (isEmpty(a))
		return false;
	a->length--;
	b = a->queen[a->length];
	return true;
}
bool getTop(Stack* a, Queen& b)
{
	if (isEmpty(a))
		return false;
	b = a->queen[a->length - 1];
	return false;
}
void updateVisit(int x, int y, int visited[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++)
	{
		visited[x][i] = 1;
		visited[i][y] = 1;
		if (x + i < n && y + i < n)
			visited[x + i][y + i] = 1;
		if (x - i >= 0 && y - i >= 0)
			visited[x - i][y - i] = 1;
		if (x - i >= 0 && y + i < n)
			visited[x - i][y + i] = 1;
		if (x + i < n && y - i >= 0)
			visited[x + i][y - i] = 1;
	}
}
int cut = 0;
void dfs(int n, int visited[MAX_SIZE][MAX_SIZE]) //n表示总共有几个皇后，index表示正在放第几行,path表示皇后拜访信息，cut用来统计是第几个方案
{
	Stack* a = initStack();
	for (int e = 0; e< n; e++)
	{
		Queen tmp;
		tmp.x = 0;
		tmp.y = e;
		tmp.nexti = -1;

		int oldvisit[MAX_SIZE][MAX_SIZE];
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp.oldvisit[k][j] = visited[k][j];
			}
		}
		push(a, tmp);
		updateVisit(tmp.x, tmp.y, visited, n);
		while (!isEmpty(a))
		{
			a->queen[a->length - 1].nexti++;
			getTop(a, tmp);
			if (a->length == n)
			{
				for (int i = 0; i < n; i++)
				{

					printf("(%d,%d)  ", a->queen[i].x, a->queen[i].y);
				}
				cut++;
				puts("");
			}

			bool find = false;
			int i = tmp.nexti;


			for (; i < n; i++)
			{
				if (visited[tmp.x + 1][i] == false)
				{
					find = true;
					goto link;
				}
			}
			pop(a, tmp);
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < n; j++)
				{
					visited[k][j] = tmp.oldvisit[k][j];
				}
			}

		link:
			if (find == true)
			{
				Queen temp;
				temp.x = tmp.x + 1;
				temp.y = i;
				temp.nexti = -1;
				a->queen[a->length - 1].nexti = i;
				for (int k = 0; k < n; k++)
				{
					for (int j = 0; j < n; j++)
					{
						temp.oldvisit[k][j] = visited[k][j];
					}
				}
				push(a, temp);
				updateVisit(temp.x, temp.y, visited, n);
			}

		}
	}
	
}

int main()
{
	int n = 8;//棋盘宽度
	int visited[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
	dfs(n,visited);
	printf("\n%d", cut);
	return 0;
}