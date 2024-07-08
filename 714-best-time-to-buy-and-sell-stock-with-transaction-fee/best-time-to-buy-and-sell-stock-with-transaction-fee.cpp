class Solution {
public:
    int solve(int ind, int buy, int fee, vector<int>&prices, vector<vector<int>>&dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+solve(ind+1, 0, fee, prices, dp), solve(ind+1, 1, fee, prices, dp));
        }
        else{
            profit = max(prices[ind]+solve(ind+1, 1, fee, prices, dp)-fee, solve(ind+1, 0, fee, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};