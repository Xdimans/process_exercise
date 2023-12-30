#define _CRT_SECURE_NO_WARNINGSs
#include<bits/stdc++.h>
#define MAX_SIZE 12
typedef struct box
{
	int x;
	int y;
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
void dfs(int n, int index, Queen path[MAX_SIZE],int visited[MAX_SIZE][MAX_SIZE]) //n表示总共有几个皇后，index表示正在放第几行,path表示皇后拜访信息，cut用来统计是第几个方案
{
	if (index == n) //index==8，说明已经摆放完毕
	{
		for (int i = 0; i < n; i++)
		{
			
			printf("(%d,%d)  ", path[i].x, path[i].y);
		}
		cut++;
		puts("");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[index][i] == 0)
		{
			int oldvisited[MAX_SIZE][MAX_SIZE];
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < n; j++)
				{
					oldvisited[k][j] = visited[k][j];
				}
			}
			updateVisit(index, i, visited, n);
			Queen tmp;
			tmp.x = index;
			tmp.y = i;
			path[index++] = tmp;
			dfs(n, index, path, visited);

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					visited[i][j] = oldvisited[i][j];
				}
			}
			index--;
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
	Queen path[MAX_SIZE];
	dfs(n, 0, path,visited);
	printf("\n%d", cut);
	return 0;
}