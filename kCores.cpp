//Elimination of the vertices having less than k degree
#include<bits/stdc++.h>
using namespace std;

int visited[100];
bool fnc(vector<vector<int> >adj,vector<int>&degree,int k, int v, int s)
{
    visited[s] = true;
    vector<int>:: iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++ )
    {
        if(degree[s] < k)
            degree[*it]--;

        if(!visited[*it])
        {
            if(fnc(adj,degree,k,v,*it))
            {
                degree[s]--;
            }
        }
    }

    return (degree[s] < k);

}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int> >adj(v);
    vector<int>degree(v);
    memset(visited,0,sizeof(int)*v);
    int s,d;
    for(int i = 0; i < e; i++)
    {

        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
        //cout<<"check"<<endl;
        degree[s] = 1+degree[s];
        degree[d] = 1+degree[d];
        //cout<<"check"<<endl;
    }

    int k;
    cin>>k;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            fnc(adj,degree,k,v,i);
        }
    }

    for(int i = 0; i < v; i++)
    {
        if(degree[i] >= k)
        {
                cout<<i;
                vector<int>:: iterator it;
                for(it = adj[i].begin(); it != adj[i].end(); it++ )
                {
                    if(degree[*it] >= k)
                    {
                        cout<<" -> ";
                        cout<<*it;
                    }
                }
                 cout<<endl;
        }

    }

    return 0;
}
