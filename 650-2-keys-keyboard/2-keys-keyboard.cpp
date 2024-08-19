class Solution {
public:
    int solve(int cnt, int curr, int n, vector<vector<int>>&dp){
        if(cnt == n){
            return 0;
        }
        if(cnt>n){
            return 1000;
        }
        if(dp[cnt][curr] != -1){
            return dp[cnt][curr];
        }

        //paste
        int res1 = 1+ solve(cnt+curr, curr, n, dp);

        //copy+paste;
        int res2 = 2+ solve(cnt+cnt, cnt, n, dp);

        return dp[cnt][curr] = min(res1, res2);
    }
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return 1+ solve(1, 1, n, dp);
    }
};