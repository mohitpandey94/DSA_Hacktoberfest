#include<bits/stdc++.h>
using namespace std;
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout <<"first = "<< q.top().first << " , second = "<<q.top().second<<" , ";
        q.pop();
    }
    std::cout << '\n';
}
struct PairComparator {
  bool operator()( const pair<int, int>& p1, const pair<int, int>& p2 ) const 
    {  if( p1.first < p2.first ) return true;
        //if( p2.first < p1.first ) return false;
        //return p1.second < p2.second;
    }
};

int main()
{
	int n;
	cin>>n;
	int weights[n];
	int benifit[n];
	
	//cout<<"Enter the weights of n items:\n";
	for(int i = 0; i < n; i++)
	cin>>weights[i];
	
	//cout<<"Enter the benifit values for n items:\n";
	for(int i = 0; i < n; i++)
	cin>>benifit[i];
	
	int cap;
	cin>>cap;
	pair<int,int>pr;
	priority_queue<pair<int,int> >pq;
	for(int i = 0; i < n; i++)
	{
		pq.push(make_pair(benifit[i]/weights[i],i));
	}
	
	int cur_cap = cap;
	int cur_ind = 0;
	int profit = 0;
	
	//cout<<"\nCreated queue is :-\n";
//	print_queue(pq);
/*
3
10 20 30
60 100 120
50
*/
	while(!pq.empty()) 
	{
		//cout<<"Element's benefit is = "<<benifit[pq.top().second]<<" and Weight is = "<<weights[pq.top().second]<<endl;
		
		if(cur_cap <= 0 || cur_cap < weights[pq.top().second])
		{
			break;
		}
		
		//cout<<"Element's benefit is = "<<benifit[pq.top().second]<<" and Weight is = "<<weights[pq.top().second]<<endl;
		if(weights[pq.top().second] <= cur_cap)
		{
			profit = profit + benifit[pq.top().second] ;
			cur_cap = cur_cap - weights[pq.top().second];
		}
		pq.pop();
	}
	if(!pq.empty())
	{
		profit = profit + pq.top().first*cur_cap;
	}
	cout<<"\nprofit = "<<profit<<endl;
	//print_queue(pq);
	//cout<<endl;
	return 0;
}	
