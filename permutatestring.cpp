#include<bits/stdc++.h>
using namespace std;

//map<string,int>mp;
//int ctr = 0;
void permutate(string str, int cur, int n)
{
	if(cur == (n-1))
	{
		/*if(mp.find(str) == mp.end())
		{
			cout<<str<<endl;
			mp[str] = 1;
			ctr++;
		}
		*/
		cout<<str<<endl;

		return;
	}

	for(int i = cur; i < n; i++)
	{
		swap(str[cur],str[i]);
		permutate(str,cur+1,n);
		swap(str[cur],str[i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	//mp.clear();
	string str;
	cin>>str;
	permutate(str,0,str.length());
	//cout<<"Counter = "<<
	//ctr<<endl;
	//ctr = 0;
	}
	return 0;
}
