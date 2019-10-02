//https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    int recurse(vector<int> coins, int amount, vector<int> &memo, int maxx) {
        if ( amount == 0) return 0;
        // if (amount < 0) return INT_MAX;
        if (memo[amount] != -1) return memo[amount];
        int ans = maxx;
       // cout<<curamount<<" "<<coinused<<"\n";
        for (int i=0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0)
                ans = min(ans, recurse(coins, amount-coins[i], memo, maxx)+1);
        }
        return memo[amount] = ans;
    }
    
     int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);
        int ans =  recurse(coins, amount, memo, amount+1);
        return ans == amount+1 ? -1 : ans;
    }
    
   
};

