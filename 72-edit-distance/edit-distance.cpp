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
    int solveTabSO(string&a, string&b){
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int>curr(b.length()+1, 0);
        vector<int>next(b.length()+1, 0);
        
        for(int j = 0; j<b.length(); j++){
            next[j] = b.length()-j;
        }

        for(int i = a.length()-1; i>=0; i--){
            for(int j = b.length()-1; j>=0; j--){
                curr[b.length()] = a.length()-i;
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    //insert
                    int ins = 1+ curr[j+1];
                    //delete
                    int del = 1+ next[j];
                    //replace
                    int rep = 1+ next[j+1];
                    ans = min(ins, min(del, rep));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        return solveTabSO(word1, word2);
    }
};