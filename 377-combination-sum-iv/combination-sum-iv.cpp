class Solution {
public:

    int solve(vector<int>&nums, int tar, vector<int>&dp){
        if(tar == 0){
            return 1;
        }
        if(tar<0){
            return 0;
        }
        //step 3
        if(dp[tar] != -1){
            return dp[tar];
        }
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans += solve(nums, tar-nums[i], dp);
        }
        //step 2
        dp[tar] = ans;
        return dp[tar];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};