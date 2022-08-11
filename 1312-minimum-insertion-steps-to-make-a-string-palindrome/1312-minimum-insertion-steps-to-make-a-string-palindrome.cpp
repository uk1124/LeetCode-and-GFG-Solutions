class Solution {
public:
    /*APPROACH: USing DP (Top Down)
    Trick: Just find the size of Longest Palindromic Subsequence and subtract it from the original string size*/
    int LPS(int i, int j, string &s, vector<vector<int>> &dp) {    
        if(i >= j) {
            return (i==j);
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = LPS(i+1, j, s, dp);
        ans = max(ans, LPS(i, j-1, s, dp));
        if(s[i] == s[j]) {
            ans = max(ans, LPS(i+1, j-1, s, dp) + 2);
        }
        return dp[i][j] = ans;
    }
    
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        int sizeLPS =  LPS(0, n-1, s, dp);
        
        return n - sizeLPS;
    }
};