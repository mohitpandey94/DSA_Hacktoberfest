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

        int a[n];
        for(int i = 0; i < n; i++)
        cin>>a[i];
		if(n <= 1)
        {
        cout<<n<<endl;
        continue;
        }
        int cum[n];
        cum[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            cum[i] = a[i]+cum[i-1];
        }

        for(int i = 1; i < n-1; i++)
        {
            if(cum[i-1] == (cum[n-1]-cum[i]))
            {
              //  cout<<"here"<<endl;
                cout<<(i+1)<<endl;
                break;
            }

        }



    }
return 0;
}

