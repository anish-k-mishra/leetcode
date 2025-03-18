class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s =0;
        int ans = 0;
        int mask = 0;
        int n = nums.size();
        for(int e = 0; e<n; e++){
            while((mask & nums[e]) != 0){
                mask = mask^nums[s];
                s++;
            }
            mask = mask|nums[e];
            ans = max(ans, e-s+1);
        }
        return ans;
    }
};