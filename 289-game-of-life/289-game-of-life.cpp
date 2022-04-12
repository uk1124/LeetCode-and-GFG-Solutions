class Solution {
public:
    
    int neighbor(vector<vector<int>>& board, int r, int c) {
    if(r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or board[r][c] == 0 ) { // Out of bound cases
        return 0; 
    }                         
    return 1;
}
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> tempBoard = board;  // We will first update values in this temporary matrix
        int liveNeighbors;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                liveNeighbors = neighbor(board, r-1, c-1) + neighbor(board, r-1, c) + neighbor(board, r-1, c+1) + neighbor(board, r, c+1) +  neighbor(board, r+1, c+1) + neighbor(board, r+1, c) + neighbor(board, r+1, c-1) + neighbor(board, r, c-1);
                
                if(board[r][c] == 1) { 
                    tempBoard[r][c] = (liveNeighbors < 2 or liveNeighbors > 3) ? 0 : 1;    // Update temporary matrix, based on the rules in question
            }
                else { 
                    tempBoard[r][c] = (liveNeighbors == 3) ? 1 : 0;
                }
            }
        }
        
        for(int r = 0; r < rows; r++){
            board[r] = tempBoard[r];                    // Copy all tempBoard elements back to board matrix
        }
    }
};