class Solution {
public:
    bool isPrefixAndSuffix(string& s1, string& s2){
        int n = s1.length();
        if(s1.length()>s2.length()){
            return false;
        }
        for(int i = 0; i<n; i++){
            if(s2[i] != s1[i]){
                return false;
            }
        }
        for(int i = 0; i<n; i++){
            if(s2[s2.length()-n+i] != s1[i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};