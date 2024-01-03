#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<TripleMatrix.h>
using namespace std;
int main()
{
	int row, col;//矩阵行数列数
	scanf("%d %d", &row, &col);
	TripleMatrix A(row, col);
	TripleMatrix B(row, col);
	TripleMatrix RES(row, col);
	TripleMatrix RES2(row, col);
	int a, b, c;//临时变量
	int nA;//A的非零元个数
	int nB;//B的非零元个数
	scanf("%d %d", &nA, &nB);
	for (int i = 0; i < nA; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		A.setItem(a, b, c);
	}
	for (int i = 0; i < nB; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		B.setItem(a, b, c);
	}
	printf("矩阵A:\n");
	A.printMatrix();
	printf("矩阵B:\n");
	B.printMatrix();
	puts("");
	RES.MatrixAdd(A, B, RES);
	printf("A和B相加:\n");
	RES.printMatrix();
	puts("");
	RES2.MatrixMulty(A, B, RES2);
	printf("A和B相乘:\n");
	RES2.printMatrix();
	puts("");
	return 0;
}