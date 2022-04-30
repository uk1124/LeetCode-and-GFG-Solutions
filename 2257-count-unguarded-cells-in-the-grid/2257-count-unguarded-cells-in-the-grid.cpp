class Solution {
public:
    /*APPROACH: DFS and mark all the unguarded cells upward, downward, right & left of a guarded cell until guarded or walled cell is found.
    Here,   g -> cell with a guard
            w -> cell with a wall
            d -> guarded cells
            u -> unguarded cells
    */
    void dfs_mark(vector<vector<char>> &grid, int r, int c, int m, int n) {
        for(int j=c+1; j<n; j++) {
            if (grid[r][j] == 'w' or grid[r][j] == 'g') {
                break;
            }
            grid[r][j] = 'd';
        }
        
        for(int j=c-1; j>=0; j--) {
            if (grid[r][j] == 'w' or grid[r][j] == 'g') {
                break;
            }
            grid[r][j] = 'd';
        }
        
        for(int i=r+1; i<m; i++) {
            if (grid[i][c] == 'w' or grid[i][c] == 'g') {
                break;
            }
            grid[i][c] = 'd';
        }
		
        for(int i=r-1; i>=0; i--) {
            if (grid[i][c] == 'w' or grid[i][c] == 'g') {
                break;
            }
            grid[i][c] = 'd';
        }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid (m , vector<char>(n, 'u'));
        int ans = 0;
        
        for(int i=0; i<guards.size(); i++) {
            grid[guards[i][0]] [guards[i][1]] = 'g';
        } 
        
        for(int i=0; i<walls.size(); i++) {
            grid[walls[i][0]] [walls[i][1]] = 'w';
        }
        
        for(int i=0; i<guards.size(); i++) {
            dfs_mark(grid, guards[i][0], guards[i][1], m, n);
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'u') {
                    ans++;
                }
            }
        }
        return ans;
    }
};