#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int fnc(int dim[],int l, int h, int n)
{
    if(dp[l][h] != -1)
    {
        return dp[l][h];
    }
    int res = INT_MAX;

        if(l + 1 == h)
        {
            return 0;
        }
        else if(h == l+2)
        {
            return dim[l]*dim[l+1]*dim[h];
        }

    for(int i = l+1; i < h; i++)
    {
        res = min(res,fnc(dim,l,i,n)+fnc(dim,i,h,n)+dim[l]*dim[i]*dim[h]);
    }
    dp[l][h] = res;

    if(res == INT_MAX)
    {
        cout<<"INF"<<endl;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int dim[n+1];
    for(int i = 0; i <=n; i++)
    {
        cin>>dim[i];
    }
    for(int i = 0; i <= n; i++)
    {

        for(int j = 0; j <= n; j++)
        {

            dp[i][j] = -1;
        }
    }
    int res = fnc(dim,0,n,n);
    cout<<res<<endl;
    return 0;
}
