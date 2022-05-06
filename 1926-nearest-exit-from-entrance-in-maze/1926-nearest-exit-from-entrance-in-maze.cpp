class Solution {
public:
    //APPROACH: BFS to find the nearest exit.
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        int ans = 1;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';                                     // Mark the entrance as visited
            
        while(!q.empty()) {
            int size = q.size(); 
            
            for(int i=0; i<size; i++) {
                auto it = q.front();
                q.pop();
                
                for(int j=0; j<4; j++) {
                    int x = it.first + dirs[j][0];
                    int y = it.second + dirs[j][1];
                    
                    if(x < 0 or y < 0 or x >= m or y >= n or maze[x][y] == '+') { // Invalid cell
                        continue;
                    }
                    if(x == 0 or y == 0 or x == m-1 or y == n-1) {                // Found the exit
                        return ans;
                    }
                    maze[x][y] = '+';                                             // Mark the visited cell
                    q.push({x,y});
                }
            }
            ans++;
        }
        return -1;
    }
};