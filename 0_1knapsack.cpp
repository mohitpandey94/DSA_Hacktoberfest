#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>&fir,pair<int,int>&sec)
{
	return fir.first < sec.first;
}	

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int w;
	    cin>>n;
	    cin>>w;
	    int val[n];
	    int wt[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin>>val[i];
	    }
	    for(int i = 0; i < n; i++)
	    {
	        cin>>wt[i];
	    }
	    
	    vector<pair<int,int> >v;
	    for(int i = 0; i < n; i++)
	    {
			v.push_back(make_pair(wt[i],val[i]));	    	
		}
		sort(v.begin(),v.end(),compare);
	    int dp[n+1][w+1];
	   /* for(int i = 0; i <= n; i++)
	    {
	    	for(int j = 0; j <=w; j++)
	    	{
	    		dp[i][j] = 1;
			}
		}*/
	    for(int i = 0; i <= w; i++)
	    {
	        dp[0][i] = 0;
	    }
	    
	    for(int i = 0; i <= n; i++)
	    {
	        dp[i][0] = 0;
	    }
	    
	   for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= w; j++)
	        {
	            if(v[i-1].first > j )
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j] = max(v[i-1].second + dp[i-1][j-v[i-1].first],dp[i-1][j]);
	            }
	        }
	    }
	    
	   cout<<dp[n][w];
	   cout<<endl;
	  /* for(int i = 0; i <= n; i++)
	   {
	   	for(int j = 0; j <= w; j++)
	   	{
	   		cout<<dp[i][j]<<" ";
		}
		   cout<<endl;
	   }
	   */
	   
	}
	return 0;
}
