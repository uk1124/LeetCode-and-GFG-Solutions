class Solution {
public:
    /*APPROACH: Similar to Cycle Detection In a Directed Graph.
    Unvisited nodes are marked as 0.
    Visited but unsafe nodes are marked as 1.
    Visited but safe nodes are marked as 2.
    */
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node) {
        color[node] = 1;
        
        for(auto curr: graph[node]) {
            if(color[curr] == 0 and dfs(graph, color, curr) or (color[curr] == 1)) {
                return true;
            }
        }
        color[node] = 2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n), ans;
        
        for(int i=0; i<n; i++) {
            if(color[i] == 2 or !dfs(graph, color, i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};