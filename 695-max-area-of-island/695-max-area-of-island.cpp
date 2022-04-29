class Solution {
public:
    // DFS and calculate the max area out of all the islands
    int dfs_cal(vector<vector<int>>& grid, int i, int j) {
       if(i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size() and grid[i][j] == 1) {
           grid[i][j] = 0;
           return 1 + dfs_cal(grid, i+1, j) + dfs_cal(grid, i, j+1) + dfs_cal(grid, i-1, j) + dfs_cal(grid, i, j-1);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, dfs_cal(grid, i, j));
                }
            }
        }
        return ans;
    }
};