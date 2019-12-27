#include <iostream>
using namespace std;

double A[3][3]={{4,-2,4},{-2,17,10},{4,10,9}};
double b[3]={10,3,-7};
double L[3][3]={0};
double D[3][3]={0};
double y[3]={0};
double x[3]={0};

/**
 *@name Resolve_Matrix：分解矩阵
 *@param1 A：需要分解的矩阵 A=LDLT
**/
void Resolve_Matrix(double A[3][3])
{
	//L的对角线全赋值为1
	for (int i=0;i<3;i++)
	{
		L[i][i]=1;
	}

	//L和D需要同时进行分解
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (i==j)
			{
				D[i][j]=A[i][j];
				for (int k=0;k<i;k++)
				{
					D[i][j]-=D[k][k]*L[i][k]*L[i][k];
				}
			}
			else if(i>j)
			{
				L[i][j]=A[i][j];
				for (int k=0;k<j;k++)
				{
					L[i][j]-=D[k][k]*L[i][k]*L[j][k];
				}
				L[i][j]/=D[j][j];
			}
		}
	}

	//打印分解结果
	cout<<"the L is"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"the D is"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
}

/**
 *@name Back_solve：回代求解
 *@param1 L：分解得到的下三角阵L
 *@param2 D：分解得到的对角阵D
 *@param3 b：右端向量b
**/
void Back_solve(double L[3][3],double D[3][3],double b[3])
{
	//回代求y向量
	for (int i=0;i<3;i++)
	{
		y[i]=b[i];
		for (int k=0;k<i;k++)
		{
			y[i]-=L[i][k]*y[k];
		}
	}
	//打印结果
	cout<<"\nthe y is "<<" ";
	for (int i=0;i<3;i++)
	{
		cout<<y[i]<<" ";
	}

	//回代求x向量
	for (int i=2;i>=0;i--)
	{
		x[i]=y[i]/D[i][i];
		for (int k=i+1;k<3;k++)
		{
			x[i]-=L[k][i]*x[k];
		}
	}


	cout<<"\nthe x is"<<" ";
	for (int i=0;i<3;i++)
	{
		cout<<x[i]<<" ";
	}

}

void main()
{
	Resolve_Matrix(A);
	Back_solve(L,D,b);
	system("pause");
}