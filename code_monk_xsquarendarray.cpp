#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    long long a[n+1];
    long long b[n+1];

    for(int i = 1; i <= n; i++)
        cin>>a[i];

    for(int i = 1; i <= n; i++)
        cin>>b[i];


    for(int i = 2; i <= n; i+=2)
    {
        swap(a[i],b[i]);
    }



    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        a[i] = a[i] + a[i - 1];
        b[i] = b[i] + b[i - 1];
    }



    int t,l,r;
    while(q--)
    {

        cin>>t>>l>>r;
        if(t == 1)
        {

            cout<<(a[r] - a[l - 1])<<"\n";
        }
        else
        {

            cout<<(b[r] - b[l - 1])<<"\n";
        }
    }

    return 0;
}
