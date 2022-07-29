class Solution {
public:
    int solve(vector<int> &slices, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n/3 + 1, 0));
        //int ans = INT_MIN;
        
        // for (int i=0; i<n+1; ++i) {
        //     dp[i][0] = 0;
        // }
        for (int i=2; i<n+1; i++) {
            for (int j=1; j< n/3 + 1; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i-2][j-1] + slices[i-2]);
            }
        }
        
        return dp[n][n/3];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> v1, v2;
        for(int i=0; i<n; i++) {
            if(i != 0) {
                v1.push_back(slices[i]);
            }
            if(i != n-1) {
                v2.push_back(slices[i]);
            }
        }
        return max(solve(v1, n), solve(v2, n));
    }
};