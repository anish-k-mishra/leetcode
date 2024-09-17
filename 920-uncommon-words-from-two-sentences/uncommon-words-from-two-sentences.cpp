class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>m;
        int i = 0;
        int j = i;
        while(j<s1.length()){
            string s = "";
            if(s1[j+1] == ' ' || j+1 == s1.length()){
                s += s1.substr(i, j-i+1);
                m[s]++;
                j++;
                i = j+1;
            }
            j++;
        }
        i = 0;
        j = i;
        while(j<s2.length()){
            string s = "";
            if(s2[j+1] == ' ' || j+1 == s2.length()){
                s += s2.substr(i, j-i+1);
                m[s]++;
                j++;
                i = j+1;
            }
            j++;
        }
        vector<string>v;
        for(auto i:m){
            if(i.second == 1){
                v.push_back(i.first);
            }
        }
        return v;
    }
};