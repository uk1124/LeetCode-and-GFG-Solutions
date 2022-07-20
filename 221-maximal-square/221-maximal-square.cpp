class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_len = 0;
        
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(matrix[r][c] == '1') {
                    dp[r+1][c+1] = min(dp[r][c], min(dp[r+1][c], dp[r][c+1])) + 1;
                    max_len = max(max_len, dp[r+1][c+1]);
                }
            }
        }
        return max_len*max_len;
    }
};