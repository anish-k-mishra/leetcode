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
    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(s.length()+1, vector<int>(revs.length()+1, -1));
        return solve(revs, s, 0, 0, dp);
    }
};