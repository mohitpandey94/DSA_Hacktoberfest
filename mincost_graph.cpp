#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,c;
	cin>>r>>c;
	int a[r][c];
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin>>a[i][j];
		}
	}
	int dp[r][c];
	dp[0][0] = a[0][0];
	for(int i = 1; i < c; i++)
	{
		dp[0][i] = dp[0][i-1] + a[0][i];
	}
	
	for(int i = 1; i < r; i++)
	{
		dp[i][0] = dp[i-1][0] + a[i][0];
	}
	
	for(int i = 1; i < r; i++)
	{
		for(int j = 1; j < c; j++)
		{
			dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + a[i][j];
		}
	}
	
	cout<<dp[r-1][c-1]<<endl;
}
