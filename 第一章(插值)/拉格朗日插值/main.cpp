#include<iostream>
#include<stdlib.h>
using namespace std;

float x[10];
float y[10];
int count;

void load_data()
{
	cout<<"the count is";
	cin>>count;
	for(int i=0;i<count;i++)
	{
		cin>>x[i]>>y[i];
		cout<<"\n";
	}
}

void print_data()
{
	for(int i=0;i<count;i++)
	{
		cout<<"x is "<<x[i]<<" y is "<<y[i]<<'\n';
	}
}


float Lagrange_interpolation(float value_x)
{
	float sum_all=0;
	float sum_single;
	for (int i=0;i<count;i++)
	{
		sum_single=y[i];
		for(int j=0;j<count;j++)
		{
			if(i==j)
				continue;
			else
			{
				sum_single*=(value_x-x[j])/(x[i]-x[j]);
			}
		}
		//cout<<"the sum_single is "<<sum_single<<endl;
		sum_all+=sum_single;
	}
	return sum_all;
}

void main()
{
	float value_x;
	float result;
	load_data();
	print_data();
	cout<<"please input the value_x ";
	cin>>value_x;
	result=Lagrange_interpolation(value_x);
	cout<<"the output is "<<result;
	system("pause");
}