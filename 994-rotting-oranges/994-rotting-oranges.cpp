class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;                        //Initially all rotten oranges started at 0.
        vector<int> dir = {-1, 0 ,1, 0, -1};

        queue<pair<int,int>> q;
        int fresh = 0;                       //To keep track of all fresh oranges left
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto p = q.front();
                q.pop();
                for(int i=0; i<4; i++) {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    if(r >=0 and r < m and c >= 0 and c < n and grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;             //Decrement by 1 for each fresh orange that now is rotten
                    }       
                }
            }
            ans++;                           //Incremented after each minute passes
        }
        
        if(fresh > 0) {                      //If fresh>0 that means there are fresh oranges left
            return -1;
        }
        if(ans == -1) {                      //We initialised with -1, so if there were no oranges it'd take 0 mins.
            return 0; 
        }
        
        return ans; 
    }
};