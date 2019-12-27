#include<iostream>
using namespace std;
const int len =5;													//数据向量的长度

double res[2]={0};											//最小二乘法求得的回归系数
double A[2][2]={0};											//最小二乘法对应的系数矩阵
double b[2]={0};												//最小二乘法对应的右端向量
double x[5]={165,123,150,123,141};				//数据点x向量
double y[5]={187,126,172,125,148};				//数据点y向量


/**
 *@name Build_matrix：构建最小二乘法需要的矩阵
**/
void Build_matrix()
{
	//构建最小二乘法对应的系数矩阵
	A[0][0]=len;

	for (int i=0;i<len;i++)
	{
		A[0][1]+=x[i];
		A[1][1]+=x[i]*x[i];
	}
	A[1][0]=A[0][1];

	//构建最小二乘法对应的右端向量
	for (int i=0;i<len;i++)
	{
		b[0]+=y[i];
		b[1]+=x[i]*y[i];
	}

	/*
	//打印系数矩阵A
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;

	//打印右端向量b
	for (int i=0;i<2;i++)
	{
		cout<<b[i]<<" ";
	}*/
}

/**
 *@name Least_square_method：利用最小二乘法求解回归系数
 *@param1 A：最小二乘法对应的系数矩阵
**/
void  Least_square_method(double A[2][2],double b[2])
{
	res[0]=(A[0][1]*b[1]-b[0]*A[1][1])/(A[0][1]*A[1][0]-A[0][0]*A[1][1]);
	res[1]=(A[1][0]*b[0]-A[0][0]*b[1])/(A[0][1]*A[1][0]-A[0][0]*A[1][1]);
}

void main()
{
	Build_matrix();
	Least_square_method(A,b);
	cout<<"the line is y="<<res[0]<<"+"<<res[1]<<"x"<<endl;
	system("pause");
}