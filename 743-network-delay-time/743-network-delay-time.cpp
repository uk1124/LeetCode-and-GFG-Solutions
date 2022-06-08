class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1);
        for (auto t : times) {
            g[t[0]].push_back({t[1], t[2]});
        }
    
        vector<int> dist(n+1, INT_MAX);
		vector<bool> vis(n+1, false);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int u, v, w;
        
        while(!pq.empty()) {
            u = pq.top().second; 
            pq.pop();
			// if(vis[u]) {
			// continue;
			// }
			vis[u] = true;
            for (auto to: g[u]) {
                v = to.first, w = to.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};