/*APPROACH: Using 3D DP.
Use recursive traversal with memoization to count the number of paths from a given position within a specified move limit in a grid.
[The three DP states are the current row index (i), the current column index (j), and the number of moves made (currMove)]
*/
class Solution {
private:
    int mod = 1e9 + 7;

public:
    // Helper function for recursive traversal
    int traverse(int i,int j, int currMove,int maxMove, int m,int n, vector<vector<vector<int>>>& dp) {
        // Base case: If moves exceed the maximum allowed, return 0
        if (currMove > maxMove) {
            return 0;
        }

        // Base case: If out of bounds, return 1 (path found)
        if (i < 0 or j < 0 or i >= m or j >= n) {
            return 1;
        }

        // If the result for the current state is already calculated, return it
        if (dp[i][j][currMove] != -1) {
            return dp[i][j][currMove];
        }

        long long paths = 0;

        // Recursively explore four possible directions
        paths = (paths + traverse(i + 1, j, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i, j + 1, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i - 1, j, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i, j - 1, currMove + 1, maxMove, m, n, dp)) % mod;

        // Save the result in the DP array
        dp[i][j][currMove] = paths;

        // Return the total number of paths from the current state
        return paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Initialize a 3D DP array with -1 (unvisited) values
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        // Start the recursive traversal from the initial position
        return traverse(startRow, startColumn, 0, maxMove, m, n, dp);
    }
};
