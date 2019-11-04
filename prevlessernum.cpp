#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin>>n;
	vector<int>a;
	while(n>0)
	{
		a.insert(a.begin(),n%10);
		n = n/10;
	}

	for(int i = 0; i < a.size(); i++)
	{
		//cout<<a[i]<<" ";
	}
	//cout<<endl;

	int i,j;
	for( i = a.size()-1; i >=1; i--)
	{
		if(a[i] < a[i-1])
		{
			break;
		}
	}
	//cout<<" i = "<<i-1<<endl;
	int max_ind = i;
	int max_val = a[i];
	for(j = i+1; j < a.size(); j++)
	{

		if(a[j] > max_val)
		{
			max_val = a[i];
		//	cout<<"max val = "<<max_val<<endl;
			max_ind = j;
		}
	}
	swap(a[i-1],a[max_ind]);

	sort(a.begin()+i,a.end());
	for( i = 0; i < a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
