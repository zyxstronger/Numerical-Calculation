#include <iostream>
#include <cmath>
using namespace std;

double Tn[20];	//用来存放求积结果

/**
 *@name function：被积函数
 *@param1 x：输入的自变量
**/
double function(double x)
{
	if(x==0)
		return 1;
	else
		return sin(x)/x;
}

/**
 *@name Variable_step：利用变步长梯形公式求积
 *@param1 down：积分下限
 *@param2 upper：积分上限
 *@param3 limit_error：误差限
**/
void Variable_step(double down,double upper,double limit_error)
{
	Tn[0]=(function(down)+function(upper))/2;

	double h;		//定义小区间的长度
	double n=0.5;		//定义划分的区间数
	double S=0;		//新增和

	//注意每次区间二分，不是自加
	for (int i=0;i<19;i++)
	{
		//从前先后推 Tn[0]->Tn[1] 每次对区间进行二分
		n=n*2;		
		//计算小区间的长度
		h=(upper-down)/n;	

		S=0;
		//计算小区间内所有中点的函数和 
		for (int j=0;j<n;j++)
		{
			S+=function(down+j*h+h/2);
		}

		//迭代到下一项
		Tn[i+1]=Tn[i]/2+(h/2)*S;

		//如果检测到误差小于限制，则直接输出
		if(abs(Tn[i+1]-Tn[i])/3<limit_error)
			break;
	}
}

void main()
{
	//利用变步长梯形公式求积
	Variable_step(0,1,1e-10);

	//打印求积结果
	for (int i=0;i<20;i++)
	{
		cout<<"步长"<<i<<" "<<Tn[i]<<endl; 
	}
	system("pause");
}