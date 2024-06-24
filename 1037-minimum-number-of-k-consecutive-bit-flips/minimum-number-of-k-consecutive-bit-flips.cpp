class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n, 0);
        int cnt = 0, flipCount = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipCount ^= flip[i - k];
            }
            if (flipCount % 2 == nums[i]) {
                if (i + k > n) return -1;
                flip[i] = 1;
                flipCount ^= 1;
                ++cnt;
            }
        }
        return cnt;
    }
};