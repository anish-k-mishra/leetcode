class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long int>pre(nums.size());
        long long int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            pre[i] = sum;
        }
        int ans = 0;
        for(int i = 1; i<nums.size(); i++){
            if(pre[i-1] >= pre.back()-pre[i-1]){
                ans++;
            }
        }

        return ans;
    }
};