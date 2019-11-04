#include<bits/stdc++.h>
using namespace std;

vector<vector<long long int> >res;

void fnc(vector<long long int>&temp,long long int ind,long long int pro,long long int a[], long long int n, long long int k)
{
   // cout<<"pro = "<<pro<<endl;
    //cout<<"ind = "<<ind<<endl;
    if(pro > k)
    {
        temp.pop_back();
        return;
    }
    if(pro == k)
    {
        res.push_back(temp);
        temp.pop_back();
        return;
    }
    for(long long int i = ind; i < n; i++)
    {
        if(k%a[i] != 0)
            continue;
        temp.push_back(a[i]);
        fnc(temp,i,pro*a[i],a,n,k);

    }
    temp.pop_back();
}
int lexic_small(vector<long long int>a,vector<long long>b)
{
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] > b [i])
            return 2;
        else
            return 1;
    }
}
int main()
{
    long long int n,k;
    cin>>k>>n;
    long long a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<long long int>());
    vector<long long int>temp;
    temp.push_back(1);
    fnc(temp,0,1,a,n,k);
    long long int nt = res.size();
    int min_size = INT_MAX;
    vector<vector<long long int> >fin_res;

    for(long long i = 0; i < nt; i++)
    {
        if(res[i].size() < min_size)
        {
            min_size = res[i].size();
        }
        for(long long j = 0; j < res[i].size();j++)
        {
           // cout<<res[i][j]<<" ";
        }
       // cout<<endl;
    }
   // cout<<nt<<endl;

    for(long long i = 0; i < nt; i++)
    {
        if(res[i].size() == min_size)
        {
            fin_res.push_back(res[i]);
        }
    }

    int min_ind = 0;
    long long int l = 0;
    while(l < fin_res.size()-1)
    {
        if(lexic_small(fin_res[min_ind],fin_res[l+1]) == 1)
        {
            min_ind = l;
        }
        else
        {
            min_ind = l+1;
        }
        l++;
    }
    sort(fin_res[min_ind].begin(),fin_res[min_ind].end());
    for(l = 2; l < fin_res[min_ind].size(); l++)
    {
        fin_res[min_ind][l] *= fin_res[min_ind][l-1];
    }
    for(l = 0; l < fin_res[min_ind].size(); l++)
    {
        cout<<fin_res[min_ind][l]<<" ";
    }
    cout<<endl;
    return 0;

}
