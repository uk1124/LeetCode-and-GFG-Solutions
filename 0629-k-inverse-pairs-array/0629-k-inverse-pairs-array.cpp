class Solution {
public:
//APPROACH: Using DP (MEMOIZATION METHOD)
    int MOD = 1e9 + 7;

    int dp_(int n, int k, vector<vector<int>>& dp) {
        // Base cases
        if (k < 0) {
            return 0;
        } 
        else if (k == 0) {
            return 1;
        }

        if (dp[n][k] != -1) {
            return dp[n][k];
        }

        int count = 0;
        // Iterate over possible values of p to calculate the count
        for (int p = 0; p <= min(k, n - 1); p++) {
            // Recursively calculate the count for reduced parameters and sum them up
            count = (count + dp_(n - 1, k - p, dp)) % MOD;
        }

        // Store the calculated count in the memoization table
        dp[n][k] = count;
        return count;
    }

    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return dp_(n, k, dp);
    }

/*(TABULATION METHOD)

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
*/
};
