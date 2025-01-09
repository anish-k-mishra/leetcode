class Solution {
public:
    bool isPresent(string& a, string& b){
        for(int i = 0; i<b.length(); i++){
            if(b[i] != a[i]){
                return false;
            }
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i<words.size(); i++){
            if(isPresent(words[i], pref)){
                cnt++;
            }
        }
        return cnt;
    }
};