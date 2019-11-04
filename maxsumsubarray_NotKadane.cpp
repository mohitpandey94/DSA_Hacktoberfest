#include<bits/stdc++.h>
using namespace std;

vector<int>maxset(vector<int> &A) {
 pair<int,int>res = make_pair(-1,-1);
 int maxsum = INT_MIN;
 int cursum = 0;
 int l = 0;
 int r = 0;
 for(int i = 0; i < A.size(); i++)
 {
     if(A[i] < 0)
     {
         cursum = 0;
         l = i+1;
         r = i+1;
     }
     else
     {
         cursum += A[i];
         if(cursum > maxsum)
         {
             res.first = l;
             res.second = i;
             maxsum = cursum;
  //           cout<<"maxsum = "<<maxsum<<endl;
         }
         else if(cursum == maxsum)
         {
             if((res.second -res.first) < (i - l) )
             {
                 res.first = l;
                 res.second = i;
             }
         }
         r = i;
     }
 }
//cout<<"L = "<<res.first<<" , R = "<<res.second<<endl;
 vector<int>resA;
 if(l == -1)return resA;
 for(int i = res.first; i <= res.second; i++)
 {
     resA.push_back(A[i]);
 }
return resA;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        vec.push_back(ele);
    }
    vector<int>res = maxset(vec);
    if(res.size() > 0)
    {
        vector<int>::iterator it;
        for(it = res.begin(); it != res.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;

    return 0;
}
