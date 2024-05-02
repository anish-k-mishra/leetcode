class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        while(nums[j]>0 && nums[i]<0){
            if(abs(nums[i]) < nums[j]){
                j--;
            }
            else if(nums[j] < abs(nums[i])){
                i++;
            }
            else if(abs(nums[i]) == nums[j]){
                return nums[j];
            }
        }
        return -1;
    }
};