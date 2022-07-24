class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        multiset<vector<int>> s;
        int n = grid.size();
        int count = 0;
        
        for(int i=0; i<n; i++) {
            vector<int> v;
            for(int j=0; j<n; j++) {
                v.push_back(grid[j][i]);
            }
            s.insert(v);
        }
        
        for(int i=0; i<n; i++) {
            vector<int> v;
            for(int j=0; j<n; j++) {
                v.push_back(grid[i][j]);
            }
            count += s.count(v);
        }
        return count;
    }
};