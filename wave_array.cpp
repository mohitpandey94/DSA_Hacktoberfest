#include<bits/stdc++.h>
using namespace std;
vector<int>wave(vector<int>&A)
{

 // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    int n = A.size();
    for(int i = 0; i < n-1; i+=2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}
int main()
{
    int n;
    cin>>n;
    vector<int>res;
    vector<int>A;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        A.push_back(ele);
    }
    res = wave(A);
     vector<int>::iterator it;
        for(it = res.begin(); it != res.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    return 0;
}
