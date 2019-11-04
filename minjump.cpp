#include <bits/stdc++.h>
using namespace std;
int fnc(int a[], int n)
{
    int jump[n];
    jump[0] = 0;
    for(int i = 1; i < n; i++)
        jump[i] = INT_MAX;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if((j + a[j]) >= i)
            {
                if((jump[j] + 1) < jump[i])
                {
                    jump[i] = jump[j] + 1;
                }
            }
        }
    }

    return jump[n - 1];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin>>a[i];
	    }
	    if(n == 0 || a[0] == 0)
	    {
	        cout<<"-1"<<endl;
	        continue;
	    }
	    int res = fnc(a,n);
	    cout<<res<<endl;
	}
	return 0;
}
