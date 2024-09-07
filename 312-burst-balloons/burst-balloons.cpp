class Solution {
public:
    int bb(int i, int j, vector<int>&v, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxi = INT_MIN;
        for(int k = i; k<=j; k++){
            int coin = v[i-1]*v[k]*v[j+1] + bb(i, k-1, v, dp) + bb(k+1, j, v, dp);
            maxi = max(maxi, coin);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return bb(1, n, nums, dp);
    }
};