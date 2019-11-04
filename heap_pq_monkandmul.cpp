#include <bits/stdc++.h>
using namespace std;

int main()
{
   	int n;
   	cin>>n;
   	priority_queue<int>q;
   	long long a,b,c;
   	for(int i = 0; i < n; i++)
   	{
   		int ele;
   		cin>>ele;
   		q.push(ele);
   		if(q.size() < 3)
   		{
   			cout<<"-1"<<endl;
   		}
   		else
   		{

   			long long pro = 1;
   			 a = q.top();
   			q.pop();
   			 b = q.top();
   			q.pop();
   			 c = q.top();
   			pro = a*b*c;
   			q.push(a);
   			q.push(b);
   			cout<<pro<<endl;
   		}
   	}
    return 0;
}
