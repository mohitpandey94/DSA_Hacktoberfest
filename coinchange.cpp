#include<bits/stdc++.h>
using namespace std;
long long coinchange2(vector<int> &A, long longB) {

    long long m = A.size();
    long long n = B;
   long long dp[m+1][n+1];
   for(long long i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for(long long i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    for(long long i = 1; i <=m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(A[i-1] > j)
            {
                dp[i][j] = dp[i- 1][j];
               // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j - A[i - 1]];
                 //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
        }
    }

    return dp[m][n];
}

int main()
{
	long long cost;
	cin>>cost;
	long long n;
	cin>>n;
	vector<int>v;
	long long ele;
	for(long long i = 0; i < n; i++)
	{
		cin>>ele;
		v.push_back(ele);
	}


	long long res = coinchange2(v,cost);
	cout<<res<<endl;
	return 0;
}
