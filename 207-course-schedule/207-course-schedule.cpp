class Solution {
public:
    /*APPROACH: Similar logic as of 'Detecting cycle in a directed graph'.
                Then, by doing dfs (Could be also done using bfs).*/
    bool isCycle(int node, vector<int> &visited, vector<vector<int>> &adj) {    //Coloring algorithm
        if(visited[node] == 1) {
            return true;
        }
        
        if(visited[node] == 0) {
            visited[node] = 1;
            for(auto it : adj[node]) {
                if(isCycle(it, visited, adj)) {
                    return true;
                }
            }
        }
        visited[node] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        
        for(auto x : prerequisites) {
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0; i<numCourses; i++){
            if(isCycle(i, visited, adj)) {
                return false;
            }
        }
        return true;
    }
};