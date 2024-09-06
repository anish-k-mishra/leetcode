class Solution {
public:
    int solve(int ind, int amt, vector<int>& coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(amt%coins[0] == 0){
                return amt/coins[0];
            }
            return INT_MAX;
        }
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }

        int excl = solve(ind-1, amt, coins, dp);
        int incl = INT_MAX;
        if(coins[ind]<=amt){
            int res = solve(ind, amt-coins[ind], coins, dp);
            if(res!= INT_MAX){
                incl = 1+res;
            }
        }
        return dp[ind][amt] = min(incl, excl);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins.size()-1, amount, coins, dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};