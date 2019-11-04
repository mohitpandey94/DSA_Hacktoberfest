//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
int dp[102][102];
int sum(int a[], int i, int j)
{
    int s = 0;
    for(int r = i; r <= j; r++)
        s+=a[r];

    return s;
}
int fnc1(int f[], int i, int j)
{
    if(i > j)
    return 0;
    if(i == j)
    {
        dp[i][j] = f[i];
        return f[i];
    }


    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        int minv = INT_MAX;
        int s = sum(f,i,j);
        //cout<<"s = "<<s<<endl;
        for(int r = i; r<=j; r++)
        {
           int cost = 0;
           // if(dp[i][r-1] != -1)
                cost = cost + fnc1(f,i,r-1);
            //if(dp[r+1][j] != -1)
                cost = cost + fnc1(f,r+1,j);
           // cout<<"cost = "<<cost<<endl;
            minv = min(minv,cost);
        }
        dp[i][j] = minv + s;
    }
    return dp[i][j];
}
int fnc(int a[], int freq[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return fnc1(freq,0,n-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j = 0; j < n; j++)
        {
            cin>>a[j];
        }
        int freq[n];
        for(int j = 0; j < n; j++)
        {
            cin>>freq[j];
        }

        cout<<fnc(a,freq,n)<<endl;
    }
return 0;
}
