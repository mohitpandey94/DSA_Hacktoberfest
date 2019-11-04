//http://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/
/*
		5
		31 100 65 12 18
        10 13 47 157 6
        100 113 174 11 33
        88 124 41 20 140
        99 32 111 41 20
        */
#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int dist[50][50];
bool issafe(int n, int i, int j)
{
	if(((i >= 0) && (i < n)) && ( (j >= 0) && (j < n)) )
	{

		return true;
	}
	else
		return false;
}
int dijsktra(int n)
{
	priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
	pq.push(make_pair(a[0][0],make_pair(0,0)));
	dist[0][0] = a[0][0];
	int res = 0;
	while(!pq.empty())
	{
		pair<int,pair<int,int> >temp;
		temp = pq.top();
		pq.pop();
		int dis = temp.first;
		int x = temp.second.first;
		int y = temp.second.second;
		//cout<<"x = "<<x<<", y = "<<y<<endl;

		if(issafe(n,x,y-1))
		{
			cout<<"x = "<<x<<", y = "<<y-1<<endl;
			if(dist[x][y-1] > (dis+ a[x][y-1]))
			{
				dist[x][y-1] = dis+ a[x][y-1];
				pq.push(make_pair(dist[x][y-1],make_pair(x,y-1)));
			}

		}
		if(issafe(n,x,y+1)&&(dist[x][y+1] > (dis+ a[x][y+1])))
			{
				cout<<"x = "<<x<<", y = "<<y+1<<endl;
				dist[x][y+1] = dis+ a[x][y+1];
				pq.push(make_pair(dist[x][y-1],make_pair(x,y-1)));
			}
			if(issafe(n,x+1,y)&&(dist[x+1][y] > (dis+ a[x+1][y])) )
			{
				cout<<"x = "<<x+1<<", y = "<<y<<endl;
				dist[x+1][y] = dis+ a[x+1][y];
				pq.push(make_pair(dist[x+1][y],make_pair(x+1,y)));
			}
			if(issafe(n,x-1,y)&&(dist[x-1][y] > (dis+ a[x-1][y])))
			{
				cout<<"x = "<<x-1<<", y = "<<y<<endl;
				dist[x-1][y] = dis+ a[x-1][y];
				pq.push(make_pair(dist[x-1][y],make_pair(x-1,y)));
			}
	}
	return dist[n-1][n-1];
}
int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
			dist[i][j] = INT_MAX;
		}
	}

	int res;
	res = dijsktra(n);
	cout<<res<<endl;
}
