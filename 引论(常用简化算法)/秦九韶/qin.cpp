#include<iostream>
#include<stdio.h>
#include "math.h"

using namespace std;

int function_qin1(int x)
{
	int a[6]={1,-1,4,0,-3,1};
	int i;
	int temp,sum;
	sum=a[0];
	temp=1;
	for(i=1;i<6;i++)
	{
		temp*=x;
		sum+=temp*a[i];
	}
	return sum;
}

int function_qin2(int x)
{
	int i;
	int n=6;
	int a[6]={1,-1,4,0,-3,1};
	int sum;
	sum=a[5];
	for(i=4;i>=0;i--)
	{
		sum=sum*x+a[i];
	}
	return sum;
}

void main()
{
	cout<<"the result is"<<function_qin1(3)<<endl;
	cout<<"the result is"<<function_qin2(3)<<endl;
	system("pause");
}