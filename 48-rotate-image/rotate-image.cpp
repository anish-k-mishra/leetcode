class Solution {
public:
    void reverse(vector<int>& v){
        if(v.size() == 0 || v.size() == 1){
            return;
        }
        int s = 0;
        int e = v.size()-1;
        while(s<=e){
            swap(v[s], v[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v = matrix;
        matrix = {};
        for(int i = 0; i<v.size(); i++){
            vector<int>temp;
            for(int j = 0; j<v[0].size(); j++){
                temp.push_back(v[j][i]);
            }
            matrix.push_back(temp);
        }
        for(int i = 0; i<matrix.size(); i++){
            reverse(matrix[i]);
        }
        
    }
};