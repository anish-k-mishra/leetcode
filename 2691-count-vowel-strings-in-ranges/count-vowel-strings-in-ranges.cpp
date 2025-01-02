class Solution {
public:
    bool isVowel(char a, char b) {
        bool isa = false;
        bool isb = false;
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            isa = true;
        }
        if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') {
            isb = true;
        }
        return isa && isb;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre(words.size());
        int cnt = 0;

        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0], words[i][words[i].length() - 1])) {
                cnt++;
            }
            pre[i] = cnt;
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                ans.push_back(pre[queries[i][1]]);
            } 
            else {
                ans.push_back(pre[queries[i][1]] - pre[queries[i][0] - 1]);
            }
        }

        return ans;
    }
};
