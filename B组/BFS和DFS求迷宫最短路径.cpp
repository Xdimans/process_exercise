#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 50
/*
数据
5 5
0 1 0 0 0
0 1 0 0 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
0 0 2 2
*/
typedef struct box {
	int x;
	int y;
	int step;
}Box;
typedef struct node {
	Box data[MAX_SIZE];
	int rear;
	int tail;
}Queue;
Queue* initQueue()
{
	Queue* base;
	base = (Queue*)malloc(sizeof(Queue));
	if (base == NULL)exit(0);
	base->rear = 0;
	base->tail = 0;
	return base;
}
bool isFull(Queue* base)
{
	return (base->tail + 1 % MAX_SIZE) == base->rear;
}
bool isEmpty(Queue* base)
{
	return base->rear == base->tail;
}
bool push(Queue*& base,Box a)
{
	if (isFull(base))
		return false;
	base->data[base->tail] = a;
	base->tail = (base->tail + 1) % MAX_SIZE;
	return true;
}
bool pop(Queue*& base,Box& a)
{
	if (isEmpty(base))
		return false;
	a = base->data[base->rear];
	base->rear = (base->rear + 1) % MAX_SIZE;
	return true;
}
bool judge(int x, int y, int n, int m)
{
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}
static int dx[4] = { 0,1,0,-1 };
static int dy[4] = { 1,0,-1,0 };
int bfs(int a[MAX_SIZE][MAX_SIZE],int startx,int starty,int endx,int endy,int n,int m,int visited[MAX_SIZE][MAX_SIZE])//迷宫数组，起点xy，终点xy，迷宫行列数
{
	Queue* base = initQueue();
	Box tmp;
	tmp.x = startx;
	tmp.y = starty;
	tmp.step = 0;
	push(base, tmp);
	while (!isEmpty(base))
	{
		pop(base, tmp);
		if (tmp.x == endx && tmp.y == endy)
		{
			return tmp.step;
		}
		for (int i = 0; i < 4; i++)
		{
			int x = tmp.x + dx[i];
			int y = tmp.y + dy[i];
			if (visited[x][y] == 0 && judge(x, y, n, m))
			{
				visited[x][y] = 1;
				Box next;
				next.x = x;
				next.y = y;
				next.step = tmp.step + 1;
				push(base, next);
			}
		}
	}
	return -1;
}
static int minStep = 10000000;
void dfs(int a[MAX_SIZE][MAX_SIZE],int n,int m,int nowx,int nowy,int endx,int endy,int step,int visited[MAX_SIZE][MAX_SIZE])
{
	if (nowx == endx && nowy == endy)
	{
		if (step < minStep)
		{
			minStep = step;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = nowx + dx[i];
		int y = nowy + dy[i];
		if (visited[x][y] == 0 && judge(x, y, n, m))
		{
			visited[x][y] = 1;
			dfs(a, n, m, x, y, endx, endy,step+1,visited);

			visited[x][y] = 0;
		}
	}
}
int main()
{
	int n;
	int m;
	int startx;
	int starty;
	int endy;
	int endx;
	int a[MAX_SIZE][MAX_SIZE];
	scanf("%d %d", &n, &m);
	int visited[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
				visited[i][j] = -1;
			else visited[i][j] = 0;
		}
	}
	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
	printf("BFS算出来的最小路径:%d\n",bfs(a, startx, starty, endx, endy, n, m,visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
	dfs(a, n, m, startx, starty, endx, endy,0,visited);
	printf("DFS算出来的最小步数:%d", minStep);
	return 0;
}