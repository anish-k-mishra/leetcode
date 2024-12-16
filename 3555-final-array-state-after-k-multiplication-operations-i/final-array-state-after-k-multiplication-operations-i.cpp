class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>v = nums;
        int n = k; 
        while(n--){
            int mini = INT_MAX;
            int ind = -1;
            for(int i = 0; i<v.size(); i++){
                if(mini>v[i]){
                    mini = v[i];
                    ind = i;
                }
            }
            v[ind] = mini*multiplier;
        }
        return v;
    }
};