#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];

	sort(a,a+n);
	int ad[n][2];
	int j = 1;
	int k = 0;
	while(j < n-1)
	{
		int ctr = 1;
		while(a[j] == a[j-1])
		{
			ctr++;
			j++;
		}

	}
}
