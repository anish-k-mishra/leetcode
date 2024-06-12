#include <vector>
#include <string>

class Solution {
public:
    string getPermutation(int n, int k) {
        // Factorials from 0! to (n-1)!
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        // Numbers from 1 to n
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        
        // Adjust k to be zero-indexed
        k--;

        // Generate the k-th permutation
        string result;
        for (int i = n; i >= 1; --i) {
            int j = k / factorial[i - 1];
            result.push_back('0' + nums[j]);
            nums.erase(nums.begin() + j);
            k %= factorial[i - 1];
        }
        
        return result;
    }
};
