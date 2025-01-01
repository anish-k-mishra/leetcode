class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int i = 1; i<s.length(); i++){
            int sc = 0;
            for(int j = 0; j<i; j++){
                if(s[j] == '0'){
                    sc++;
                }
            }
            for(int j = i; j<s.length(); j++){
                if(s[j] == '1'){
                    sc++;
                }
            }
            ans = max(ans, sc);
        }
        return ans;
    }

};