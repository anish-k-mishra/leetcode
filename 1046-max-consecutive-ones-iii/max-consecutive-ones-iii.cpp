class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int zerocnt = 0;
        int maxlen = 0;

        while(r<nums.size()){
            if(nums[r] == 0){
                zerocnt++;
            }
            while(zerocnt >k){
                if(nums[l] == 0){
                    l++;
                    zerocnt--;
                }
                else{
                    l++;
                }
            }
            int len = r-l+1;
            maxlen = max(len, maxlen);
            r++;
        }

        return maxlen;
    }
};