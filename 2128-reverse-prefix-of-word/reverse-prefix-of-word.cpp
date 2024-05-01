class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        queue<char> q;
        bool flag = false;
        int pos;
        for(int i = 0; i<word.length(); i++){
            if(word[i] == ch){
                flag = true;
                pos = i;
                break;
            }
        }
        string ans;
        if(flag == true){

            for(int i = 0; i<=pos; i++){
                st.push(word[i]);
            }
            for(int i = pos+1; i<word.length(); i++){
                q.push(word[i]);
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            while(!q.empty()){
                ans.push_back(q.front());
                q.pop();
            }
        }
        else{
            ans = word;
        }
        return ans;
    }
};