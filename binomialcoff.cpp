#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int fnc(int n, int k)
{
    if(n < k)
        return 0;
    for(int i = 0; i <= n; i++)
    {

        dp[i][0] = 1;
    }
    for(int i =  1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(i == j)
            {
                dp[i][j] = 1;
               // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
        }
    }

    return dp[n][k];
}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j<=k; j++)
        {
            dp[i][j] = 0;
        }
    }
   int res =  fnc(n,k);
    cout<<res<<endl;
    return 0;
}
