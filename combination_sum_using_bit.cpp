//When one character can be used only one time
#include<bits/stdc++.h>
using namespace std;
void printoutput(vector<int>res)
{
	for(int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		int n;
		cin>>n;
		int a[n];
		vector<int>res;
		for(int i = 0; i < n; i++)
		{

			cin>>a[i];
		}

		int sum ;
		cin>>sum;
		bool flag = false;
		for(int i = 0; i < pow(2,n); i++)
		{
			int cur_sum = 0;
			res.clear();
			for(int j = 0; j < n; j++)
			{
				if(i&(1<<j))
				{
					cur_sum = cur_sum + a[j];
					res.push_back(a[j]);
				}
			}
			if(cur_sum == sum)
			{
				flag = true;
				cout<<"The Resultant Subset is :"<<endl;
				printoutput(res);

				break;
			}
		}
		if(!flag)
		cout<<"false"<<endl;

	}
}
