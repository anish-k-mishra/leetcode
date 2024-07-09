class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>&dp){
        if(i>=a.length() ||j>=b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            return dp[i][j] = 1+solve(a, b, i+1, j+1, dp);
        }
        else{
            return dp[i][j] = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};