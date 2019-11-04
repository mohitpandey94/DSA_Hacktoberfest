//Author chanfool21
#include<bits/stdc++.h>

using namespace std;

void fnc(string res, int pos, int prev, int n)
{
    //cout<<"res = "<<res<<endl;
    if(pos > n)
    return;
    if(pos == n)
    {
        cout<<res<<endl;

        return;
    }

    for(int i = prev + 1; i <= 9; i++)
    {
        res.push_back(i+'0');
        fnc(res,pos+1,i,n);
        res.erase(res.end() - 1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string res = "";
        fnc(res,0,0,n);
    }
return 0;
}
