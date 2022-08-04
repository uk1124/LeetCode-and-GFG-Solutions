class Solution {
public:
    /*APPROACH:
    State variable-
        The start index(i) and end index(j) of a substring can identify a state, which influences our decision.
        So the state variable is state(i, j) indicates whether s[i, j] inclusive is palindromic
    Goal state-
        max(j - i + 1) for all state(i, j) = 1
    */
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;           //Each character is a palindrome of length 1
            ans++;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1 or dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;                      
    }
};