class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp) {
        if (amount < 0) return -1; // Base case: invalid amount
        if (amount == 0) return 0; // Base case: no coins needed for amount 0
        
        if (dp[amount] != -2) {   // Return already computed result
            return dp[amount]; 
        }
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int ans = solve(coins, amount - coin, dp);
            if (ans >= 0 and ans < minCoins) {
                minCoins = 1 + ans; // Update minimum coins needed
            }
        }
        
        dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins; // Store the result in memo
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, -2); // Initialize memo array with a default value
        return solve(coins, amount, dp);
    }
};