//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
bool sieve[10000000];
void createsieve(int n)
{
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i <= n; i++)
    sieve[i] = true;

    for(int i = 2; i <= n; i++)
    {
        if(sieve[i])
        {
            for(int j = 2; i*j <= n; j++)
            {
               sieve[i*j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    long long l[n],r[n];
    for(int i = 0; i < n; i++)
    {
        cin>>l[i]>>r[i];
    }
    long long int rng = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        rng = max(rng,r[i]);
    }
    createsieve(rng);

    for(int i = 0; i < n; i++)
    {
        long long count_prim = 0;
        long long count_comp = 0;
        for(long long j = l[i]; j <= r[i]; j++)
        {
            if(j == 1)
                continue;
            if(!sieve[j])
            count_comp++;
            else
            count_prim++;
        }

        cout<<(count_comp-count_prim)<<endl;
    }
return 0;
}
