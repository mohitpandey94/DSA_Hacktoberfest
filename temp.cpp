#include<iostream>
#include<algorithm>
using namespace std;
int dp(int a[], int n)
{
    int dp[n];
    memset(dp,1,sizeof(n));
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j+1];
                }
            }
        }
    }

    sort(dp,dp+n);
    return dp[n-1];
}
int main()
{
   int n;
   cin>>n;
   for(int i = 0; i < n; i++)
   {
       cin>>a[i];
   }

   int res = dp(a,n);
   cout<<res<<endl;
}
