#include <iostream>
#include <cmath>
using namespace std;

double A[4][4]={{2,-1,0,0},{-1,3,-2,0},{0,-1,2,-1},{0,0,-3,5}};
double B[4]={6,1,0,1};
double L[4][4]={0};			//A分解得到的上三角矩阵
double U[4][4]={0};			//A分解得到的下三角矩阵
double a[4];		//来自系数矩阵A
double b[4];	//来自系数矩阵A
double c[3];		//来自系数矩阵A
double d[4];
double u[3];

/**
 *@name Resolve_matrix：分解矩阵得到A=LU 
**/
void Resolve_matrix()
{
	//填充各个系数序列
	for (int i=0;i<4;i++)
	{
		b[i]=A[i][i];
		if (i<3)
		{
			a[i+1]=A[i+1][i];
			c[i]=A[i][i+1];
		}
	}

	//根据公式计算L和U中的各个系数
	d[0]=b[0];
	for (int i=0;i<3;i++)
	{
		u[i]=c[i]/d[i];
		d[i+1]=b[i+1]-u[i]*a[i+1];
	}
	

	//得到U
	for (int i=0;i<4;i++)
	{
		U[i][i]=1;		//对角线元素全为1

		if(i<3)			//对角线上一层为u
		{
			U[i][i+1]=u[i];
		}
	}

	//得到L
	for (int i=0;i<4;i++)
	{
		L[i][i]=d[i];		//对角线元素的值

		if (i<3)				//对角线下一层为a
		{
			L[i+1][i]=a[i+1];
		}
	}

	//打印U
	cout<<"it's U matrix "<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//打印L
	cout<<"it's L matrix "<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
}

/**
 *@name Solve_matrix：求解矩阵 Ly=b Ux=y
**/
void Solve_matrix()
{
	double y[4];
	//得到y向量的解
	y[0]=B[0]/d[0];
	for (int i=1;i<4;i++)
	{
		y[i]=(B[i]-a[i]*y[i-1])/d[i];
	}
	/*
	for (int i=0;i<4;i++)
	{
		cout<<y[i]<<" ";
	}
	cout<<endl;*/

	double x[4];
	//得到x向量的值
	x[3]=y[3];
	for (int i=2;i>=0;i--)
	{
		x[i]=y[i]-u[i]*x[i+1];
	}
	
	//输出解向量x
	cout<<"其解向量为"<<endl;
	for (int i=0;i<4;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	Resolve_matrix();
	cout<<endl;
	Solve_matrix();
	system("pause");
}