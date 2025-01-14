class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>hash(A.size()+1, 0);
        vector<int>ans;
        int cnt = 0;
        for(int i = 0; i<A.size(); i++){
            hash[A[i]]++;
            if(hash[A[i]] == 2){
                cnt++;
            }
            hash[B[i]]++;
            if(hash[B[i]] == 2){
                cnt++;
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};