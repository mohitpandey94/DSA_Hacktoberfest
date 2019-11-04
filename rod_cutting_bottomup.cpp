#include<bits/stdc++.h>
using namespace std;
int fnc(int p[], int n, int m)
{
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }

    }

   // cout<<"p[0] = "<<p[0]<<endl;
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = i * p[0];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(i > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(dp[i -1][j],p[i - 1] + dp[i][j - i]);
        }
    }


    return dp[n][m];
}

int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i = 0; i < n; i++)
        cin>>p[i];

   // memset(dp,0,sizeof(dp));
    //cin>>n;
    int m;
    cin>>m;
    int res = fnc(p,n,m);
    cout<<res<<endl;
    return 0;
}
