class Solution {
public:
    int solve(string& a, string& b, int i, int j){
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]){
            return solve(a, b, i+1, j+1);
        }
        else{
            //insert
            int ins = 1+solve(a, b, i, j+1);
            //delete
            int del = 1 + solve(a, b, i+1, j);
            //replace
            int rep = 1 + solve(a, b, i+1, j+1);
            ans = min(ins, min(del, rep));
        }
        return ans;
    }
    int solveTab(string&a, string&b){
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));
        for(int i = 0; i<a.length(); i++){
            dp[i][b.length()] = a.length()-i;
        }
        for(int j = 0; j<b.length(); j++){
            dp[a.length()][j] = b.length()-j;
        }

        for(int i = a.length()-1; i>=0; i--){
            for(int j = b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //insert
                    int ins = 1+dp[i][j+1];
                    //delete
                    int del = 1+dp[i+1][j];
                    //replace
                    int rep = 1+dp[i+1][j+1];
                    ans = min(ins, min(del, rep));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return solveTab(word1, word2);
    }
};