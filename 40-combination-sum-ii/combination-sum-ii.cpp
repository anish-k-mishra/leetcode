class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue; // skip duplicates

            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], current, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, current, ans);
        return ans;
    }
};
