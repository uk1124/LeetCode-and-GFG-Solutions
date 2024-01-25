class Solution {
public:
//APPROACH: Using DP (Top Down Solution)
    int lcs(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 or j < 0) {
            return 0;
        }

        // If the result is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Three possible cases:
        // 1. Skip character from text1
        int ans1 = lcs(text1, text2, i - 1, j, dp);
        // 2. Skip character from text2
        int ans2 = lcs(text1, text2, i, j - 1, dp);
        // 3. Match current characters and go diagonally
        int ans3 = lcs(text1, text2, i - 1, j - 1, dp) + (text1[i] == text2[j]);

        // Store and return the maximum of these three cases
        return dp[i][j] = max(ans1, max(ans2, ans3));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        // Initialize a DP array to memorize computed results
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        // Call the recursive function with initial indices
        return lcs(text1, text2, n1 - 1, n2 - 1, dp);
    }

/* ITERATIVE SOLUTION
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        // Initialize a DP array to store results of subproblems
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Iterate through the DP array
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                // If characters match, take diagonal value + 1
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                else {
                    // If characters don't match, take the maximum of the above and left values
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // The result is stored in the bottom-right cell of the DP array
        return dp[n1][n2];
    }
*/
};

