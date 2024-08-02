class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int win = 0;
        for(int i = 0; i<nums.size(); i++){
            win+=nums[i];
        }
        int max1 = 0;
        int curr1 = 0;
        for(int i = 0; i<win; i++){
            curr1 += nums[i];
        }
        max1 = curr1;
        int s = 0;
        int e = win-1;
        while(s<nums.size()){
            if(nums[(e+1)%nums.size()] == 1){ //% for handeling circular condition
                curr1++;
            }
            if(nums[s] == 1){
                curr1--;
            }
            e++;
            s++;
            max1 = max(max1, curr1);
        }
        return win-max1;
    }
};