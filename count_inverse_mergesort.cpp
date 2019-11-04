//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
int ctr;
void mergef(int a[], int l, int mid, int h)
{

    int b[h-l+1];
    //cout<<"size of b = "<<(h-l+1)<<endl;
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= h)
    {
        if(a[i] <= a[j])
        {
          b[k++] = a[i];
          i++;
        }
        else
        {
            ctr += (mid - i + 1);
            b[k++] = a[j];
            j++;
        }
    }
    while(i <= mid)
    {
        b[k++] = a[i++];
    }
    while(j <= h)
    {
        b[k++] = a[j++];
    }

    for(i = l,j = 0; j < k && i <= h; i++,j++)
    {
        a[i] = b[j];
    }
    //cout<<"ctr = "<<k<<endl;
}
void mergefnc(int a[], int l, int h)
{
    //cout<<"l = "<<l<<" , h = "<<h<<endl;
    if(l >= h)
    return;

    int mid = (l+h)/2;
    mergefnc(a,l,mid);
    mergefnc(a,mid+1,h);
    mergef(a,l,mid,h);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ctr = 0;
        int n;
        cin>>n;

        int a[n];

        for(int i = 0; i < n; i++)
        cin>>a[i];

        mergefnc(a,0,n-1);
        cout<<ctr<<endl;
    }
return 0;
}
