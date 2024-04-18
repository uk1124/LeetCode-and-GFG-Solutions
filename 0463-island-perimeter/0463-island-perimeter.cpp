class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) { 
            for(int j = 0; j < grid[i].size(); j++) { 
                if(grid[i][j] == 1) { // If current cell represents land
                    perimeter += 4;   // Increment perimeter by 4
                    
                    // Check if there is land in the cell below
                    if(i < grid.size()-1 and grid[i+1][j] == 1) {
                        perimeter -= 2; // Decrement perimeter by 2 (due to shared edge)
                    }
                    // Check if there is land in the cell to the right
                    if(j < grid[i].size()-1 and grid[i][j+1] == 1) {
                        perimeter -= 2; // Decrement perimeter by 2 (due to shared edge)
                    }
                }
            }
        }
        return perimeter;
    }
};
