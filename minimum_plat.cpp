#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arriv[n];
	int dep[n];
	for(int i = 0; i < n; i++)
	{

		cin>>arriv[i];
	}
	for(int i = 0; i < n; i++)
	{

		cin>>dep[i];
	}

	sort(arriv,arriv+n);
	sort(dep,dep+n);

	int i = 0; int j = 0;
	int cur_plat = 1;
	int res = INT_MIN;
	while( i < 0 && j < n)
	{
		if(arriv[i] >= dep[j])
		{
			cur_plat--;
			j++;
		}
		else
		{
			cur_plat++;
			i++;
			res = max(res,cur_plat);
		}
	}

	cout<<res<<endl;
	return 0;
}
