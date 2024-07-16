class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            return -1;
        }
        int piv = -1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                piv = i;
                break;
            }
        }
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                if(piv == -1){
                    return mid;
                }
                return (mid+piv + 1)%nums.size();
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
};