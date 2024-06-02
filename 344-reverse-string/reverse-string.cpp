class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        // int j = s.size()-1;
        while(i<s.size()-1-i){
            swap(s[i], s[s.size()-1-i]);
            i++;
        }
    }
};