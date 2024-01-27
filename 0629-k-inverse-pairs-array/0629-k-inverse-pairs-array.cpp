class Solution {
public:
    int MOD = 1e9+7;

    int kInversePairs(int n, int k) {
        // Base case: if k is negative, there are no arrays
        if (k < 0) {
            return 0;
        }
        // Base case: if k is zero, there is exactly one array (sorted)
        else if (k == 0) {
            return 1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Initialize the base case: there is one way to have 0 inverse pairs for any array
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill in the dp table using the recurrence relation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 0; p <= min(j, i - 1); p++) {
                    // Update dp[i][j] by considering the last element in the array
                    // and the number of inverse pairs it can form with previous elements
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};
