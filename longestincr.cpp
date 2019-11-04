#include<bits/stdc++.h>
using namespace std;
int dp(int a[], int n)
{
    int dp[n];
    for(int i = 0; i < n; i++)
    {
    	dp[i] = 1;
	}
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    sort(dp,dp+n);
    for(int i = 0; i < n; i++)
    {
    	cout<<dp[i]<<" ";
	}
	cout<<endl;
    return dp[n-1];
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i = 0; i < n; i++)
   {
       cin>>a[i];
   }

   int res = dp(a,n);
   cout<<res<<endl;
}
