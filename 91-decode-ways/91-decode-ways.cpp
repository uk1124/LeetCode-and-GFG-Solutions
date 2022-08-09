class Solution {
public:
    /*APPROACH: Using DP.
    For a character s[i], we have 2 ways to decode:
    • Single digit: Require s[i] != '0' (decoded to 1 to 9)
    • Two digits: Require i + 1 < len(s) and (s[i] == 1 (decoded to 10 to 19) or s[i] == 2 and s[i+1] <= '6')
    (decoded to 20 to 26). */
    int solve(string &s, int i, vector<int> &dp) {
        if(i == s.size()) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = 0;
        if (s[i] != '0') {                                                      // Single digit 
            ans += solve(s, i+1, dp);
        }
        if(i+1 < s.size() and (s[i] == '1' or s[i] == '2' and s[i+1] <= '6')) { // Two digits 
            ans += solve(s, i+2, dp);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        
        return solve(s, 0, dp);
    }
};