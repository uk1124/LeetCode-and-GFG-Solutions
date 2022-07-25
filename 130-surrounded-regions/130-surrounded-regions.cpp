class Solution {
public:
    /*APPROACH:
    1. Move over the boundary of board, and find 'O's 
    2. Every time we find an 'O', perform DFS from it's position
    3. In DFS convert all 'O' to '#' (So that we can differentiate which 'O' can be flipped and cannot be)   
    4. After all DFSs have been performed, board contains three elements, '#', 'O' and 'X'
    5. 'O' are left over elements which are not connected to any boundary 'O', so flip them to 'X'
    6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'. */
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i < 0 or j < 0 or i >= m or j >= n or board[i][j] != 'O') {
            return;
        }
        board[i][j] = '$';
        
        dfs(board, i+1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j-1, m, n);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m == 0) {
            return;
        }
        
        for(int i=0; i<m; i++) {            //Moving over first and last column   
            if(board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
            if(board[i][n-1] == 'O') {
                dfs(board, i, n-1, m, n);
            }
        }
        
        for(int j=0; j<n; j++) {            //Moving over first and last row   
            if(board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }
            if(board[m-1][j] == 'O') {
                dfs(board, m-1, j, m, n);
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};