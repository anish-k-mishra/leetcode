class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(nums[mid] > target){
                e = mid - 1;

            }
            if(nums[mid] < target){
                s = mid +1;
            }
            if(nums[mid] == target){
                return mid;
            }
            
            mid = s + (e-s)/2;
        }
        return mid;

    }
};