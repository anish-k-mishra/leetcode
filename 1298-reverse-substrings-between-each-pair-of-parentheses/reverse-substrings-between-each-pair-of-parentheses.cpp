class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        vector<int>v(s.length(),0);
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int a = st.top();
                v[i] = a;
                v[a] = i;
                st.pop();
            }
        }
        int dir = 1;
        int i = 0;
        string ans = "";
        while(i<s.length()){
            if(s[i] == '(' || s[i] == ')'){
                dir = dir*(-1);
                i = v[i] + dir;
                continue;
            }
            else{
                ans += s[i];
                i+=dir;
            }
        }
        return ans;
    }
};