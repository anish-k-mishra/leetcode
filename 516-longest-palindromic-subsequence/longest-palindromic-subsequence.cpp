class Solution {
public:
    int solve(string& a, string& b){
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));
        for(int i = a.length()-1; i>=0; i--){
            for(int j = b.length()-1; j>=0; j--){
                int res = 0;
                if(a[i] == b[j]){
                    res = 1 + dp[i+1][j+1];
                }
                else{
                    res = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(s.begin(), s.end());
        return solve(revs, s);
    }
};