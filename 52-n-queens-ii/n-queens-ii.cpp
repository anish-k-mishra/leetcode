class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int r = row;
        int c = col;
        //upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = r;
        col = c;
        //coloumn
        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        //lower diagonal
        col = c;
        while(col>=0 && row<n){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& v, int &ans){
        if(col>= n){
            v.push_back(board);
            ans++;
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, v, ans);
                board[row][col] = '.'; //backtrack
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>v;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        int ans = 0;
        solve(0, n, board, v, ans);
        return ans;
    }
};