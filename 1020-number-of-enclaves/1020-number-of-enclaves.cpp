class Solution {
public:
    //APPROACH: DFS and flood-fill the land (change 1 to 0) from the boundary of the grid. Then, we count the remaining land.
    int dfs_check(vector<vector<int>>& grid, int i, int j, int rows, int columns) {
        if(i < 0 or j < 0 or i >= rows or j >= columns or grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;
        
        return (1 + dfs_check(grid, i-1, j, rows, columns) + dfs_check(grid, i+1, j, rows, columns) + dfs_check(grid,i, j-1, rows, columns) + dfs_check(grid, i, j+1, rows, columns));
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int total_ones = 0, closed_ones = 0;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(grid[i][j] == 1) {
                    total_ones++;
                }
            }
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if((i == 0 or j == 0 or i == rows-1 or j == columns-1) and (grid[i][j] == 1)) {
                    closed_ones += dfs_check(grid, i, j, rows, columns);
                }
            }
        }
        return (total_ones - closed_ones);
    }
};