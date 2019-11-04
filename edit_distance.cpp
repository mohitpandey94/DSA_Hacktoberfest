#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	int n;
	cin>>n;
	int m;
	cin>>m;
	char str1[n+1];
	char str2[m+1];
	cin>>str1;
	cin>>str2;
	int dp[n+1][m+1];
	for(int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}
	
	for(int i = 0; i <= m; i++)
	{
		dp[0][i] = i;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
			}
		}
	}
	
	
	cout<<dp[n][m]<<endl;
	}
	return 0;
}
