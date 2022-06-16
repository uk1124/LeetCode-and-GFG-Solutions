class Solution {
public:
    /*APPROACH: Using DP (Bottom Up)
    Notable point: In even number the count of '1's is always the same as its half number, on the other hand, it's
    plus one to the odds' half number. */
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i/2] + (i % 2);
        }
        return dp;
    }
};