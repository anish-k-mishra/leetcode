class Solution {
public:
    int solve(int ind, vector<int>&arr, int k, vector<int>& dp){
        if(ind == arr.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int ans = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j = ind; j<min((int)arr.size(), ind+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len*maxi + solve(j+1, arr, k, dp);
            ans = max(ans, sum);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1, -1);
        return solve(0, arr, k, dp);
    }
};