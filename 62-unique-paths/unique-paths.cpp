class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i>=m || j>= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
            return dp[i][j];
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp;
        for(int i = 0; i<m; i++){
            vector<int>v;
            for(int j = 0; j<n; j++){
                v.push_back(-1);
            }
            dp.push_back(v);
        }
        return solve(0, 0, m, n, dp);
    }
};