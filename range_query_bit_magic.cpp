#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    //cin>>q;
    int n;
        cin>>n;
        int a[n];

        for(int i = 0; i < n;i++)
        {
            cin>>a[i];
        }
        cin>>q;
        int bit[33];
        bit[0] = 0;

        int ql[q][2];

        for(int i = 0; i < q; i++)
        {
            cin>>ql[i][0];
            cin>>ql[i][1];
        }

        memset(bit,0,sizeof(bit));

        for(int j = 0; j < n; j++)
        {

            for(int i = 0;i<32;i++)
            {
                if(a[j]&(1<<i))
                {
                    bit[j]=1+bit[j];
                }
            }
        }


        for(int i = 1; i <32; i++)
        {
            bit[i] = 1 + bit[i-1];
        }


        for(int i = 0; i < q; i++)
        {
            cout<<bit[ql[i][1]]-bit[ql[i][0]]+1<<endl;
        }


    return 0;
}
