class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<= n-3; i++){
            if(nums[i] == 0){
                for(int j = i; j<=i+2; j++){
                    if(nums[j] == 0){
                        nums[j] = 1;
                    }
                    else if(nums[j] == 1){
                        nums[j] = 0;
                    }
                }
                cnt++;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                return -1;
            }
        }
        return cnt;
        
    }
};