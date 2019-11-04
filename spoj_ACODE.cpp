#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int fnc(string str, int i, int n)
{
    if(dp[i] != -1)
        return dp[i];
    if(i == n-1)
        return 1;
    if(i == n)
        return 1;
    int res = 0;
    res = fnc(str,i+1,n);
    if((10*(str[i] - '0')+(str[i+1]-'0')) <= 26)
    {
        res = res+fnc(str,i+2,n);
    }
    dp[i] = res;
    return dp[i];
}
int main()
{
    string str;
    cin>>str;
    int n = str.length();
    memset(dp,-1,sizeof(dp));
    int res = fnc(str,0,str.length());
    cout<<res<<endl;
}
