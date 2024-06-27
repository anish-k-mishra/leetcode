class Solution {
public:
    int solve(int ind, vector<int>&v, int n, int end, vector<vector<int>>&dp){
        if(n == 0 || ind>end){
            return 0;
        }
        if(dp[ind][n] != -1){
            return dp[ind][n];
        }
        int take = v[ind] + solve(ind+2, v, n-1, end, dp);
        int notTake = 0 + solve(ind+1, v, n, end, dp);
        return dp[ind][n] = max(take, notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>>dp1(k, vector<int>(k, -1));
        int case1 = solve(0, slices, k/3, k-2, dp1);
        vector<vector<int>>dp2(k, vector<int>(k, -1));
        int case2 = solve(1, slices, k/3, k-1, dp2);
        return max(case1, case2);
    }
};