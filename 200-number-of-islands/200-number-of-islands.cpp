class Solution {
public:
    //APPROACH: DFS and mark the area as '2' wherever we found land
    void mark_island(vector<vector<char>>& grid, int i, int j, int rows, int columns) {
        if(i < 0 or j < 0 or i >= rows or j >= columns or grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '2';
        mark_island(grid, i+1, j, rows, columns);
        mark_island(grid, i, j+1, rows, columns);
        mark_island(grid, i-1, j, rows, columns);
        mark_island(grid, i, j-1, rows, columns);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        
        if(rows == '0') {
            return 0;
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(grid[i][j] == '1') {
                    mark_island(grid, i, j, rows, columns);
                    ans++;
                }
            }
        }
        return ans;
    }
};