class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean*(n+m);
        int msum = 0;
        for(int i = 0; i<rolls.size(); i++){
            msum+=rolls[i];
        }
        int nsum = sum-msum;

        vector<int>ans;
        if(nsum<n || nsum>n*6){
            return ans;
        }
        int avg = nsum/n;
        int dist = nsum%n;
        for(int i = 0; i<n; i++){
            ans.push_back(avg);
            if(dist>0){
                if(ans[i]+1<=6){
                    ans[i] += 1;
                    dist--;
                }
            }
        }
        return ans;
    }
};