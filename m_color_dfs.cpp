//Author chanfool21
#include<bits/stdc++.h>

using namespace std;
int a[51][51];
int color[100];
set<int>done;
/*1
4
5
3
1 2 2 3 3 4 4 1 1 3
*/
bool color_fnc(int s,int c, int col, int n)
{
	if(c > col)
		return false;
	if(done.size() == n)
		return true;
    color[s] = c;
    //cout<<"s = "<<s<<" and col = "<<c<<endl;
    done.insert(s);
    for(int i = 1; i <= n; i++)
    {
    	//cout<<" i1 = " << i<<endl;
        if(i != s && a[s][i] && color[i] == -1)
        {
        	//cout<<"i = " << i<<endl;
            for(int j = 1; j <= col; j++)
            {
            	if(j == c)
					continue;
                if(color_fnc(i,j,col,n))
                {
                    return true;
                }

            }
        }
        if(i != s && color[i] == c)
		{
			return false;
		}
    }

    color[s] = -1;
    done.erase(done.find(s));
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	done.clear();
        int v,e;
        cin>>v>>e;
        int col;
        cin>>col;
      //  int a[v+1][v+1];
        for(int i = 0; i <= v; i++)
        {
            for(int j = 0; j <= v; j++)
            {
                a[i][j] = 0;
            }
        }

        for(int i = 0; i < e; i++)
        {
            int src,dest;
            cin>>src>>dest;
            a[src][dest] = 1;
            a[dest][src] = 1;
        }
        for(int i = 0; i <= v; i++)
        {
            color[i] = -1;
        }

        if(color_fnc(1,1,col,v))
        {
           for(int i = 1; i <= v; i++)
		   {

		   	cout<<"color "<< i <<" = " <<color[i]<<endl;
		   }
        }
        else
        {
            cout<<0<<endl;
        }
    }
return 0;
}
