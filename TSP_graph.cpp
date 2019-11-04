#include<bits/stdc++.h>
using namespace std;
int a[100][100];
list<set<int> >make_subset(int m)
{
	int n = pow(2,m);

	list<set<int> >lis;
	for(int i = 0; i < n; i++)
	{
		set<int>vec;
		for(int j = 2; j <= m; j++)
		{
			if(i && (1<<(j-1)))
			{
				vec.push_back(j);
			}
		}

		if(vec.empty())
		{
			vec.push_back(-1);
		}
		lis.push_back(vec);
	}
}

void tsp(int n)
{

}
int main()
{
	int m;
	cin>>m;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>a[i][j];
		}
	}

	tsp(m);


}
