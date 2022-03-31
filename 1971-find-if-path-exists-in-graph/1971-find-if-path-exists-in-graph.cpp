class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int source, int destination) {
        if(source == destination) {
            return true;
        }
        if(visited[source]) {
            return false;
        }
        visited[source] = 1;
        
        for(int i=0; i<adj[source].size(); i++) {
            if(dfs(adj, visited, adj[source][i], destination)) {
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n, 0);
        
        return dfs(adj, visited, source, destination);
    }
};