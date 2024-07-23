class Solution {
public:
    bool solve(string& s, int ind, int cnt, vector<vector<int>>&dp){
        if(cnt<0){
            return false;
        }
        if(ind == s.length()){
            if(cnt == 0){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[ind][cnt] != -1){
            return dp[ind][cnt];
        }

        if(s[ind] == '('){
            return dp[ind][cnt]= solve(s, ind+1, cnt+1, dp);
        }
        else if(s[ind] == ')'){
            return dp[ind][cnt] = solve(s, ind+1, cnt-1, dp);
        }
        else{
            return dp[ind][cnt] = (solve(s, ind+1, cnt+1, dp) || solve(s, ind+1, cnt-1, dp) || solve(s, ind+1, cnt, dp));
        }
    }
    bool checkValidString(string s) {
        int cnt = 0;
        int ind = 0;
        vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1));
        return solve(s, ind, cnt, dp);
    }
};