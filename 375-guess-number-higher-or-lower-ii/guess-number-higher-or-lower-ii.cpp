class Solution {
public:
    int solve(int s, int e, vector<vector<int>>&dp){
        if(s>=e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i = s; i<= e; i++){

            ans = min(ans, i+max(solve(s, i-1, dp), solve(i+1, e, dp)));
        }
        return dp[s][e] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
};