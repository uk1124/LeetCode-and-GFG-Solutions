class Solution {
public:
    //APPROACH: Using Topological sort
     bool isCycle(int i, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans) {    //Coloring algorithm
         vis[i] = 1;
         
         for(int x : adj[i]) {
            if(vis[x] == 0) {
                if(isCycle(x, vis, adj, ans)) {
                    return true; 
                }
            }
            else if(vis[x] == 1) {
                return true; 
            }
         }
         
         vis[i] = 2;
         ans.push_back(i);
         return false;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> ans;
        stack<int> st;
        
        for(auto x: prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i=0; i<numCourses; i++) {
            if(vis[i] == 2) { 
                continue;
            }
            if(isCycle(i, vis, adj, ans)) {
                return {}; 
            }
        }
        return ans;
    }
};