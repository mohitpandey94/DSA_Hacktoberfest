#include<bits/stdc++.h>
using namespace std;
int fn(int n)
{
    if(n == 0 || n == 1 || n == 2)
        return 1;

    if(n == 3)
        return 2;

        return fn(n - 1) + fn(n - 3) + fn( n - 4);
}

int dp[10000];
int fnc(int n)
{
     if(n == 0 || n == 1 || n == 2)
        return 1;

    if(n == 3)
        return 2;

    if(dp[n] != 0)
        return dp[n];

    else
        dp[n] = fnc(n - 1)+fnc(n - 3)+fnc(n - 4);

    return dp[n];

}
int main()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    cout<<fnc(n)<<endl;
    return 0;
}
