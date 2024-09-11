class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(int ind, string& s, vector<int>& dp){
        if(ind == s.length()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int ans = 1e9;
        for(int i = ind; i < s.length(); i++){
            if(isPalindrome(s, ind, i)){
                int cost = 1 + solve(i+1, s, dp);
                ans = min(ans, cost);
            }
        }
        return dp[ind] = ans;
    }
    
    int minCut(string s) {
        vector<int> dp(s.length(), -1);
        return solve(0, s, dp) - 1;
    }
};
