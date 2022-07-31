class Solution {
public:
    /*APPROACH: Using BFS.
    -> Use BFS to compute distance from node1 to every node and from node2 to every node individually.
    -> Loop from 0 to n nodes and return the first node with smallest value of max(v1[node], v2[node]) */
    void bfs(int node, vector<int> &dist, vector<int> &edges) {
        queue<int> q;
        dist[node] = 0;
        q.push(node);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(edges[curr] != -1 and dist[edges[curr]] == INT_MAX) {
                q.push(edges[curr]);
                dist[edges[curr]] = dist[curr] + 1;
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> v1(n, INT_MAX), v2(n, INT_MAX);
        
        bfs(node1, v1, edges);
        bfs(node2, v2, edges);
    
        int ans = INT_MAX, indx = -1;
        for(int i=0; i<n; i++) {
            if(v1[i] == INT_MAX or v2[i] == INT_MAX) {
                continue;
            }
            if(ans > max(v1[i], v2[i])) {
                indx = i;
                ans = max(v1[i], v2[i]);  
            }
        }
        return indx;
    }
};