class Solution {
public:
    int dfs(int index, vector<vector<int>>&stones, vector<bool>&visited, int n) {
        visited[index] = true;
        int result = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i] and (stones[i][0] == stones[index][0] or stones[i][1] == stones[index][1])) {
                result += (dfs(i, stones, visited, n) + 1);
            }
        }
        return result;
    }
    
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(visited[i]) {
                continue;
            }
            ans += dfs(i, stones, visited, n);
        }
        return ans;
    }
};