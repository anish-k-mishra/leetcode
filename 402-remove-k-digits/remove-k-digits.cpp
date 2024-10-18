class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length()){
            return "0";
        }
        stack<char>st;
        st.push(num[0]);
        for(int i = 1; i<num.length(); i++){
            while(!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0"; 
        }
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        while(res.length() != 0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if(res.length() == 0){
            return "0";
        }
        return res;
    }
};