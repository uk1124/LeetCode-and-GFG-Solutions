class Solution {
public:
    //APPROACH: Using DP (Top Down)
    int lcs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if(i < 0 or j < 0) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans1 = lcs(i-1, j, text1, text2, dp);       //Removing character from 1st string keeping 2nd string same
        
        int ans2 = lcs(i, j-1, text1, text2, dp);       //Removing character from 2nd string keeping 1st string same
        
        int ans3 = lcs(i-1, j-1, text1, text2, dp) + (text1[i]==text2[j]);  //Check if both the characters are equal
        
        return dp[i][j] = max(ans1, max(ans2, ans3));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        
        return lcs(n1-1, n2-1, text1, text2, dp);
    }
};