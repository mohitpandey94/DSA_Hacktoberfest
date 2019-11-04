#include<bits/stdc++.h>
using namespace std;
vector<int>flip(string A) {
int n = A.length();
int i = 0;
int ctr = 0;
int ctrm = 0;
int flag = 0;
int l,r;
int lr,rr;
lr = rr = -1;
l = r = -1;
while(i < n)
{
    if(ctr < 0)
    {
        ctr = 0;
    }

    if(A[i] == '0')
    {
        ctr++;
        if(ctr == 1)
        {
            l = i;
            r = i;
        }
        if(ctr > ctrm)
        {
            r = i;
            lr = l;
            rr = r;
            ctrm = ctr;
        }
        r = i;
    }
    else
    ctr--;
    i++;
}

vector<int>res();
    if(lr != -1 && rr != -1)
    {
        res.push_back(lr);
        res.push_back(rr);
    }
return res;
}

int main()
{
    string str;
    cin>>str;
    vector<int>res;
    res = flip(str);
    if(res.size())
    {
        cout<<res[0]<<","<<res[1];
    }
    else
    {
        cout<<"empty"<<endl;
    }
    return 0;
}
