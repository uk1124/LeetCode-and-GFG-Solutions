class Solution {
public:
    int solveMem(int n, vector<int> &dp) {
        if(n == 0 or n == 1) {
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