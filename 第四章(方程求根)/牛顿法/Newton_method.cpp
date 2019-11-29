#include <iostream>
#include <math.h>
using namespace std;

double function(double x)
{
	return pow(x,3)+2*pow(x,2)+10*x-20;
}

double function_d(double x)
{
	return 3*pow(x,2)+4*x+10;
}

/**
 *@name Newton_method：牛顿法
 *@param1 x0：迭代的初始值
 *@param2 e：给定的误差限
**/
double Newton_method(double x0,double e)
{
	double xk=x0;
	double xk1;
	double error=100;
	while(fabs(error)>e)
	{
		if(fabs(function_d(xk))>1e-3)
		{
			//牛顿法公式
			xk1=xk-function(xk)/function_d(xk);
			//计算误差
			error=xk1-xk;
			//进行新一轮的迭代
			xk=xk1;

			cout<<"the xk1 is "<<xk1<<endl;
		}
		else
		{
			cout<<"error div number is 0"<<endl;
			return 0;
		}
	}
	return xk1;
}

double Newton_down_method(double x0,double e,double lamda_limit)
{
	double lamda=1;
	double xk=x0;
	double xk1;
	double error=100;
	unsigned char down_flag=0;
	while(fabs(error)>e)
	{
		if(fabs(function_d(xk))>1e-3)
		{
			//牛顿法迭代
			xk1=xk-lamda*function(xk)/function_d(xk);

			//若还未成功下山 则作如下判断
			if(down_flag==0)
			{
				//判断是否成功下山
				if(fabs(function(xk1))<fabs(function(xk)))
				{
					down_flag=1;
					cout<<"go down successful!"<<endl;
				}
			}

			if(down_flag==0)
			{
				//判断lamda是否越界
				if(lamda<lamda_limit)
				{
					cout<<"please choose another x0 "<<endl;
					return 0;
				}
				else
					lamda=lamda/2;
			}

			//判断误差 并进入新一轮迭代
			error=xk1-xk;
			xk=xk1;
			cout<<"the xk1 is "<<xk1<<" the lamda is "<<lamda<<endl;
		}
		else
		{
			cout<<"error div number is 0"<<endl;
			return 0;
		}
	}
	return xk1;
}

void main()
{
	cout<<"牛顿法求根"<<endl;
	Newton_method(1,1e-6);
	cout<<"牛顿下山法求根"<<endl;
	Newton_down_method(1,1e-6,0.02);
	system("pause");
}