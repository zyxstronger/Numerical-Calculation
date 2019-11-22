#include <iostream>
#include <cmath>
using namespace std;

/**
 *@name function：迭代用的函数
 *@param1 xk：输入的xk值
**/
double function(double xk)
{
	return log(xk)+2;
}

/**
 *@name function：迭代用的函数的导数
 *@param1 xk：输入的xk值
**/
double function_diff(double xk)
{
	return 1/xk;
}

/**
 *@name Equation_iteration：方程求根的迭代法
 *@param1 x0：初始值
**/
double Equation_iteration(double x0)
{
	double xk=x0;
	double xk1;
	double error=100;
	while(fabs(error)>1e-4)
	{
		xk1=function(xk);
		error=xk1-xk;
		xk=xk1;
		cout<<"the iteration result is "<<xk1<<endl;
	}
	return xk1;
}

/**
  *@name Equation_iteration_weighting：带加权加速的迭代法
  *@param1 x0：
**/
double Equation_iteration_weighting(double x0)
{
	double xk=x0;
	double xk1;
	double error=100;
	double L=function_diff(x0);
	while(fabs(error)>1e-4)
	{
		xk1=1/(1-L)*(function(xk)-L*xk);
		error=xk1-xk;
		xk=xk1;
		cout<<"the iteration result is "<<xk1<<endl;
	}
	return xk1;
}

/**
  *@name Equation_iteration_weighting：松弛加速的迭代法
  *@param1 x0：
**/
double Equation_iteration_loose(double x0)
{
	double xk=x0;
	double xk1;
	double error=100;
	double wk;
	while(fabs(error)>1e-4)
	{
		//先求出wk，防止出现除0
		if(function_diff(xk)!=1)
			wk=1/(1-function_diff(xk));
		else
			wk=1;

		//松弛迭代
		xk1=wk*function(xk)+(1-wk)*xk;
		error=xk1-xk;
		xk=xk1;
		cout<<"the iteration result is "<<xk1<<endl;
	}
	return xk1;
}

/**
 *@name Equation_iteration_Aitken：埃特金加速的迭代法
 *@param1 x0：
**/
double Equation_iteration_Aitken(double x0)
{
	double xk=x0;
	double xk1;
	double xk2;
	double compensate;
	double error=100;
	while(fabs(error)>1e-4)
	{
		xk1=function(xk);
		xk2=function(xk1);
		//计算补偿
		if(fabs(xk2-2*xk1+xk)>1e-4)
			compensate=pow(xk2-xk1,2)/(xk2-2*xk1+xk);
		else
			compensate=0;
		//这里用的是xk2，再对其进行补偿
		xk1=xk2-compensate;
		error=xk1-xk;
		xk=xk1;
		cout<<"the iteration result is "<<xk1<<endl;
	}
	return xk1;
}

void main()
{
	cout<<"Equation_iteration"<<endl;
	Equation_iteration(3);
	cout<<"Equation_iteration_weighting"<<endl;
	Equation_iteration_weighting(3);
	cout<<"Equation_iteration_loose"<<endl;
	Equation_iteration_loose(3);
	cout<<"Equation_iteration_Aitken"<<endl;
	Equation_iteration_Aitken(3);
	system("pause");
}