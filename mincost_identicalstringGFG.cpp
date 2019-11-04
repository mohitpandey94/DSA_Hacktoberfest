#include<bits/stdc++.h>
using namespace std;
int dp[20][20];
int fnc(string str1, string str2,int i, int j, int m, int n, int cost1, int cost2)
{
    if(i == m && j == n)
        return 0;
    if(i == m)
    {
        return cost2 *(n - j);
    }
    if(j == n)
    {
        return cost1*(m-i);
    }

    if(dp[i][j] != -1)
    {

        return dp[i][j];
    }

    if(str1[i] == str2[j])
    {
        dp[i][j] = fnc(str1,str2,i+1,j+1,m,n,cost1,cost2);
    }
    else
    {

        dp[i][j] = min(cost1 + fnc(str1,str2,i+1,j,m,n,cost1,cost2),cost2 + fnc(str1,str2,i,j+1,m,n,cost1,cost2));
    }

    return dp[i][j];
}
int main()
{

    string str1;
    cin>>str1;
    int n = str1.length();
    string str2;
    cin>>str2;
    int m = str2.length();
    int cost1,cost2;
    cin>>cost1>>cost2;
    for(int i = 0; i < n; i++)
    {
        for(int j= 0; j < m; j++)
        {
            if(str1[i] == str2[j])
            {
              dp[i][j] = 0;
            }
            dp[i][j] = -1;
        }
    }
   int res = fnc(str1,str2,0,0,n,m,cost1,cost2);
   cout<<res<<endl;
}
