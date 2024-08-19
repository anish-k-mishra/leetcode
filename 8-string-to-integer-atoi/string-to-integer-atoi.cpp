class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.length() && s[i] == ' ') {
            i++;
        }
        
        if(i == s.length()) return 0;  
        
        bool negative = false;
        if(s[i] == '-' || s[i] == '+') {
            negative = (s[i] == '-');
            i++;
        }
        
        long long result = 0;
        while(i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if(negative && -result < INT_MIN) return INT_MIN;
            if(!negative && result > INT_MAX) return INT_MAX;
            i++;
        }
        
        return negative ? -result : result;
    }
};
