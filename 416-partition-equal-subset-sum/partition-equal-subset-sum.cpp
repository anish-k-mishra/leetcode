class Solution {
public:
    bool solve(vector<int>&nums, int ind, int target, vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        bool incl = solve(nums, ind+1, target-nums[ind], dp);
        bool excl = solve(nums, ind+1, target, dp);

        return dp[ind][target] = (incl || excl);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2 == 0){
            vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, -1));
            return solve(nums, 0, sum/2, dp);
        }
        return false;
    }
};