#include<iostream>
#define MAX 100
typedef struct
{
	int row, col;//ÿ����Ԫ�����������С��С�����Ԫ����ֵ
	int item;
}Triple;

class TripleMatrix
{
private:
	Triple data[MAX];
	int row_, col_, NonZeronum;//���У����У��ܷ���Ԫ����
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
		//std::cout << "������\n";
	}
	void setItem(int row, int col, int item)//�����к��кŷ���Ԫ�����һ����Ԫ����
	{
		if (row > row_ || col > col_)
		{
			printf("�л����г�������\n");
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
			if (data[i].row == row && data[i].col == col)//���ƥ�䵽��
			{
				data[i].item = item;//�޸����е�ֵ
			}
			else if (data[i].item == 0)
			{
				NonZeronum++;
				data[i] = { row,col,item };
			}
			else//���û��ƥ�䣬�ǾͲ���һ���µģ���������Ķ�����ƶ�һ��
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
		//����û�ж������ж��Ƿ���Ϸ�Χ������Ū��
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
				//��Ԫ�����е��к��ж��Ǵ��±�1��ʼ�ģ�����Ҫ-1
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
			//���в�ƥ��
		}
		int k = 0;//��¼����Ԫ����
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
			//���в�ƥ��
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