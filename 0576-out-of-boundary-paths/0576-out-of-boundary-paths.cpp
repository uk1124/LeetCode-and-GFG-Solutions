class Solution {
private:
    int mod = 1e9 + 7;
public:
    int traverse(int i,int j, int currMove,int maxMove, int m,int n, vector<vector<vector<int>>>& dp) {
        if (currMove > maxMove) {
            return 0;
        }

        if (i < 0 or j < 0 or i >= m or j >= n) {
            return 1;
        }

        if (dp[i][j][currMove] != -1) {
            return dp[i][j][currMove];
        }

        long long paths = 0;
        paths = (paths + traverse(i + 1, j, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i, j + 1, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i - 1, j, currMove + 1, maxMove, m, n, dp)) % mod;
        paths = (paths + traverse(i, j - 1, currMove + 1, maxMove, m, n, dp)) % mod;

        dp[i][j][currMove] = paths;
        return paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return traverse(startRow, startColumn, 0, maxMove, m, n, dp);
    }
};