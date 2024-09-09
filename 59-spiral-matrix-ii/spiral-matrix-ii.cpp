class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a = n*n;
        int i = 1;
        vector<vector<int>>v(n, vector<int>(n));
        int tr = 0, br = n-1, tc = 0, bc = n-1;
        while(i<=a){
            for(int col = tc; col<=bc; col++){
                v[tr][col] = i;
                i++;
            }
            tr++;
            for(int row = tr; row<= br; row++){
                v[row][bc] = i;
                i++;
            }
            bc--;
            for(int col = bc; col>=tc; col--){
                v[br][col] = i;
                i++;
            }
            br--;
            for(int row = br; row>=tr; row--){
                v[row][tc] = i;
                i++;
            }
            tc++;
        }
        return v;
    }
};