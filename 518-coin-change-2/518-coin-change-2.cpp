class Solution {
public:   
    /*Using DP (Bottom Up)
    Try all combinations of the given coins to select the ones that give a total sum of amount. */
    
    //(2-D DP)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++) {
            dp[i][0] = 1;
            for(int j=1; j<=amount; j++) {
                dp[i][j] = dp[i-1][j];
                if(j - coins[i-1] >= 0) {
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
    
    //(1-D DP)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<int> dp(amount+1, 0);
    //     dp[0] = 1;
    //     for(int i=0; i<n; i++) {
    //         for(int j=1; j<=amount; j++) {
    //             if(j - coins[i] >= 0) {
    //                 dp[j] += dp[j - coins[i]]; 
    //             }
    //         }
    //     }
    //     return dp[amount];
    // }
};