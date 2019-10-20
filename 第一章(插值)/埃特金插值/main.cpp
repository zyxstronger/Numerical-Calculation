#include <iostream>
#include <stdlib.h>
using namespace std;

int count;
float result[10][10];
float node[10];

void Load_data()
{
	cout<<"please input the count ";
	cin>>count;

	cout<<"input the node and result"<<endl;
	for(int i=0;i<count;i++)
	{
		cin>>node[i]>>result[0][i];
		cout<<endl;
	}
}

void Print_result()
{
	for (int i=0;i<count;i++)
	{
		for (int j=0;j<count;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Aitken_interpolation(float x)
{
	for (int i=1;i<count;i++)
	{
		for (int j=i;j<count;j++)
		{
			result[i][j]=result[i-1][j]*(x-node[i-1])/(node[j]-node[i-1])+result[i-1][i-1]*(x-node[j])/(node[i-1]-node[j]);
		}
	}
}

void main()
{
	float x;
	Load_data();
	cout<<"please input the value_x ";
	cin>>x;
	Aitken_interpolation(x);
	Print_result();
	system("pause");
}