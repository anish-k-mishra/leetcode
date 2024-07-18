class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;

        // Iterate over nums2 to find next greater elements
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int current = nums2[i];
            while (!s.empty() && s.top() <= current) {
                s.pop();
            }
            nextGreater[current] = s.empty() ? -1 : s.top();
            s.push(current);
        }

        // Prepare the result for nums1 using the nextGreater map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
