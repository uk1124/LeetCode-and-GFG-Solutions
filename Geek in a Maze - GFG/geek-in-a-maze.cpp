// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
	    vector<vector<bool>> visited;
	    for(int i = 0; i < n; i++) {
	        vector<bool> vec (m , false);
	        visited.push_back(vec);
	    }
	    queue<pair<pair<int, int>, pair<int, int>>> q;
	    if(mat[r][c] ==  '#'){
	        return 0;
	    }
	    
	    q.push({{r,c}, {0, 0}});
	    visited[r][c] = true;
	    int count = 1;
	    while(!q.empty()) {
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int up = q.front().second.first;
	        int down = q.front().second.second;
	        q.pop();
	        
	        if(y - 1 >= 0 and mat[x][y - 1] == '.' and visited[x][y - 1] == false) {
	            q.push({{x, y - 1}, {up, down}});
	            visited[x][y - 1] = true;
	            count++;
	        }
	        if(y + 1 < m and mat[x][y + 1] == '.' and visited[x][y + 1] == false) {
	            q.push({{x, y + 1}, {up, down}});
	            visited[x][y + 1] = true;
	            count++;
	        }
	        if(x - 1 >= 0 and mat[x - 1][y] == '.' and visited[x - 1][y] == false and up != u) {
	            q.push({{x - 1, y}, {up + 1, down}});
	            visited[x - 1][y] = true;
	            count++;
	        }
	        if(x + 1 < n and mat[x  + 1][y] == '.' and visited[x + 1][y] == false and down != d) {
	            q.push({{x + 1, y}, {up, down + 1}});
	            visited[x + 1][y] = true;
	            count++;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends