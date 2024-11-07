class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<int, int>m;
        while(r<fruits.size()){
            m[fruits[r]]++;
            while(m.size()>2){
                m[fruits[l]]--;
                if (m[fruits[l]] == 0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            int len = r-l+1;
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};