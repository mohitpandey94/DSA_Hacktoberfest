
#include <iostream>
using namespace std;



int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int right_pro[n];
    int left_pro[n];

    right_pro[n-1] = 1;
    left_pro[0] = 1;
    for(int i = n-2; i >= 0; i--)
    {
    	if(a[i] == 0)
			right_pro[i] = 1;
		else
        right_pro[i] = a[i+1]*right_pro[i+1];
    }

     for(int i = 1; i < n; i++)
    {
    	if(a[i] == 0)
			left_pro[i] = 1;
		else
        left_pro[i] = a[i-1]*left_pro[i-1];
    }

    for(int i = 0; i < n; i++)
    {
        cout<<left_pro[i]*right_pro[i]<<" ";
    }
    cout<<endl;
    return 0;
}
