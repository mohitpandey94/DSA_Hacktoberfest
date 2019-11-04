
//Author <ftw>Retaliation
#include<bits/stdc++.h>

using namespace std;
int fnc(string str, map<string, int>&mp) {
    cout<<"String = "<<str<<endl;
    if(mp.find(str) != mp.end())
        return mp[str];

    int l = 0;
    int h = str.length() - 1;
    if(l == h)
        mp[str] = 0;
    else if(l == h-1) {
        if(str[l]==str[h])
            mp[str] =  0;
        else
            mp[str] = 1;
    } else if(l > h) {
        mp[str] =  INT_MAX;
    } else if(str[l] == str[h]) {
        mp[str] = fnc(str.substr(l+1,str.length() - 2),mp);
    } else {
        mp[str] =  (1+min(fnc(str.substr(l,str.length() - 2),mp),fnc(str.substr(l+1,str.length()-1),mp)));
    }

    return mp[str];
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        map<string,int>mp;
        cin>>s;
        int l = s.length();
        int res = fnc(s,mp);
        cout<<res<<endl;
    }
    return 0;
}
