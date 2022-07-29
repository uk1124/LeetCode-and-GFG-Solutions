class Solution {
public:
    /*APPROACH: Using 2D DP.
    We memoise the previously computed results for dice i and and target.
    Since dp is initialized with zeros, we store there ans to check if the result has been pre-computed. */
    int m = 1000000007;
    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        if(n == 0 or target < 0) {
            return n == target;
        }
        
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        
        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans = (ans + solve(n-1, k, target-i, dp)) % m;
        }
        return dp[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};