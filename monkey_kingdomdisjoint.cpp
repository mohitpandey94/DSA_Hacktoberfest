#include<bits/stdc++.h>
using namespace std;
int parent[100005];
long long length[100005];
long long a[100005];
int find_par(int x)
{

if(parent[x] != x)
{

return find_par(parent[x]);

}

return parent[x];

}


void makeunion(int x, int y)
{
int x_par = find_par(x);

int y_par = find_par(y);

if(length[x_par] >= length[y_par])

{

parent[y_par] = x_par;

length[x_par] += length[y_par];
//a[x_par] += a[y_par];
//a[y_par] = 0;

length[y_par] = 0;

}

else

{

parent[x_par] = y_par;

length[y_par] += length[x_par];
//a[y_par] += a[x_par];
//a[x_par] = 0;
length[x_par] = 0;

}

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(parent,0,sizeof(parent));
		memset(length,0,sizeof(length));
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}
		
		for(int i = 1; i <= m; i++)
		{
			int src;
			int dest;
			cin>>src>>dest;
			if(find_par(dest) != find_par(src))
			{
				makeunion(src,dest);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
			cout<<"parent of i = "<<i<<" is "<<parent[i]<<endl;
			if(parent[i] != i)
			a[parent[i]] = a[parent[i]] + a[i];
			else
			a[parent[i]] = a[i];
		}
		sort(a,a+n+1);
		int val = a[n];
		cout<<val<<" ";
	}
	return 0;
}
