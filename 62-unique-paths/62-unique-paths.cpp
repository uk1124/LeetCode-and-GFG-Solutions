class Solution {
public:
    /*APPROACH: Using DP. 
    We consider both of the moves (Down and Right).
    If the series of moves leads to a cell outside the grid's boundary, we can return 0 denoting no valid path was
    found.
    If the series of moves leads us to the target cell (m-1, n-1), we return 1 denoting we found a valid unique path
    from start to end.
    */
    int solve(int i, int j, vector<vector<int>> &dp) {
        int m = dp.size() - 1;
        int n = dp[0].size() - 1;
        
        if(i > m or j > n) {
            return 0;
        }
        if(i == m-1 and j == n-1) {                 // We got a possible path
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        else {
            return dp[i][j] = solve(i, j+1, dp) + solve(i+1, j, dp);
        }
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(0, 0, dp);
    }
};