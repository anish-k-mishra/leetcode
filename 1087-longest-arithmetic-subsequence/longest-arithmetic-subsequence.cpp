class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int ans = 0;
        unordered_map<int, int>dp[nums.size()+1];
        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;
                //check if ans already present
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};