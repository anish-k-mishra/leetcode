class Solution {
public:
    int maxArea(vector<int>&v){
        stack<int>st;
        int ans = 0;
        int n = v.size();
        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i == n || v[st.top()] >= v[i])){
                int height = v[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top()-1;
                }
                ans = max(ans, width*height);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int>height(matrix[0].size(), 0);
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            int area = maxArea(height);
            ans = max(ans, area);
        }
        return ans;
    }
};