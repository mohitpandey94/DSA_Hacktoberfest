#include <bits/stdc++.h>
using namespace std;
long long dp[11000];
long long fnc(int n)
{
	if(n == 0)
		return 0;


	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		dp[i] = i * dp[i - 1];
	}
	return dp[n];
}
int main()
{
    int n;
    int t;
    cin>>t;
    long long res;
    memset(dp,0,sizeof(dp));
    while(t--)
    {
    	scanf("%d",&n);
    	res = fnc(n);
    	printf("%lld\n",res);
    }

    return 0;
}
