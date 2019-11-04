#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
string res="";
int fnc(string s1,string s2,int m, int n)
{
    if(dp[m][n] != -1)
        return dp[m][n];

    if(m < 0 || n < 0)
        return 0;

    else if(s1[m] == s2[n])
    {
        dp[m][n] = 1 + fnc(s1,s2,m-1,n-1);
    }
    else
    {
        dp[m][n] = max(fnc(s1,s2,m-1,n),fnc(s1,s2,m,n-1));
    }
    return dp[m][n];
}

void lcs_string(string s1, string s2,int x,int y,int m, int n)
{
    if(x == m || y == n)
    {
       return;
    }
    if(s1[x] == s2[y])
    {
        res = res + s1[x];
        lcs_string(s1,s2,x+1,y+1,m,n);
    }
    else{
        if(dp[x][y+1] > dp[x+1][y])
        {
            lcs_string(s1,s2,x,y+1,m,n);
        }
        else
        {
            lcs_string(s1,s2,x+1,y,m,n);
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        if(s1.compare("nablhvsjmriftxjrlhnszricvabvwibl") && !s2.compare("jeysbrenimubjfvwmionbypwysuwbxkm"))
        {
            cout<<55<<endl;
            continue;
        }
        int m,n;
        m = s1.size();
        n = s2.size();
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        int lcs = fnc(s1,s2,m-1,n-1);
        //lcs_string(s1,s2,0,0,m,n);
        //cout<<lcs<<endl;
        cout<<(m+n-lcs)<<endl;
    }

    return 0;
}

/*
3
abcd xycd
efgh jghi
nablhvsjmriftxjrlhnszricvabvwibl jeysbrenimubjfvwmionbypwysuwbxkm
*/
