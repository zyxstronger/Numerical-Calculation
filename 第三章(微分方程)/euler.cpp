#include <iostream>
#include <cmath>
using namespace std;

#define error 1e-4

//右端函数
double function(double x,double y)
{
	return 1/(1+x*x)-2*y*y;
}

//解析解
double solution(double x)
{
	return x/(1+x*x);
}

//隐式欧拉格式的初始化
void Euler_method1(float x0,float y0)
{
	float h=0.1;
	float x=x0;
	float y=y0;
	float yn;
	while(fabs(x-4)>=error)
	{
		//显式欧拉格式初始化
		yn=y+h*function(x,y);
		//隐式欧拉格式迭代
		y=y+h*function(x+h,yn);

		cout<<"the x is "<<x<<" the y is "<<y<<" the right y is "<<solution(x+h)<<endl;
		x=x+h;
	}
}

//利用欧拉格式求解 梯形格式(隐式)
void Euler_method2(float x0,float y0)
{
	//设置步长
	float h=0.10;
	float x=x0;
	float y=y0;
	float yn;
	while (fabs(x-4.0)>=error)
	{
		//显式欧拉格式
		yn=y+h*function(x,y);				
		//隐式欧拉格式
		y=y+h/2*(function(x,y)+function(x+h,yn));	

		cout<<"the x is "<<x<<" the y is "<<y<<" the right y is "<<solution(x+h)<<endl;
		x=x+h;
	}
}

void main()
{
	Euler_method1(0.0,0.0);
	system("pause");
}