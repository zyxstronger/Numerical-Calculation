#include <iostream>
#include <cmath>
using namespace std;

const int row_len=3;
const int col_len=3;
double A[row_len][col_len]={{3,-1,2},{1,1,1},{2,1,-1}};
double b[row_len]={-3,-4,-3};

/**
 *@name Jordan_elimination：约当消元
 *@param1 A：系数矩阵
 *@param2 b：右端向量
**/
void Jordan_elimination(double A[row_len][col_len],double b[row_len])
{
	for (int i=0;i<row_len;i++)
	{
		//对一行元素
		//首先进行归一化 A中元素
		double A_temp=A[i][i];
		for (int j=0;j<col_len;j++)
		{
			A[i][j]=A[i][j]/A_temp;
		}
		//归一化b中元素
		b[i]=b[i]/A_temp;

		//对其他行减去该行的归一化元
		for (int k=0;k<row_len;k++)
		{
			if(k==i)
				continue;
			else
			{
				//消去该行的第i列的元素
				double A_temp2=A[k][i];
				for (int p=0;p<row_len;p++)
				{
					A[k][p]=A[k][p]-A_temp2*A[i][p];
				}
				//对b向量在该行的值作处理
				b[k]=b[k]-A_temp2*b[i];
			}
		}
	}

	//显示矩阵经过约当消元后的结果 对角
	for (int i=0;i<row_len;i++)
	{
		for (int j=0;j<col_len;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<b[i]<<endl;
	}
}


/**
 *@name Jordan_elimination：高斯消去法
 *@param1 A：系数矩阵
 *@param2 b：右端向量
**/
void Gaussian_elimination(double A[row_len][col_len],double b[row_len])
{
	for (int i=0;i<row_len;i++)
	{
		//将主对角归一化
		double A_temp=A[i][i];
		for (int j=0;j<col_len;j++)
		{
			A[i][j]=A[i][j]/A_temp;
		}
		b[i]=b[i]/A_temp;

		//对该行后面的行进行消元
		for (int k=i+1;k<row_len;k++)
		{
			double A_temp2=A[k][i];
			for (int p=0;p<col_len;p++)
			{
				A[k][p]=A[k][p]-A_temp2*A[i][p];
			}
			b[k]=b[k]-A_temp2*b[i];
		}
	}

	//显示矩阵结果 上三角
	for (int i=0;i<row_len;i++)
	{
		for (int j=0;j<col_len;j++)
		{
			cout<<A[i][j]<<" "; 
		}
		cout<<b[i]<<endl;
	}

	//回代
	cout<<"\nthe result is"<<endl;
	
	//x定义为解向量 从后向前回代
	double x[row_len];
	for (int i=row_len-1;i>=0;i--)
	{
		x[i]=b[i];
		for (int j=i+1;j<row_len;j++)
		{
			x[i]+=(-A[i][j]*x[j]);
		}
	}

	//显示解向量
	for (int i=0;i<row_len;i++)
	{
		cout<<x[i]<<endl;
	}
}


void main()
{
	//cout<<"约当消去法"<<endl;
	//Jordan_elimination(A,b);
	//cout<<endl;
	cout<<"高斯消去法"<<endl;
	Gaussian_elimination(A,b);
	system("pause");
}