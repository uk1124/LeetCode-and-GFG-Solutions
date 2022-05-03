class Solution {
public:
    // APPROACH: BFS and find the shortest path
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();                    // == No. of rows == No. of columns
        int ans = 0;
        vector<vector<int>> d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector(n,false));
        
        if(grid[0][0] or grid[n-1][n-1]) {
            return -1;
        }
        
        q.push(make_pair(0,0));
        visited[0][0] = true;
        
        while(!q.empty()) {
            int steps = q.size();
            ans++;
            
            for(int i=0; i<steps; ++i) {            // Directions
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 and y == n-1) {
                    return ans;
                }
                
                for(int j=0; j<8; ++j) {
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1>=0 and x1<n and y1>=0 and y1<n) {
                        if(!visited[x1][y1] and !grid[x1][y1]) {
                            q.push({x1,y1});
                            visited[x1][y1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};