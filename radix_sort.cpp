#include<bits/stdc++.h>
using namespace std;
void countingsort(int a[], int n, int e)
{
    int freq[10];
    memset(freq,0,sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        freq[(a[i]/e)%10]++;
    }
    for(int i = 1; i < 10; i++)
    {

        freq[i] = freq[i-1] + freq[i];
    }
    int b[n];
    for(int i = n - 1; i >=0; i--)
    {
        b[(freq[(a[i]/e)%10]) - 1] = a[i];
        freq[(a[i]/e)%10]--;
    }
/*
for(int i = 0; i < n; i++)
{
    b[(freq[(a[i]/e)%10]) - 1] = a[i];
        freq[(a[i]/e)%10]--;
}
*/
     for(int i = 0; i < n; i++)
    {
       a[i] = b[i];
    }
}
void radixsort(int a[], int n)
{
    int maxv = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        maxv = max(maxv,a[i]);
    }

    int ctr = 0;
    while(maxv > 0)
    {
        maxv = maxv/10;
        ctr++;
    }
    cout<<"ctr = "<<ctr<<endl;
    int dig = 1;
    for(int i = 1; i < (int)pow(10,ctr); i*=10)
    {
        countingsort(a,n,i);
        cout<<"After "<<dig<<" position bit, the sorted values are :\n";
         for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        dig++;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Before sorting:\n";
     for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    radixsort(a,n);

    cout<<"After sorting:\n";
     for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
8
170 45 75 90 802 24 2 66
*/
/*
snd_updateaudiocache
snd_rebuildaudiocache
snd_mix_async 1
snd_mixahead 0.05
*/
