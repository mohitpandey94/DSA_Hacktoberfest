#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>&p1, const pair<int,int>&p2)
{
	return p1.first < p2.first;
}
int main()
{

	int n;
	cin>>n;
	int a[n];
	int m;
	cin>>m;
	int b[m];
	priority_queue<pair<int,int> >pq;
	for(int i = 0; i < n ; i++)
	{
		cin>>a[i];
		pq.push(make_pair(a[i],i));
	}
	for(int i = 0; i < m; i++)
	{

		cin>>b[i];
	}

	int ctr = 0;
	vector<pair<int,int> >vec;
	while(ctr < m)
	{
		pair<int,int>temp;
		temp = pq.top();
		pq.pop();
		vec.push_back(make_pair(temp.second,temp.first));
		ctr++;
	}

	//vec.sort(vec.begin(),vec.end(),compare);
	int res = 0;
	sort(vec.begin(),vec.end(),compare);

	for(int i = 0; i < m; i++)
	{

		res = res + b[i]*vec[i].second;
	}

	cout<<res<<endl;
	return 0;
}
