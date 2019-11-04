#include<iostream>
#include<cstdlib>
using namespace std;
void display(int **a,int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{

	int n;
	cin>>n;
	int **ptr;
	ptr =(int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++)
	{
		ptr[i] = (int*)malloc(sizeof(int)*n);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>ptr[i][j];
		}
	}

	display(ptr,n);
	cout<<endl;
}
