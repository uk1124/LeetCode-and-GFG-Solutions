class Solution {
public:
    int dp[605][105][105];
    int solve(int indx, int m, int n, vector<string> &strs) {
        if(indx == strs.size()) {
            return 0;
        }
        if(dp[indx][m][n] != -1) {
            return dp[indx][m][n];
        }
        
        string s = strs[indx];
        int zeroes = count(s.begin(), s.end(), '0');
        int ones = count(s.begin(), s.end(), '1');
            
        dp[indx][m][n] = solve(indx + 1, m, n, strs);
        
        if(m - zeroes >= 0 and n - ones >= 0) {
            dp[indx][m][n] = max(dp[indx][m][n], 1 + solve(indx+1, m-zeroes, n-ones, strs));
        }
        return dp[indx][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, m, n, strs);
    }
};