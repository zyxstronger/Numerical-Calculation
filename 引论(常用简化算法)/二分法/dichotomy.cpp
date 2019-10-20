#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

float Equation_function(float x)
{
	return pow(x,3)-x-1;
}

float Dichotomy_solution(float error_range,float down,float upper)
{
	float error=(upper-down)/2;
	float x;
	float y,y0,y1;										//用来记录x,upper,down的函数值
	int count=0;

	while(error>=error_range)
	{
		//找到当前上下限对应的解以及误差
		x=(upper+down)/2;
		error=(upper-down)/2;

		//计算此时的x,upper,down对应的函数值
		y=Equation_function(x);
		y0=Equation_function(down);
		y1=Equation_function(upper);

		if((y*y1)<0)
		{
			down=x;
		}
		else if((y*y1)==0)
		{
			return x;
		}
		else
		{
			upper=x;
		}
	}
	return x;
}

void main()
{
	float x;
	x=Dichotomy_solution(1e-3,1,2);
	cout<<"x is "<<x<<endl;
	system("pause");
}