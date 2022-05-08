class Solution {
public:
    /*APPROACH: Count the number of connected networks. To connect two unconneccted networks, we need to set one
    cable.
    The number of operations we need = the number of connected networks - 1 */
    void dfs(vector<vector<int>>& adj, vector<bool> &visited, int node) {
        visited[node] = true;
        for(int i: adj[node]) {
            if(!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {      // If we do not have enough cables, return -1
            return -1;
        }
        
        vector<vector<int>> adj(n);
        for(auto v: connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]) {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};