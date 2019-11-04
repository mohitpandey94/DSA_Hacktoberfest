#include<bits/stdc++.h>
using namespace std;
struct compare
{
bool operator()(const pair<int,char>&i, const pair<int,char>&j)
{
    return i.first > j.first;
}
};
int main() {
	// your code goes here
	priority_queue<pair<int,char>,vector< pair<int,char> >,greater<pair<int,char> > >pq;
	int n;
	cin>>n;
	int arr[n];
	int dep[n];
	for(int i = 0; i < n; i++)
	{
	cin>>arr[i];

	pq.push(make_pair(arr[i],'a'));
	}
	for(int i = 0; i < n; i++)
	{
	cin>>dep[i];
	pq.push(make_pair(dep[i],'d'));
	}

	int res = 0;
	int cur = 0;

	int s = pq.size();
	pair<int,char>p;
	while(s--)
	{
		p = pq.top();
		if(p.second == 'a')
		{
	//	cout<<"arrival time = "<<p.first<<endl;
			cur++;
			res = max(res,cur);

		}
		else
		{

	//	cout<<"depart time = "<<p.first<<endl;
		cur--;
		}
		pq.pop();
	}

	cout<<res<<endl;
	return 0;
}
