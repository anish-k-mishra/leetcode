class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows*cols;
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans;
        ans.push_back({rStart, cStart});
        int count = 1;
        int ind = 0;
        int step = 1;
        while(count<n){
            for(int i = 0; i<2; i++){
                for(int j = 0; j<step; j++){
                    rStart += dir[ind%4][0];
                    cStart += dir[ind%4][1];
                    if(rStart>=0 && rStart<rows && cStart >= 0 && cStart<cols){
                        ans.push_back({rStart, cStart});
                        count++;
                    }
                }
                ind++;
            }
            step++;
        }
        return ans;
    }
};