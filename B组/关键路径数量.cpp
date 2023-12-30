#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define ElemType int
#define MAX_SIZE 500
#define INF 32767
int A[MAX_SIZE][MAX_SIZE] =
{
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF,INF,INF} };
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
typedef struct stack
{
	ElemType data[MAX_SIZE];
	int top;
}Stack;
Stack* initStack()
{
	Stack* a = (Stack*)malloc(sizeof(Stack));
	if (a == NULL) exit(0);
	a->top = -1;
	return a;

}
bool isFull(Stack* a)
{
	return a->top >= MAX_SIZE;

}
bool isEmpty(Stack* a)
{
	return a->top == -1;
}
bool push(Stack*& a, ElemType b)
{
	if (isFull(a))
		return false;
	a->data[++(a->top)] = b;
	return true;
}
bool pop(Stack* a, ElemType& b)
{
	if (isEmpty(a))
		return false;
	b = a->data[a->top];
	a->top--;
	return true;
}
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
			if (A[i][j] > 0 && A[i][j] < INF) //如果说有边，且权重小于最大值
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
int cut = 0;
int q = 0;
void CriticalPath(Graph* head, int path[],int n);
void top(Graph* head, int*& path, int n)
{
	if (n == head->v&&q<1)
	{
		q++;
		CriticalPath(head, path, n);
		return;
	}
	for (int i = head->v - 1; i >= 0; i--)
	{
		if (visited[i] == false && in[i] == 0&&q<1)
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
void CriticalPath(Graph* head, int path[],int n)
{
	int late[MAX_SIZE];
	int early[MAX_SIZE];
	//最早发生时间取最大值
	for (int i = 0; i < head->v; i++)
	{
		early[i] = 0;
	}
	for (int i = 0; i < head->v; i++)
	{
		int tmp = path[i];
		Enode* p = head->edge[tmp].firstE;
		while (p != NULL)
		{
			int temp = p->No;
			if (early[temp] < early[tmp] + p->weight)
				early[temp] = early[tmp] + p->weight;
			p = p->nextEdge;
		}
	}
	//最迟发生时间取最小值
	for (int i = 0; i < head->v; i++)
	{
		late[i] = early[path[head->v - 1]];
	}
	for (int i = head->v - 1; i >= 0; i--)
	{
		int tmp = path[i];
		Enode* p = head->edge[tmp].firstE;
		while (p != NULL)
		{
			int temp = p->No;
			if (late[tmp] > late[temp] - p->weight)
				late[tmp] = late[temp] - p->weight;
			p = p->nextEdge;
		}
	}
	for (int i = 0; i < head->v - 1; i++)
	{
		Enode* tmp = head->edge[i].firstE;
		while (tmp != NULL)
		{
			int temp = tmp->No;
			if (early[i] == late[temp] - tmp->weight)
			{
				printf("(%d,%d)  ", i  , temp);
				cut++;
			}
			tmp = tmp->nextEdge;
		}
	}
	printf("一共有%d条", cut);
}
/*
入:
0 -> 1, 1
0 -> 2, 5
1 -> 3, 3
2 -> 3, 7
3 -> 4, 2
*/
int main()
{
	int n = 5;
	int e = 0;
	for (int i = 0; i < 5; i++)
	{
		int j, k,m;
		scanf("%d -> %d, %d", &j, &k,&m);
		A[j][k] = m;
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
	int* path = (int*)malloc(sizeof(int) * MAX_SIZE);
	int* temp = path;
	top(head, path, 0);
	//CriticalPath(head, path);
	freeGraph(head);

	return 0;
}