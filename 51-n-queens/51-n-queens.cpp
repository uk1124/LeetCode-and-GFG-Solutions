class Solution {
public:
    //APPROACH: Using Backtracking.
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int x = row;
        int y = col;
        while(y >= 0) {                         //Check row
            if(board[x][y] == 'Q') {
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        while(x >=0 and y >= 0) {               //Check left diagonal
            if(board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        
        x = row;
        y = col;
        while(x < n and y >= 0) {               //Check right diagonal
            if(board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }
    
    void solve(int col, vector<vector<string>> &ans,  vector<string> &board, int n) {
        if(col == n) {                          // Base Case
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';          //Make decision
                solve(col+1, ans, board, n);    //Next iteration
                
                board[row][col] = '.';          // Backtracking
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        solve(0, ans, board, n);
        return ans;
    }
};