#include<bits/stdc++.h>
/*
5
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1
*/
using namespace std;
int a[50][50];
bool visited[50][50];
int tot_island = 0;
bool issafe(int x, int y, int n, int m)
{

    if((x >= 0) && (x < n) && (y >= 0) && (y < m) && !visited[x][y])
        return true;
    return false;
}

void dfs(int x, int y, int n, int m)
{
    if(!issafe(x,y,n,m))
        return;

    visited[x][y] = true;
    //cout<<"x = "<<x<<" and y = "<<y<<endl;
    int rowc[3] = {1,0,-1};
    int colc[3] = {1,0,-1};

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(rowc[i] == 0 && colc[j] == 0)
            {
                continue;
            }
            else
                {
                    if((a[x+rowc[i]][y+colc[j]] == 1) && !visited[x+rowc[i]][y+colc[j]])
                    {
                       // visited[x+rowc[i]][y+colc[j]] = true;
                        dfs(x+rowc[i],y+colc[j],n,m);

                    }
                }
        }
    }
}
int main()
{

    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && a[i][j])
            {
               // cout<<"i = "<<i<<" and j = "<<j<<endl;

                tot_island++;
                dfs(i,j,n,m);
            }
        }
    }

    cout<<tot_island<<endl;
    return 0;
}
