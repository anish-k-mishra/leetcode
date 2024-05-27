class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int x = n;
        
        while(x>=0){
            int cnt = 0;
            for(int i = 0; i<n; i++){
                if(nums[i] >= x){
                    cnt++;
                }
            }
            if(cnt == x){
                return cnt;
            }
            x--;
        }
        return -1;
    }
};