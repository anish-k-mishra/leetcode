class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1){
            return s.length();
        }
        set<char>st;
        int i = 0, j = 0;
        int ans = INT_MIN;
        while(j<s.length()){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                while(st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
                ans = max(ans, j-i+1);
                st.insert(s[j]);
                j++;
            }
        }
        return ans;
    }
};