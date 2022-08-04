class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            ans++;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1 or dp[i+1][j-1]) {
                        dp[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;                      
    }
};