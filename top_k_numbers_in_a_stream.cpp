
//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
struct mmp
{
    int val = 0;
    int freq = 0;
};
bool compare(mmp a, mmp b)
{
    if(a.freq == b.freq)
    {
        return a.val < b.val;
    }
   else
        return a.freq > b.freq;
}
int main()
{
   /* int t;
    cin>>t;
    while(t--)
    {

        int n,k;
        cin>>n>>k;
        map<int,int>mp;
        mmp[n];
        map<int,int>::iterator it;
        int ele;
        bool flag = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>ele;
            if(flag && (mp.find(ele) == mp.end())
            {
                break;
            }

            if(mp.find(ele) != mp.end())
            {
                mp[ele] = 1+mp[ele];
            }
            else
            {
                mp[ele] = 1;
            }
            for(it = mp.begin(); it != mp.end(); it++)
            {
                cout<<it->first<<" ";
            }
            if(mp.size() == k)
            {
                flag = 1;
            }
        }



      /*  for(int i = 0; i < k; i++)
        {
            cout<<pq.top();
            pq.pop();
        }
        */
    //}
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        mmp a[101];
        map<int,int>mp;
        map<int,int>::iterator it;
        int z = 0;
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
                int ele;
                cin>>ele;
                mp[ele]++;
                if(mp.size() > k)
                {
                    flag = 1;
                }
                z = 0;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            a[z].val = it->first;
            a[z].freq = it->second;
            z++;
        }
        sort(a,a+n,compare);
        for(int i = 0; (i < z && i < k); i++)
        {
            cout<<a[i].val<<" ";
        }

        }
        cout<<endl;
    }
return 0;
}
/*Output WRONG
2
5 4
5 2 1 3 2
5 2 5 1 2 5 1 2 3 5
5 2 1 3 4
5 2 5 1 2 5 1 2 3 5
*/
