#include<bits/stdc++.h>
using namespace std;

void printoutput(vector<int>vec)
{
	cout<<"(";
	for(int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<")";
}
void fncutil(int a[],int ind, int n, int cursum, int sum,vector<int>vec)
{

	if(cursum > sum)
		return;
	if(cursum == sum)
	{
		printoutput(vec);
		return;
	}

	for(int i = ind; i < n; i++)
	{
		vec.push_back(a[i]);
		fncutil(a,i,n,cursum+a[i],sum,vec);
		vec.pop_back();
	}
}
void fnc(int a[], int n, int sum)
{
	vector<int>vec;
	fncutil(a,0,n,0,sum,vec);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	sort(a,a+n);
	map<int,int>mp;
	//vector<int>c;
	int c[10000];
	int ctr = 0;
	   for(int i = 0; i < n; i++)
    {
        mp[a[i]] += 1;
        if(mp[a[i]] == 1)
        {
            c[ctr++] = a[i];
        }
    }
    for(int i = 0; i < ctr; i++)
    {

        cout<<c[i]<<" ";
    }
    cout<<endl;
	int sum = 0;
	cin>>sum;

	fnc(c,ctr,sum);
	return 0;
}
