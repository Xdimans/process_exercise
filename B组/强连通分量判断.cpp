#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF 32767
#define MAX_SIZE 40
int A[MAX_SIZE][MAX_SIZE] = {
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF},
{INF,INF,INF,INF,INF,INF,INF} };
void Display(int Vnumber, int cube[MAX_SIZE][MAX_SIZE], int path[MAX_SIZE][MAX_SIZE])
{ 
    for (int i = 0; i < Vnumber; i++)
    {
        for (int j = 0; j < Vnumber; j++)
        {
            if (cube[i][j] == INF && i != j)
            {
                printf("No");
                return;
            }
        }
    }
    printf("Yes");
}
void floyd(int Vnumber)
{
    int cube[MAX_SIZE][MAX_SIZE];
    int path[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < Vnumber; i++)
    {
        for (int j = 0; j < Vnumber; j++)
        {
            cube[i][j] = A[i][j];
            if (i != j && cube[i][j] < INF)
            {
                path[i][j] = i;
            }
            else path[i][j] = -1;
        }
    }
    for (int k = 0; k < Vnumber; k++)
    {
        for (int i = 0; i < Vnumber; i++)
        {
            for (int j = 0; j < Vnumber; j++)
            {
                if (cube[i][j] > cube[i][k] + cube[k][j])
                {
                    cube[i][j] = cube[i][k] + cube[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    Display(Vnumber, cube, path);
}
/*
5 5
0 -> 1, 4
1 -> 3, 1
2 -> 1, 4
3 -> 0, 2
4 -> 2, 2
上面是非强连通图的数据

5 7
0 -> 1, 4
1 -> 3, 1
2 -> 1, 4
3 -> 0, 2
4 -> 2, 2
2 -> 4, 1
1 -> 2, 1
上面是强连通图的数据
*/
int main()
{

    int Vnumber, number;
    printf("请输入结点个数以及连线个数");
    scanf("%d %d", &Vnumber,&number);
    for (int i = 0; i < number; i++)
    {
        int k, m, n;
        scanf("%d -> %d, %d", &k, &m, &n);
        A[k][m] = n;
    }
        floyd(Vnumber);
    return 0;
}
