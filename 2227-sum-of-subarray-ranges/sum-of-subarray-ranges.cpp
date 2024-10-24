class Solution {
public:
    vector<int>findpse(vector<int>& v){
        vector<int> ans;

        stack<int>st;
        for(int i = 0; i<v.size(); i++){
            while(!st.empty() && v[st.top()]>v[i]){
                st.pop();
            }
            if(!st.empty() ){
                ans.push_back(st.top());
                st.push(i);
            }
            else{
                ans.push_back(-1);
                st.push(i);
            }

        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int>findpge(vector<int>& v){
        vector<int> ans;

        stack<int>st;
        for(int i = 0; i<v.size(); i++){
            while(!st.empty() && v[st.top()]<v[i]){
                st.pop();
            }
            if(!st.empty() ){
                ans.push_back(st.top());
                st.push(i);
            }
            else{
                ans.push_back(-1);
                st.push(i);
            }

        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int>findnse(vector<int>& v){
        vector<int> ans;

        stack<int>st;
        for(int i = v.size()-1; i>=0; i--){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(!st.empty() ){
                ans.push_back(st.top());
                st.push(i);
            }
            else{
                ans.push_back(v.size());
                st.push(i);
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int>findnge(vector<int>& v){
        vector<int> ans;

        stack<int>st;
        for(int i = v.size()-1; i>=0; i--){
            while(!st.empty() && v[st.top()]<=v[i]){
                st.pop();
            }
            if(!st.empty() ){
                ans.push_back(st.top());
                st.push(i);
            }
            else{
                ans.push_back(v.size());
                st.push(i);
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>nse = findnse(arr);
        vector<int>pse = findpse(arr);

        long long ans = 0;
        int mod = 1e9+7;

        for(int i = 0; i<arr.size(); i++){
            int left = i-pse[i];
            int right = nse[i]-i;

            ans = (ans+(right*left*1LL*arr[i]));
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>nge = findnge(arr);
        vector<int>pge = findpge(arr);

        long long ans = 0;
        int mod = 1e9+7;

        for(int i = 0; i<arr.size(); i++){
            int left = i-pge[i];
            int right = nge[i]-i;

            ans = (ans+(right*left*1LL*arr[i]));
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long a = sumSubarrayMaxs(nums);
        long long b = sumSubarrayMins(nums);
        return a-b;
    }
};