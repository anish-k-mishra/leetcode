class Solution {
public:
    bool solve(vector<int>& nums, int ind, int sum, int curr, vector<vector<int>>& dp) {
        if (curr > sum) return false; // Current sum exceeds target sum
        if (ind >= nums.size()) return sum == curr; // Check if the entire array is processed

        if (dp[ind][curr] != -1) {
            return dp[ind][curr];
        }

        bool take = solve(nums, ind + 1, sum, curr + nums[ind], dp);
        bool notTake = solve(nums, ind + 1, sum, curr, dp);

        return dp[ind][curr] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, 0, target, 0, dp);
    }
};
