#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout<<dp[n]<<endl;
    return 0;
}
