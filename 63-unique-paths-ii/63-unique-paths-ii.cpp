class Solution {
public:
    
     int solve(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
         int m = obstacleGrid.size();
         int n = obstacleGrid[0].size();
        
         if(i < 0 or j < 0 or i >= m or j >= n) {
             return 0;
         }
         if(obstacleGrid[i][j] == 1) {
             return dp[i][j] = 0;
         }
         if(i == m-1 and j == n-1) {                 // We got a possible path
             return 1;
         }
         if(dp[i][j] != -1) {
             return dp[i][j];
         }
         else {
             return dp[i][j] = solve(i, j+1, obstacleGrid, dp) + solve(i+1, j, obstacleGrid, dp);
         }
     }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(0, 0, obstacleGrid, dp);
    }
};