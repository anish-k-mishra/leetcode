class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;

        if (expression[i] == '&') {
            i++; // Move past '&'
            return gand(expression, i);
        } else if (expression[i] == '!') {
            i++; // Move past '!'
            return noti(expression, i);
        } else {
            i++; // Move past '|'
            return ory(expression, i);
        }
    }

private:
    bool noti(string& s, int& i) {
        
        if (s[i] == '(') i++; // Skip '('
        bool res = false;
        while (i < s.size() && s[i] != ')') {
            if (s[i] == 't') {
                res = false;
                i++;
                break;
            } else if (s[i] == 'f') {
                res = true;
                i++;
                break;
            } else if (s[i] == '&') {
                i++; // Skip '&'
                res = !gand(s, i);
            } else if (s[i] == '|') {
                i++; // Skip '|'
                res = !ory(s, i);
            } else if (s[i] == '!') {
                i++; // Skip '!'
                res = !noti(s, i);
            } else if (s[i] == ',') {
                i++; // Skip ','
            } else {
                i++;
            }
        }
        if (s[i] == ')') i++; // Skip ')'
        return res;
    }

    bool ory(string& s, int& i) {
        
        stack<bool> st;
        if (s[i] == '(') i++; // Skip '('
        while (i < s.size() && s[i] != ')') {
            if (s[i] == 't') {
                st.push(true);
                i++;
            } else if (s[i] == 'f') {
                st.push(false);
                i++;
            } else if (s[i] == '&') {
                i++; // Skip '&'
                st.push(gand(s, i));
            } else if (s[i] == '|') {
                i++; // Skip '|'
                st.push(ory(s, i));
            } else if (s[i] == '!') {
                i++; // Skip '!'
                st.push(noti(s, i));
            } else if (s[i] == ',') {
                i++; // Skip ','
            } else {
                i++;
            }
        }
        if (s[i] == ')') i++; // Skip ')'
        bool l = false;
        while (!st.empty()) {
            l |= st.top();
            st.pop();
        }
        return l;
    }

    bool gand(string& s, int& i) {
        
        stack<bool> st;
        if (s[i] == '(') i++; // Skip '('
        while (i < s.size() && s[i] != ')') {
            if (s[i] == 't') {
                st.push(true);
                i++;
            } else if (s[i] == 'f') {
                st.push(false);
                i++;
            } else if (s[i] == '&') {
                i++; // Skip '&'
                st.push(gand(s, i));
            } else if (s[i] == '|') {
                i++; // Skip '|'
                st.push(ory(s, i));
            } else if (s[i] == '!') {
                i++; // Skip '!'
                st.push(noti(s, i));
            } else if (s[i] == ',') {
                i++; // Skip ','
            } else {
                i++;
            }
        }
        if (s[i] == ')') i++; // Skip ')'
        bool l = true;
        while (!st.empty()) {
            l &= st.top();
            st.pop();
        }
        return l;
    }
};
