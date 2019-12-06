#include <iostream>
#include <cmath>
using namespace std;

//定义系数矩阵和结果向量
double A[2][2]={{3,1},{1,2}};
double b[2]={2,1};
double x[2]={10,10};
double x1[2];

//找到解向量中的最大值
double Max(double* x)
{
	double temp=x[0];
	for(int i=1;i<2;i++)
	{
		if(temp<x[i])
			temp=x[i];
	}
	return temp;
}

//打印x向量
void Print_vector(double* x)
{
	for(int i=0;i<2;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

//初始化x0
void Init_vector(double* x)
{
	for (int i=0;i<2;i++)
	{
		x[i]=10;
	}
}

/**
 *@name Jacobi_iteration：雅克比迭代方法求解向量
 *@param1 x：初始解向量x
 *@param2 x1：迭代结果解向量
 *@param3 error：迭代停止的精度限
**/
void Jacobi_iteration(double* x,double* x1,double error)
{
	double temp=0;
	double delta=100;
	while(fabs(delta)>error)
	{
		//根据迭代公式进行计算
		for (int i=0;i<2;i++)
		{
			//每一次利用中间变量temp存储迭代结果
			temp=0;
			for (int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=temp;
		}

		//打印这一轮的解向量，并求出误差
		Print_vector(x1);
		delta=Max(x1)-Max(x);

		//将x1赋给x，进入新一轮迭代
		for(int i=0;i<2;i++)
		{
			x[i]=x1[i];
		}
	}
}

/**
*@name Jacobi_iteration：高斯迭代方法求解向量
*@param1 x：初始解向量x
*@param2 x1：迭代结果解向量
*@param3 error：迭代停止的精度限
**/
void Gaussian_iteration(double* x,double* x1,double error)
{
	double temp=0;
	double delta=100;
	double max_x;
	while(fabs(delta)>error)
	{
		max_x=Max(x);
		//利用高斯迭代法进行迭代
		for(int i=0;i<2;i++)
		{
			temp=0;
			for(int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=x[i]=temp;
		}

		//打印这一轮迭代的解向量
		Print_vector(x1);
		delta=Max(x1)-max_x;

	}
}

void Super_loose(double* x,double* x1,double error,double w)
{
	double temp=0;
	double delta=100;
	double max_x;
	double temp_x[2];
	while(fabs(delta)>error)
	{
		//将变化前的x存起来
		max_x=Max(x);
		for(int i=0;i<2;i++)
		{
			temp_x[i]=x[i];
		}

		//利用高斯迭代法进行迭代
		for(int i=0;i<2;i++)
		{
			temp=0;
			for(int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=x[i]=temp;
		}

		//超松弛加权
		for(int i=0;i<2;i++)
		{
			x1[i]=w*x1[i]+(1-w)*temp_x[i];
		}

		//打印这一轮迭代的解向量
		Print_vector(x1);
		delta=Max(x1)-max_x;
	}
}

void main()
{
	cout<<"the Jacobi_iteration is "<<endl;
	Jacobi_iteration(x,x1,1e-4);
	Init_vector(x);
	cout<<"\nthe Gaussian_iteration is "<<endl;
	Gaussian_iteration(x,x1,1e-4);
	Init_vector(x);
	cout<<"\nthe Super_loose(w=1.5) is "<<endl;
	Super_loose(x,x1,1e-4,1.5);
	system("pause");
}