class Solution {
public:
    /*APPROACH: Using DP (Top Down)
    In general (Catalan Numbers):
    f[n] = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-2]*f[1] + f[n-1]*f[0].
    */
    int solveMem(int n, vector<int> &dp) {
        if(n == 0 or n == 1) {              //Base Case
            return 1;
        }
        int curr = n;
        if(dp[curr] != -1) {
            return dp[curr];
        }
        
        int catalan = 0;
        for(int i=0; i<n; i++) {
            catalan += solveMem(i, dp) * solveMem(n-i-1, dp);
        }
        return dp[curr] = catalan;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};