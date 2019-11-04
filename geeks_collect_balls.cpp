//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n],b[m];

        for(ll i = 0; i < n; i++)
            cin>>a[i];

        for(ll i = 0; i < m; i++)
            cin>>b[i];

     //   ll hash_a[1002],hash_b[1002];
        ll pre_a[n],pre_b[m];

//        memset(hash_a,0,sizeof(hash_a));
  //      memset(hash_b,0,sizeof(hash_b));
        memset(pre_a,0,sizeof(pre_a));
        memset(pre_b,0,sizeof(pre_b));

        pre_a[n-1] = a[n-1];
        pre_b[m-1] = b[m-1];

        for(ll i = n-2; i >= 0; i--)
        {
            pre_a[i] = pre_a[i+1] + a[i];
        }
        for(ll i = m-2; i >= 0; i--)
        {
            pre_b[i] = pre_b[i+1] + b[i];
        }


       // for(ll i = 0; i < n; i++)
         //   hash_a[a[i]] = i;

        //for(ll i = 0; i < m; i++)
          //  hash_b[b[i]] = i;

        ll k = 0;
        ll l = 0;

        int flag = 0;
        long long int res = 0;

        if(pre_a[0] > pre_b[0])
        {
            res = a[0];
            k++;
        }
        else if(pre_a[0] < pre_b[0])
        {
            res = b[0];
            l++;
            flag = 1;
        }
        else
        {
            if(a[0] > b[0])
            {
                res = a[0];
                k++;
            }
            else
            {
                res = b[0];
                l++;
                flag = 1;
            }
        }
        ll ind = 0;
        while(k < n && l < m)
        {
            if(!flag)
            {
                res = res + a[k];
                if(binary_search(b,b+m,a[k]))
                {
                     ind = (lower_bound(b,b+m,a[k]) - &b[0]);
                    if(pre_a[k] < pre_b[ind])
                    {
                        flag = 1;
                        l = ind + 1;
                    }
                    else
                    {
                        k++;
                    }
                }
                else
                {
                    k++;
                }
            }
            else
            {
                res = res + b[l];
                if(binary_search(a,a+n,b[l]))
                {
                    ind = (lower_bound(a,a+n,b[l]) - &a[0]);
                    if(pre_b[l] < pre_a[ind])
                    {
                        flag = 0;
                        k = ind + 1;
                    }
                    else
                    {
                        l++;
                    }
                }
                else
                {
                    l++;
                }
            }
        }
        cout<<res<<endl;

    }
return 0;
}
