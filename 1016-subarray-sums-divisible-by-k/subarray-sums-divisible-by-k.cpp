class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
    int prefixSum = 0;
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1;  // Initialize with 0 remainder count 1

    for (int num : nums) {
        prefixSum += num;
        int remainder = prefixSum % k;

        // If the remainder is negative, adjust it to be positive
        if (remainder < 0) {
            remainder += k;
        }

        // Count subarrays with the same remainder
        count += remainderCount[remainder];

        // Update the remainder count
        remainderCount[remainder]++;
    }

    return count;
    }
};