#include<bits/stdc++.h>
using namespace std;
int dp[20][20];
int fnc(string str, int l, int h,bool flag)
{
    if(l == h)
    {
        if(str[l] == '0' && flag == false )
        {
            return 1;
        }
        else if(str[l] == '1' && flag == true)
        {
            return 1;
        }
        else
            return 0;
    }

    if(dp[l][h] != -1)
    {
        return dp[l][h];
    }

    int c = 0;
    if(flag)
    {
        for(int i = l+1;i<=h;i+=2)
        {
            if(str[i] == '|')
            {
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,true);
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,false);
                c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,true);
            }
            else if(str[i] == '&')
            {
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,true);
            }
            else if(str[i] == '^')
            {
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,false);
                c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,true);
            }
        }
    }
    else
    {
        for(int i = l+1;i<=h;i+=2)
        {
            if(str[i] == '&')
            {
                c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,false);
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,false);
                c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,true);
            }
            else if(str[i] == '&')
            {
              c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,false);
            }
            else if(str[i] == '^')
            {
                c+=fnc(str,l,i-1,true) * fnc(str,i+1,h,true);
                c+=fnc(str,l,i-1,false) * fnc(str,i+1,h,false);
            }
        }
    }
    dp[l][h] = c;
    return dp[l][h];
}
int main()
{

    string str;
    cin>>str;
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        for(int j= 0; j < n; j++)
        {
            if(i == j)
            {
                if(str[i] == '0')
                {
                    dp[i][j] = false;
                }
                else if(str[i] == '1')
                {
                    dp[i][j] = true;
                }
            }
            dp[i][j] = -1;
        }
    }
   int res = fnc(str,0,n-1,true);
   cout<<res<<endl;
}
