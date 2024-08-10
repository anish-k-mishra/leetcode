class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        while(i<s.length()){

            while(i<s.length() && s[i] == ' '){
                i++;
            }
            int j = i+1;
            while(j<s.length() && s[j] != ' '){
                j++;
            }
            string w = s.substr(i, j-i);
            ans = w+ " "+ans;
            i = j;
        }
         i = 0;
        int j = ans.length()-1;
        while(ans[i] == ' '){
            i++;
        }
        while(ans[j] == ' '){
            j--;
        }
        ans = ans.substr(i, j-i+1);
        return ans;
    }
};