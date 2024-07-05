class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int currcnt = 0;
        int prev = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == prev){
                continue;
            }
            else if(nums[i] != prev+1){
                currcnt = 1;
                prev = nums[i];
            }
            else if(nums[i] == prev+1){
                currcnt++;
                prev = nums[i];
            }
            longest = max(currcnt, longest);
        }
        return longest;
    }
};