#include<bits/stdc++.h>
using namespace std;
//geeksforgeeks 7
//qwertyuioijhghmnbvcdswwazxcv 10
int fnc(string str)
{
    map<int,int>mp;
    int beg = 0;
    int n = str.length();
    int maxlen = 1;
    int curlen = 0;
    for(int i = beg; i < n; i++)
    {
        if(mp.find(str[i]) == mp.end())
        {
            curlen++;
            mp[str[i]] = i;
        }
        else
        {
            if(mp[str[i]] < beg)
            {
                curlen++;
                mp[str[i]] = i;
            }
            else
            {
                maxlen = max(maxlen,curlen);
                cout<<"index = "<<i<<" and char = "<<str[i]<<" and curlen = "<<curlen<<endl;
                beg = mp[str[i]]+1;
                cout<<"beg = "<<beg<<endl;
                curlen = 0;
            }
        }
         maxlen = max(maxlen,curlen);
    }

    return maxlen;
}
int main()
{

    string str;
    cin>>str;
    int res = fnc(str);
    cout<<res<<endl;
    return 0;
}
