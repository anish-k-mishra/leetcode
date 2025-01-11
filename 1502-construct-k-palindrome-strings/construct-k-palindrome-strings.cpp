class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        if(s.length() == k) return true;
        vector<int>freq(26);
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        int oddcnt = 0;
        for(int i = 0; i<26; i++){
            if(freq[i]%2 != 0){
                oddcnt++;
            }
        }
        if(oddcnt <= k){
            return true;
        }
        return false;
    }
};