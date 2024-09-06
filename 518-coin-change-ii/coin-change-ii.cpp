class Solution {
public:
    int solve(int amt, int ind, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == coins.size() && amt >0){
            return 0;
        }
        if(amt == 0){
            return 1;
        }
        if(amt<0){
            return 0;
        }
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }
        int excl = solve(amt, ind+1, coins, dp);
        int incl = 0;
        if(coins[ind] <= amt){
            incl = solve(amt-coins[ind], ind, coins, dp);
        }
        return dp[ind][amt] = incl+excl;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(amount, 0, coins, dp);
        return ans;
    }
};