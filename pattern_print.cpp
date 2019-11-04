#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A;
    cin>>A;
    int ctr = A;
    int n = 2*A - 1;
    int l = 0;
    int r = n - 1;
    int u = 0;
    int d = n - 1;
   // vector<vector<int> >res;
    int a[n][n];
    memset(a,0,sizeof(a));
    while((l <= r)&&(u <= d))
    {
        for(int i = l; i <= r; i++)
        {
            a[u][i] = ctr;
        }
        for(int i = u + 1; i <= d; i++)
        {
            a[i][r] = ctr;
        }
        for(int i = r-1; i >= l; i--)
        {
            a[d][i] = ctr;
        }

        for(int i = d-1; i >= u; i--)
        {
            a[i][l] = ctr;
        }
        ctr--;
        l++;
        u++;
        r--;
        d--;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
