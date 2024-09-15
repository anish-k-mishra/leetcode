class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>>v(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i<matrix.size(); i++){
            v[i][0] = matrix[i][0];
            // ans+matrix[i][0];
        }
        for(int i = 0; i<matrix[0].size(); i++){
            v[0][i] = matrix[0][i];
            // ans+=matrix[0][i];
        }

        for(int i = 1; i<matrix.size(); i++){
            for(int j = 1; j<matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    v[i][j] = min(v[i-1][j], min(v[i-1][j-1], v[i][j-1])) + 1;
                    // ans += v[i][j];
                }
                
            }
        }

        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                ans += v[i][j];
            }
        }

        return ans;

    }
};