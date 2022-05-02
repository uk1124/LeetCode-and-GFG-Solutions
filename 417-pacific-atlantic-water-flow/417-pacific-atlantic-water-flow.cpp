class Solution {
public:
    int m, n;          //Denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool>> atlantic, pacific;
	vector<vector<int>> ans;    
    
     void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j){        
        if(visited[i][j]) {
            return;
        }
        visited[i][j] = true;
		
        if(atlantic[i][j] && pacific[i][j]) {   //If cell reachable from both the oceans, insert into final answer vector
            ans.push_back(vector<int>{i, j});
        }
         
		//Dfs from current cell only if height of next cell is greater
         if(i+1 <  m and matrix[i+1][j] >= matrix[i][j]) {         //Downwards
             dfs(matrix, visited, i+1, j);
         }
         
         if(i-1 >= 0 and matrix[i-1][j] >= matrix[i][j]) {         //Upwards 
             dfs(matrix, visited, i-1, j);
         }
         if(j+1 <  n and matrix[i][j+1] >= matrix[i][j]) {         //Right  
             dfs(matrix, visited, i, j+1);
         }
         if(j-1 >= 0 and matrix[i][j-1] >= matrix[i][j]) {         //Left  
             dfs(matrix, visited, i, j-1);
         }
    }
    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& matrix) {
        if(!matrix.size()) {
            return ans;
        }
        m = matrix.size(), n = matrix[0].size();
        atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));
		
        for(int i=0; i<m; i++) {    // perform dfs from all edge cells (ocean-connected cells)
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n-1);
        }
        for(int i=0; i<n; i++) {
            dfs(matrix, pacific, 0, i);
            dfs(matrix, atlantic, m-1, i); 
        }
        return ans;
    }
};