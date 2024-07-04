class Solution {
public:
    int solve(vector<int>&arr, map<pair<int, int>, int>&maxi, int l, int r, vector<vector<int>>&dp){
        if(l == r){
            //leaf node
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int ans = INT_MAX;
        for(int i = l; i<r; i++){
            ans = min(ans, maxi[{l, i}]*maxi[{i+1, r}] + solve(arr, maxi, l, i, dp) + solve(arr, maxi, i+1, r, dp));
        }
        return dp[l][r] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int>maxi;
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i<arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j = i+1; j<arr.size(); j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        return solve(arr, maxi, 0, arr.size()-1, dp);
    }
};