class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        //finding the break point
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }

        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
            // return nums;
        }
        //finding the first greater number 
        for(int i = n-1; i>=0; i--){
            if(nums[ind]<nums[i]){
                swap(nums[ind], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
        // return nums;

    }
};