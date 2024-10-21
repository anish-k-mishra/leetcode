class Solution {
public:
    void f(set<string> &st, string s, int ind, int& maxi){
        if(ind == s.length()){
            maxi = max(maxi, (int)st.size());
            return;
        }
        for(int i = ind; i<s.length(); i++){
            string str = s.substr(ind, i-ind+1);
            if(st.find(str) == st.end()){
                st.insert(str);
                f(st, s, i+1, maxi);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        int maxi = 0;
        f(st, s, 0, maxi);
        return maxi;
    }
};