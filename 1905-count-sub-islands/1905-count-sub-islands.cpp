class Solution {
public:
    //APPROACH: Similar appoach as of No. of islands.
     void count_sub_island(vector<vector<int>>& grid1, int i, int j, vector<vector<int>>& grid2, int &res) {
         int rows = grid1.size();
         int columns = grid1[0].size();
         if(i < 0 or j < 0 or i >= rows or j >= columns or grid2[i][j] != 1) {
             return;
         }
        
         if(grid1[i][j] == 0 and grid2[i][j] == 1) {    // 0 if it's not a sub-island
            res = 0;
         }
         
         grid2[i][j] = 0;
         count_sub_island(grid1, i+1, j, grid2, res);
         count_sub_island(grid1, i, j+1, grid2, res);
         count_sub_island(grid1, i-1, j, grid2, res);
         count_sub_island(grid1, i, j-1, grid2, res);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int columns = grid1[0].size();
        int ans = 0;
        
        if(rows == 0) {
            return 0;
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(grid2[i][j] == 1) {
                    int res = 1;
                    count_sub_island(grid1, i, j, grid2, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};