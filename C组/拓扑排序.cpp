#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define ElemType int
#define MAX_SIZE 500
#define INF 32767
int A[MAX_SIZE][MAX_SIZE] =
{
{0,  1,  INF,INF,INF,INF},
{INF,0,  1,  INF,INF,INF},
{INF,INF,0,  1,  INF,INF},
{INF,INF,INF,0,  INF,INF},
{INF,1,  INF,INF,0,  1},
{INF,INF,INF,1,  INF,0}
};
typedef struct enode
{
	int No; //临接点编号
	int weight; //权值
	struct enode* nextEdge;//指向下一条边

}Enode;//边结点
typedef struct vnode
{
	int data;
	Enode* firstE;
}Vnode;//邻接表的头结点
typedef struct graph
{
	Vnode edge[MAX_SIZE];
	int v, e;//存放顶点、边数目

}Graph;//邻接表

Graph* initGraph(int v, int e)
{
	Graph* head = (Graph*)malloc(sizeof(Graph));
	if (head == NULL) exit(0);
	head->v = v;
	head->e = e;
	for (int i = 0; i < v; i++)
	{
		head->edge[i].firstE = NULL;
	}
	return head;
}
void cubeToGraph(Graph*& head, int v, int e)
{
	for (int i = 0; i < v; i++)//遍历矩阵
	{
		for (int j = v - 1; j >= 0; j--)
		{
			if (A[i][j] >= 1 && A[i][j] < INF) //如果说有边，且权重小于最大值
			{

				Enode* p = (Enode*)malloc(sizeof(Enode));//弄一个新的边结点用来储存A[i][j]这条边
				if (p == NULL) exit(0);
				p->No = j;//这条边是从i到j的，后续进行递归的时候需要用这个来转移到下一个结点
				p->weight = A[i][j];
				head->edge[i].data = j;
				p->nextEdge = head->edge[i].firstE;//因为一行是从后往前遍历的，所以越迟遍历到的边应该被放在越前面，所以头插法
				head->edge[i].firstE = p;

			}
		}
	}
}
bool visited[MAX_SIZE];
int in[MAX_SIZE];//入度
int num;
int cut = 0;
void top(Graph* head, int path[], int n)
{
	if (cut >= num)
		return;
	if (n == head->v)
	{
		for (int i = 0; i < head->v; i++)
		{
			printf("%d ", path[i]);
		}
		cut++;
		puts("");
	}
	for (int i = head->v - 1; i >= 0; i--)
	{
		if (visited[i] == false && in[i] == 0)
		{
			visited[i] = true;
			path[n++] = i;
			Enode* p = head->edge[i].firstE;
			while (p != NULL)
			{
				int tmp = p->No;
				in[tmp]--;
				p = p->nextEdge;
			}
			top(head, path, n);

			p = head->edge[i].firstE;
			while (p != NULL)
			{
				int tmp = p->No;
				in[tmp]++;
				p = p->nextEdge;
			}

			visited[i] = false;
			n--;

		}
	}

}
void freeGraph(Graph*& head)
{
	for (int i = 0; i < head->v; i++)
	{
		Enode* tmp = head->edge[i].firstE;
		while (tmp != NULL)
		{
			Enode* tmpNext = tmp->nextEdge;
			free(tmp);
			tmp = tmpNext;
		}


	}
}
int main()
{
	int n = 6;
	int e = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (A[i][j] > 0 && A[i][j] < INF)
				e++;
	}
	Graph* head = initGraph(n, e);
	cubeToGraph(head, n, e);
	Graph* tmp = head;
	head = tmp;
	for (int i = 0; i < head->v; i++)
	{
		in[i] = 0;
		visited[i] = false;
	}
	for (int i = 0; i < head->v; i++)
	{
		Enode* p = head->edge[i].firstE;
		while (p != NULL)
		{
			int tmp = p->No;
			in[tmp]++;
			p = p->nextEdge;
		}
	}
	int path[MAX_SIZE];
	scanf("%d", &num);
	printf("拓扑序列:");
	top(head, path, 0);
	freeGraph(head);

	return 0;
}