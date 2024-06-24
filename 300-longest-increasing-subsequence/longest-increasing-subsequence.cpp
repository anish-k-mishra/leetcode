#include <bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>&nums, int n){
        if(n == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]); //1st element undergoes no comparison and has to be pushed
        for(int i = 1; i<n; i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);

            }
            else{
                //find the just greater element index
                int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, nums.size());
    }
};