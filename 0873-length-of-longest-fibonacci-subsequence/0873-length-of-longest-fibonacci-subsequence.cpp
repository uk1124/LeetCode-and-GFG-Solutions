class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int kVal = arr[j] - arr[i];
                if (index.find(kVal) != index.end() && index[kVal] < i) {
                    dp[i][j] = dp[index[kVal]][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans >= 3 ? ans : 0;
    }
};