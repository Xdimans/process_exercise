#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<TripleMatrix.h>
using namespace std;
int main()
{
	int row, col;//������������
	scanf("%d %d", &row, &col);
	TripleMatrix A(row, col);
	TripleMatrix B(row, col);
	TripleMatrix RES(row, col);
	TripleMatrix RES2(row, col);
	int a, b, c;//��ʱ����
	int nA;//A�ķ���Ԫ����
	int nB;//B�ķ���Ԫ����
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
	printf("����A:\n");
	A.printMatrix();
	printf("����B:\n");
	B.printMatrix();
	puts("");
	RES.MatrixAdd(A, B, RES);
	printf("A��B���:\n");
	RES.printMatrix();
	puts("");
	RES2.MatrixMulty(A, B, RES2);
	printf("A��B���:\n");
	RES2.printMatrix();
	puts("");
	return 0;
}