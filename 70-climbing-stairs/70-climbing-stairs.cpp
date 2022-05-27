class Solution {
public:
    /*Top-Down Approach (Memoization):
    int fun(int n, vector<int> &dp) {
        if(n <= 2) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = fun(n-1, dp) + fun(n-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return fun(n, dp);
    }
    */
    
    //Bottom-Up Approach (Tabulation):
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};