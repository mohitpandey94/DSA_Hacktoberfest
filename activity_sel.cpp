#include<bits/stdc++.h>
using namespace std;
bool compare(pair<pair<int, int>,int>i,const pair<pair<int, int>,int>j)
{
    return i.first.first < j.first.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int start[n];
        int end[n];
        vector<pair<pair<int,int> , int> >v;
        for(int i = 0; i < n; i++)
        {
            cin>>start[i];
        }
         for(int i = 0; i < n; i++)
        {
            cin>>end[i];
        }


         for(int i = 0; i < n; i++)
        {
            v.push_back(make_pair(make_pair(end[i],start[i]),i));
        }

        sort(v.begin(),v.end(),compare);
        cout<<v[0].second<<" ";
        int prev;
        prev = v[0].first.first;
        vector<pair<pair<int,int> , int> >::iterator it;
        for(it = v.begin()+1; it != v.end(); it++)
        {
            if(prev < it->first.second)
            {
            cout<<it->second<<" ";
            prev = it->first.first;
            }
        }

        cout<<endl;
        return 0;
    }
}
