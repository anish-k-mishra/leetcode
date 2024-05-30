class Solution {
public:
    void solve(int ind, vector<int>&arr, int tar, vector<int>&v, vector<vector<int>>& ans){
        if(ind>=arr.size()){
            if(tar == 0){
                ans.push_back(v);
            }
            return;
        }

        //check foreach index number can be included or not
        if(arr[ind] <= tar){
            v.push_back(arr[ind]);
            solve(ind, arr, tar-arr[ind], v, ans);
            v.pop_back();

        }
        solve(ind+1, arr, tar, v, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(0, candidates, target, v, ans);
        return ans;
    }
};