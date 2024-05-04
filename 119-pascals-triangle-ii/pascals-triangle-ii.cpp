class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<int> ans;
        long long int sum = 1;
        ans.push_back(sum);
        for(int i = 1; i<n; i++){
            sum = (sum*(n-i))/i;
            ans.push_back(static_cast<int>(sum));
        }
        return ans;
    }
};