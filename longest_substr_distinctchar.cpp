#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string temp;
	    cin>>temp;
	    int n = temp.length();
	    bool dp[n][n];
	    memset(dp,false,sizeof(dp));
int max_len = 1;
	    for(int i = 0; i < n - 1; i++)
	    {
	        if(temp[i] == temp[i+1])
	        dp[i][i+1] = true;
	        else
				max_len = 2;
	    }


	    for(int l = 3; l <= n; l++)
	    {
	        for(int i = 0; i <= (n-l); i++)
	        {
	            int j = i+l-1;
	            if((temp[i] != temp[j])&&(!dp[i][j-1]&& !dp[i+1][j]))
	            {
	                dp[i][j] = false;
	                max_len = max(max_len,l);
	            }
	            else
	            dp[i][j] = true;
	        }
	    }

	    cout<<max_len<<endl;
	}
	return 0;
}
