class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        int n = edges.size();

        for(auto v: edges) {
            for(auto el: v) {
                mp[el]++;
            }
        }
        for(auto it: mp) {
            if(it.second == n) {
                return it.first;
            }
        }
        return -1;
    }
};