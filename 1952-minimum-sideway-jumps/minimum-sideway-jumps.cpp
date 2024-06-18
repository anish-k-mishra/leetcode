class Solution {
public:
    int solve(vector<int>&obs, int currlane, int currpos, vector<vector<int>>&dp){
        int n = obs.size()-1;
        if(currpos == n){
            return 0;
        }
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }

        if(obs[currpos + 1] != currlane){
            dp[currlane][currpos] = solve(obs, currlane, currpos + 1, dp);
            return dp[currlane][currpos];
        }
        else{
            int ans = INT_MAX;
            for(int i = 1; i<=3; i++){
                if(currlane != i && obs[currpos] != i){
                    ans = min(ans, 1+ solve(obs, i, currpos, dp));
                }
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        return solve(obstacles, 2, 0, dp);
    }
};