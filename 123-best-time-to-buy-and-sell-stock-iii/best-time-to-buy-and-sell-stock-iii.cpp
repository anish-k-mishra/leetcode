class Solution {
public:
    int solve(int ind, int buy, int limit, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(ind == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        if(dp[ind][buy][limit] != -1){
            return dp[ind][buy][limit];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, limit, prices, dp), 0+solve(ind+1, 1, limit, prices, dp));
        }
        else{
            profit = max(prices[ind]+solve(ind+1, 1, limit-1, prices, dp), 0+solve(ind+1, 0, limit, prices, dp));
        }
        return dp[ind][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};