class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size(), 0);
        stack<int>s;
        for(int i = prices.size()-1; i>=0; i--){
            int curr = prices[i];
            while (!s.empty() && s.top() > curr) {
                s.pop();
            }
            ans[i] = s.empty() ? prices[i] : abs(s.top()-prices[i]);
            s.push(curr);
        }
        return ans;
    }
};