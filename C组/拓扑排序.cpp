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
	int No; //�ٽӵ���
	int weight; //Ȩֵ
	struct enode* nextEdge;//ָ����һ����

}Enode;//�߽��
typedef struct vnode
{
	int data;
	Enode* firstE;
}Vnode;//�ڽӱ��ͷ���
typedef struct graph
{
	Vnode edge[MAX_SIZE];
	int v, e;//��Ŷ��㡢����Ŀ

}Graph;//�ڽӱ�

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
	for (int i = 0; i < v; i++)//��������
	{
		for (int j = v - 1; j >= 0; j--)
		{
			if (A[i][j] >= 1 && A[i][j] < INF) //���˵�бߣ���Ȩ��С�����ֵ
			{

				Enode* p = (Enode*)malloc(sizeof(Enode));//Ūһ���µı߽����������A[i][j]������
				if (p == NULL) exit(0);
				p->No = j;//�������Ǵ�i��j�ģ��������еݹ��ʱ����Ҫ�������ת�Ƶ���һ�����
				p->weight = A[i][j];
				head->edge[i].data = j;
				p->nextEdge = head->edge[i].firstE;//��Ϊһ���ǴӺ���ǰ�����ģ�����Խ�ٱ������ı�Ӧ�ñ�����Խǰ�棬����ͷ�巨
				head->edge[i].firstE = p;

			}
		}
	}
}
bool visited[MAX_SIZE];
int in[MAX_SIZE];//���
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
	printf("��������:");
	top(head, path, 0);
	freeGraph(head);

	return 0;
}