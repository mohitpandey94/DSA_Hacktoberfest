#include<bits/stdc++.h>
using namespace std;

void insert_edge(list<int>adj[],int src,int dest)
{
    adj[src].push_back(dest);
}
void delete_edge(list<int>adj[],int src,int dest)
{
    adj[src].remove(dest);
}
void list_display(list<int>l)
{
	if(l.empty())
		return;
    list<int>::iterator it;
    for(it = l.begin(); it!= l.end(); it++)
    {
        cout<<(*it)<<"-> ";
    }
    cout<<"NULL";
}

void display(list<int>adj[],int n)
{
    int i;
    for(i = 1; i<=n; i++)
    {
        cout<<"head = "<<i<<"-> ";
        list_display(adj[i]);
        //cout<<endl;cout<<"head = "<<i<<"-> ";
        cout<<endl;
    }
}

int visited[100005];
void dfs(list<int>adj[],int i, long long &ctr)
{
	visited[i] = 1;
	list<int>::iterator it;
	ctr = ctr + 1;
	for(it = adj[i].begin(); it != adj[i].end(); it++)
	{
		//cout<<"i = "<<i<<endl;
		//cout<<"*it = "<<*it<<endl;
		if(!visited[*it])
		{
			dfs(adj,*it,ctr);
		}
	}
	
}
bool findlist(list<int>l, int k)
{
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++)
	{
		if(*it == k)
		return true;
	}
	
	return false;
}
int main()
{
	
		int v;
		int e;
		cin>>v>>e;
		int src,dest;
		//list<int>adj[](v);
		list<int>adj[v+1];
	
		for(int i = 0; i < e; i++)
		{
				cin>>src;
                cin>>dest;
                //insert_edge(adj,src,dest);
                if(!findlist(adj[dest],src))
                	adj[dest].push_back(src);
		}
		//cout<<"Adjacency list\n";
		//display(adj,v);
		//cout<<endl;
	/*	long long a[v+1];
		for(int i= 1; i <=v; i++ )
		{
			cin>>a[i];
		}
		*/
		//vector<list<int> >::iterator it;
		memset(visited,0,sizeof(visited));
		long long ctr;
		long long maxval = INT_MAX;
		for(int i = 1; i <= v; i++)
		{
			ctr = 0;
			if(!visited[i])
			{
				dfs(adj,i, ctr);
				maxval = min(maxval,ctr);
			//	cout<<"For i = "<<i<<" bananas = "<<ctr<<endl;
			}
			//maxval = max(maxval,ctr);
		}
		
		cout<<maxval<<endl;
	
	
	return 0;
}
