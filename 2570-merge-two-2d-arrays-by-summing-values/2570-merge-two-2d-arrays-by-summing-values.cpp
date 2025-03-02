class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> sum;

        for(auto v: nums1) {
            sum[v[0]] = v[1];
        }

        for(auto v: nums2) {
            sum[v[0]] += v[1];
        }

        vector<vector<int>> ans;
        for(auto mp: sum) {
            ans.push_back({mp.first, mp.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};