class Solution {
public:
    int solveMem(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i >= j) {
            return (i==j);
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = solveMem(i+1, j, s, dp);
        ans = max(ans, solveMem(i, j-1, s, dp));
        if(s[i] == s[j]) {
            ans = max(ans, solveMem(i+1, j-1, s, dp) + 2);
        }
        
        return dp[i][j] = ans;
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solveMem(0, n-1, s, dp);
    }
};