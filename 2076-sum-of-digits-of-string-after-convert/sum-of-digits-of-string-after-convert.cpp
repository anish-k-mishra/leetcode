class Solution {
public:
    int getLucky(string s, int k) {
        string n = "";
        for(int i = 0; i<s.length(); i++){
            n += to_string(s[i] - 'a' + 1);
        }

        // int a = stoll(n);
        while(k--){
            int t = 0;
            for(char c: n){
                t += c-'0';
            }
            n = to_string(t);
        }
        return stoi(n);
    }
};