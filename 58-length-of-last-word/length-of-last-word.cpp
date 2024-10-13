class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool lastsp = false;
        bool wordenc = false;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == ' ' && !wordenc){
                lastsp = true;
                continue;
            }
            else if(s[i] != ' '){
                wordenc = true;
                ans++;
            }

            if(s[i] ==' ' && wordenc){
                break;
            }
        }
        return ans;
    }
};