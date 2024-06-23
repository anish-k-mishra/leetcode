class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeque, maxDeque;
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            // Maintain the decreasing deque for maximum values
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) 
                maxDeque.pop_back();
            maxDeque.push_back(nums[j]);

            // Maintain the increasing deque for minimum values
            while (!minDeque.empty() && nums[j] < minDeque.back()) 
                minDeque.pop_back();
            minDeque.push_back(nums[j]);

            // Check if the current window satisfies the condition
            if (maxDeque.front() - minDeque.front() > limit) {
                // If it doesn't, slide the window
                if (maxDeque.front() == nums[i]) maxDeque.pop_front();
                if (minDeque.front() == nums[i]) minDeque.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};
