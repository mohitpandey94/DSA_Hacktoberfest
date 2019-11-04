#include<bits/stdc++.h>
using namespace std;

int dp[31][31];
int fnc(string str, int l , int h, int n)
{
    if(dp[l][h] != -1)
        return dp[l][h];

    if(l > h)
        return 0;

}
int countPS(string str)
{
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return fnc(str,0,n-1,n);
}
int main()
{
    string str;
    cin>>str;

    int res = countPS(str);
    cout<<res<<endl;
    return 0;
}
