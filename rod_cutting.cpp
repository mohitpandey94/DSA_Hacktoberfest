#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int p[100];
int fnc(int n)
{
    if(n == 0)
        return 0;

    if(dp[n] != 0)
    {
        return dp[n];
    }

    int q = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        q = max(q,p[i] + fnc(n - i));
    }

    dp[n] = q;
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>p[i];

    memset(dp,0,sizeof(dp));
    cin>>n;
    int res = fnc(n);
    cout<<res<<endl;
    return 0;
}
