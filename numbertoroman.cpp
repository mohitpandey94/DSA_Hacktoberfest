#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;
void initialise_map()
{
    mp[1] = "I";
    mp[4] = "IV";
    mp[5] = "V";
    mp[9] = "IX";
    mp[10] = "X";
    mp[40] = "XL";
    mp[50] = "L";
    mp[90] = "XC";
    mp[100] = "C";
    mp[400] = "CD";
    mp[500] = "D";
    mp[900] = "CM";
    mp[1000] = "M";
}
void print_single(int num)
{
    if(num == 0)
    {
        return;
    }
    if(mp.find(num) != mp.end())
    {
     //   cout<<"num  = "<<num<<" is found"<<endl;
        cout<<mp[num];
        return;
    }
    map<int,string>::iterator it;
    map<int,string>::iterator prev;
    prev = mp.begin();
    int flag = 0;
    for(it = mp.begin(); it != mp.end(); it++)
    {

        if(it->first > num)
        {
            flag = 1;
            cout<<prev->second;
       //     cout<<"remaining val = "<<num - prev->first<<endl;
            print_single(num - prev->first);
            return;
        }
        else
            prev = it;
    }
    if(flag == 0)
    {
        cout<<prev->second;
         print_single(num - prev->first);

    }


}
void print_roman(int n)
{
    stack<int>st;
    while(n > 0)
    {
       // cout<<n%10<<endl;
        st.push(n%10);
        n = n/10;
    }

    int ctr = st.size() - 1;
    //cout<<" ctr = "<<ctr<<endl;
    while(!st.empty())
    {
        int temp = st.top();
        int val = temp * ceil(pow(10,ctr));
        ctr--;
       //cout<<"val = "<<val;
        print_single(val);
       // break;
        st.pop();
    }
}
int main()
{
    initialise_map();
    int n;
    cin>>n;
    print_roman(n);
    return 0;

}
