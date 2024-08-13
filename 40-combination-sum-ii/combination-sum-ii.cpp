class Solution {
public:
    bool isPresent(vector<vector<int>>& ans, vector<int>& v) {
        if (ans.size() == 0) {
            return false;
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == v) {
                return true;
            }
        }
        return false;
    }

    void solve(int ind, vector<int>& arr, int tar, vector<int>& v, vector<vector<int>>& ans) {
        if (tar == 0) {
            if (!isPresent(ans, v)) {
                ans.push_back(v);
            }
            return;
        }
        if (ind >= arr.size() || tar < 0) {
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue; // Skip duplicates

            v.push_back(arr[i]);
            solve(i + 1, arr, tar - arr[i], v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, v, ans);
        return ans;
    }
};
