class Solution {
public:
    bool isSorted(int i, int j, vector<int>& nums){
        for(int k = i+1; k<=j; k++){
            if( nums[k]<=nums[k-1] || nums[k] != nums[k-1]+1){
                return false;
            }
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i = 0;
        int j = k-1;
        vector<int>ans;
        while(j<nums.size()){
            if(isSorted(i, j, nums)){
                ans.push_back(nums[j]);
            }
            else{
                ans.push_back(-1);
            }
            i++;
            j++;
        }
        return ans;
    }
};