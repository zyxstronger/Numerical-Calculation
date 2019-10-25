#include <iostream>
#include <cmath>
using namespace std;

//定义积分结果表
double integral_table[10][4];

/**
 *@name function：被积函数
 *@param1 x：自变量
**/
double function(double x)
{
	return 4/(1+pow(x,2));
}

/**
 *@name Romberg_arithmetic：利用龙贝格算法建立积分结果表
 *@param1 down：积分下限
 *@param2 upper：积分上限
**/
void Romberg_arithmetic(double down,double upper)
{
	double S=0;
	double n=0.5;
	double h=(upper-down);
	integral_table[0][0]=(function(down)+function(upper))*(h/2);
	//计算顺序	外循环由列开始迭代：1列 2列 3列（其中第0列由变步长梯形法求得）
	//					内循环行迭代

	//变步长梯形法求第0列 Tn
	for (int i=0;i<10;i++)
	{
		n=n*2;
		h=(upper-down)/n;
		
		S=0;
		for (int j=0;j<n;j++)
		{
			S+=function(down+j*h+h/2);
		}

		integral_table[i+1][0]=integral_table[i][0]/2+S*(h/2);
	}

	//计算Sn Cn Rn
	for (int i=1;i<4;i++)
	{
		for(int j=i;j<10;j++)
		{
			//利用龙贝格求积公式
			integral_table[j][i]=(pow(4.0,i)*integral_table[j][i-1]-integral_table[j-1][i-1])/(pow(4.0,i)-1);
		}
	}
}

void main()
{
	Romberg_arithmetic(0,1);
	//打印求积结果表
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<4;j++)
		{
			if(integral_table[i][j]!=0)
			{
				cout<<integral_table[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	system("pause");
}