#include<iostream>
#define MAX 100
typedef struct
{
	int row, col;//每个三元组项所处的行、列、非零元具体值
	int item;
}Triple;

class TripleMatrix
{
private:
	Triple data[MAX];
	int row_, col_, NonZeronum;//总行，总列，总非零元个数
public:
	TripleMatrix(int a, int b)
	{
		row_ = a;
		col_ = b;
		NonZeronum = 0;
		for (int i = 0; i < MAX; i++)
		{
			data[i].col = 2147483647;
			data[i].row = 2147483647;
			data[i].item = 0;
		}
	}
	TripleMatrix()
	{
		row_ = MAX;
		col_ = MAX;
		NonZeronum = 0;
		for (int i = 0; i < MAX; i++)
		{
			data[i].col = 2147483647;
			data[i].row = 2147483647;
			data[i].item = 0;
		}
	}
	~TripleMatrix()
	{
		//std::cout << "已析构\n";
	}
	void setItem(int row, int col, int item)//根据行号列号非零元，添加一个三元组项
	{
		if (row > row_ || col > col_)
		{
			printf("行或者列超出上限\n");
		}
		if (NonZeronum == 0)
		{
			data[0] = { row,col,item };
			NonZeronum++;
		}
		else
		{
			int i = 0;
			while (row>data[i].row && row <= row_)
				i++;
			while (col>data[i].col && col <= col_&& data[i].row <= row && row <= row_)
				i++;
			if (data[i].row == row && data[i].col == col)//如果匹配到了
			{
				data[i].item = item;//修改现有的值
			}
			else if (data[i].item == 0)
			{
				NonZeronum++;
				data[i] = { row,col,item };
			}
			else//如果没有匹配，那就插入一个新的，把它后面的都向后移动一次
			{
				
				for (int j = NonZeronum; j >= i + 1; j--)
				{
					data[j] = data[j - 1];
				}
				NonZeronum++;
				data[i] = { row,col,item };
			}
		}
	}
	int getItem(int row, int col)
	{
		if (row > row_ || row<0 || col>col_ || col < 0)
			return -1;
		//这里没有对数据判断是否符合范围，懒得弄了
		for (int i = 0; i < NonZeronum; i++)
		{
				if (data[i].row==row&&data[i].col==col)
				{
					return data[i].item;
				}
		}
		return 0;
	}
	void printMatrix()
	{
		int k = 0;
		for (int i = 0; i < row_; i++)
		{
			for (int j = 0; j < col_; j++)
			{
				//三元组项中的行和列都是从下标1开始的，所以要-1
				if (data[k].row-1 == i && data[k].col-1 == j)
					printf("%d ", data[k++].item);
				else
					printf("0 ");
			}
			puts("");
		}
	}
	void printTriple()
	{
		for (int i = 0; i < NonZeronum; i++)
			printf("row:%d col:%d item:%d\n", data[i].row, data[i].col, data[i].item);
	}
	bool MatrixAdd(TripleMatrix A, TripleMatrix B, TripleMatrix& C)
	{
		if (A.col_ != B.col_ || A.row_ != B.row_ || C.row_ != B.row_ || C.col_ != B.col_)
		{
			return false;
			//行列不匹配
		}
		int k = 0;//记录非零元个数
		for (int i = 0; i < A.row_; i++)
		{
			for (int j = 0; j < A.col_; j++)
			{
				if (A.getItem(i + 1, j + 1) || B.getItem(i + 1, j + 1))
					C.data[k++] = { i + 1,j + 1,A.getItem(i + 1,j + 1) + B.getItem(i + 1,j + 1) };
			}
		}
		return true;
	}
	bool MatrixMulty(TripleMatrix A, TripleMatrix B, TripleMatrix& C)
	{
		if (A.col_ != B.row_)
		{
			return false;
			//行列不匹配
		}
		int sum = 0;
		for (int i = 1; i <= A.row_; i++)
		{
			for (int j = 1; j <= B.col_; j++)
			{
				sum = 0;
				for (int k = 1; k <= A.col_; k++)
				{
					sum += A.getItem(i, k) * B.getItem(k, j);
				}
				if (sum)
				{
					C.setItem(i, j, sum);
				}
			}
		}
		return true;
	}
};