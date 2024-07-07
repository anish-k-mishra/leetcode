class Solution {
public:
    int maxProfit(vector<int>& prices) { //Bottom up dp with SO
        vector<int>curr(2, 0);
        vector<int>next(2, 0);
        for(int ind = prices.size()-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[ind]+next[0]), (0+next[1]));
                }
                else{
                    profit = max((prices[ind]+next[1]), (0 + next[0]));
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};