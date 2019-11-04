#include<bits/stdc++.h>
using namespace std;
int dp[100];
int fnc(int n)
{
    if(n == 0 || n == 1)
        return n;

    if(dp[n] != -1)
    {
        return dp[n];
    }
    else
        dp[n] = fnc(n - 1)+fnc(n-2);
    return dp[n];
}
int main()
{

    int n;
    cin>>n;
    for(int i = 0; i <= n; i++)
        dp[i] = -1;

    int res = fnc(n);
    cout<<res<<endl;
    return 0;
}
