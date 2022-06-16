class Solution {
public:
    //APPROACH: DFS
    int fill(vector<vector<int>>& g, int i, int j) {
    if (i<0 or j<0 or i>=g.size() or j>=g[i].size() or g[i][j]==1) {
        return 0;
    }
    return (g[i][j] = 1) + fill(g, i+1, j) + fill(g, i, j+1) + fill(g, i-1, j) + fill(g, i, j-1);
}
    
    int closedIsland(vector<vector<int>>& g) {
        int ans = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (i*j == 0 or i == g.size()-1 or j == g[i].size()-1) {
                    fill(g, i, j);
                }
            }
        }
        
        for (int i=0; i<g.size(); i++) {
            for (int j=0; j<g[i].size(); j++) {
                ans += fill(g, i, j) > 0;
            }
        }
        return ans;
    }
};