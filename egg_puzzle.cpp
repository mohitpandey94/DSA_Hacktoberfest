#include<bits/stdc++.h>
using namespace std;
int fnc(int e, int f)
{
    int dp[e+1][f+1];
    for(int i = 0; i<=e; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int i = 1; i <= f; i++)
    {
        dp[1][i] = i;
    }
    int res;
    for(int i = 2; i <= e; i++)
    {
        for(int j = 2; j <= f; j ++)
        {
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= j; k++)
            {
                res = 1 + max(dp[i - 1][k - 1],dp[i][j - k]);
                if(res < dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }

    return dp[e][f];
}
int main()
{
    int egg;
    cin>>egg;
    int floor;
    cin>>floor;
    int res = fnc(egg,floor);
    cout<<res<<endl;
    return 0;
}
