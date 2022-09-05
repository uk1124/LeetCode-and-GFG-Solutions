class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int,int> maxmap;         //Key : element in arr; value : longest length for AS based on diff
        for(int i = 0; i < arr.size(); i++){
            maxmap[arr[i]] = maxmap[arr[i] - difference] + 1;
            ans = max(ans, maxmap[arr[i]]);
        }
        return ans;
    }
};