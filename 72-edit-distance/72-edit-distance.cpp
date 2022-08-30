class Solution {
public:
    int dp[505][505];
    int solve(int i, int j, string &word1, string &word2) {
        if(i < 0) {
            return j+1;
        }
        if(j < 0) {
            return i+1;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(word1[i] == word2[j]) {
            dp[i][j] = solve(i-1, j-1, word1, word2);
            return dp[i][j];
        }
        else {
            dp[i][j] = 1 + min(solve(i-1,j-1,word1,word2), min(solve(i,j-1,word1,word2), solve(i-1,j,word1,word2)));
            return dp[i][j];
        }
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n1-1, n2-1, word1, word2);
    }
};