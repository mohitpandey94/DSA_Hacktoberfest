#include<bits/stdc++.h>
using namespace std;
int a[50][50];
void printoutput(int n)
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
bool safe(int x, int y, int N)
{
	int i,j;
	//cout<<"x = "<<x<<"y = "<<y<<endl;
	if((x >= 0) && (x < N) && (y >= 0) && (y < N))
	{
		for(i = 0; i < N; i++)
		{
			if(a[x][i] == 1)
			{
				return false;
			}
		}
		for(i = 0; i < N; i++)
		{
			if(a[i][y] == 1)
			{
				return false;
			}
		}
		for( i = x,  j = y; i >= 0 && j >= 0; i--,j--)
		{
			if(a[i][j])
			{
				return false;
			}
		}
		for(i = x, j = y; i < N && j < N; i++,j++)
		{
			if(a[i][j])
			{
				return false;
			}
		}
		for(i = x,j = y; i >=0 && j < N; i--,j++)
		{
			if(a[i][j])
			{
				return false;
			}
		}
		for( i = x,j = y; i < N && j >= 0; i++,j--)
		{
			if(a[i][j])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool sol(int x, int y,int n, int q)
{
	if(q == 0)
	{
		return true;
	}
	if(safe(x,y,n))
	{
	//	cout<<"entered" <<endl;
		//cout<<"q = "<<q<<endl;
		a[x][y] = 1;
		q--;
		/*if(sol(++x,y,n,q) || sol(x,++y,n,q))
		{
			return true;
		}
		*/
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(sol(i,j,n,q) )
				{
					return true;
				}
			}
		}
		a[x][y] = 0;
		q++;
	}
	return false;

}
int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}

	int q;
	cin>>q;
	if(sol(0,0,n,q))
	{
		printoutput(n);
		//cout<<endl;
	}
	else
	{
		printf("Naa Ho paayi\n");
	}

	return 0;
}
