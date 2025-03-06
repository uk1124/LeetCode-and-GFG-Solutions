class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> numbers;
        vector<int> ans(2);

        for(int i=1; i<=n*n; i++) {
            numbers.insert(i);
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<grid[i].size(); j++) {
                int el = grid[i][j];
                if(numbers.find(el) != numbers.end()) {
                     numbers.erase(el);
                }
                else {
                    ans[0] = el;
                }
            }
        }
        ans[1] = *numbers.begin();
        return ans;
    }
};