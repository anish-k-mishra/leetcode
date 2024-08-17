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
        bool flag = true;
        vector<int>ans;
        while(j<nums.size()){
            if(flag == true){
                if(isSorted(i, j, nums)){
                    ans.push_back(nums[j]);   
                    flag = false;
                }
                else{
                    ans.push_back(-1);
                }
                
            }
            else{
                if(nums[j]>nums[j-1] && nums[j-1]+1 == nums[j]){
                    ans.push_back(nums[j]);
                }
                else{
                    while(i<j){
                        ans.push_back(-1);
                        i++;
                        if(i+k-1 >= nums.size()){
                            break;
                        }
                    }
                    flag = true;
                    j+=k-1;
                    continue;
                }
            }
            i++;
            j++;
        }
        return ans;
    }
};