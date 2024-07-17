class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int mid){
        int pagecnt = 0;
        int childcnt = 1;
        for(int i = 0; i<nums.size();i++){
            if(pagecnt + nums[i] <= mid){
                pagecnt += nums[i];
            }
            else{
                childcnt++;
                if(childcnt>k || nums[i] > mid){
                    return false;
                }
                pagecnt = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        for(int i = 0; i<nums.size(); i++){
            e += nums[i];
        }
        int ans = -1;
        int mid = s +(e-s)/2;
        while(s<=e){
           
            if(isPossible(nums, k, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s +(e-s)/2;
        }
        return ans;
    }
};