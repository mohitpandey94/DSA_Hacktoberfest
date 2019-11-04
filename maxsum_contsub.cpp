#include<bits/stdc++.h>
using namespace std;
int dp(int a[], int n)
{
	int sum_cur = 0;
	int maxsum = 0;

	

		for(int i = 0; i < n; i++)
		{
			if((sum_cur + a[i])< 0)
			{
				sum_cur = 0;
			}
			else
			{
				sum_cur = sum_cur + a[i];
				if(maxsum < sum_cur)
				{
					maxsum = sum_cur;
				}
			}
		}
	
	
	return maxsum;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++)
	{
	cin>>a[i];
	b[i] = a[i];
	}
	sort(a,a+n);
	if(a[n - 1]<= 0)
	{
		 cout<<a[n - 1]<<endl;
		 return 0;
	}
	
	int res = dp(b,n);
	cout<<res<<endl;
	return 0;
}
