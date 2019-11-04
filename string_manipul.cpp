//Author chanfool21
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        stack<string>st1;
        stack<string>st2;
        string temp;
        for(int i = 0 ; i < n-1; i++)
        {
            cin>>temp;
            st1.push(temp);
        }
        cin>>temp;
        st2.push(temp);
      //  cout<<"s1 = "<<st1.size()<<endl;
        //cout<<"s2 = "<<st2.size()<<endl;
        while(!st1.empty())
        {
            if(!st2.empty())
            {
                if(st1.top().compare(st2.top()) != 0)
                {
                    st2.push(st1.top());
                }
                else
                {
                    st2.pop();
                }
            }
            else
            {
                st2.push(st1.top());
            }

            st1.pop();
            // cout<<"s1 = "<<st1.size()<<endl;

        }
        cout<<st2.size()<<endl;

    }
return 0;
}
