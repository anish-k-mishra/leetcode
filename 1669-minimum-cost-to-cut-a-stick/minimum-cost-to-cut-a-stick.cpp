class Solution {
public:
    int mcm(int i, int j, vector<int>&v, vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k<=j; k++){
            int cost = v[j+1]-v[i-1] + mcm(i, k-1, v, dp) + mcm(k+1, j, v, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return mcm(1, cuts.size()-2, cuts, dp);
    }
};