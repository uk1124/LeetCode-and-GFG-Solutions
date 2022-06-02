class Solution {
    //APPROACH: 2D DP, Memoization.
    public:
    int dp[10000 + 1][12 + 1];
    
    int memoization(vector<int>& wt, int w, int n) {
        if(n == 0 or w == 0) {
            return (w == 0) ? 0 : INT_MAX - 1;
        }
        
        if(dp[w][n] != -1) {
            return dp[w][n]; 
        }
			
        if(wt[n-1] > w) {
            return dp[w][n] = 0 + memoization(wt, w-0, n-1);
        }
        else {
            return dp[w][n] = min(0 + memoization(wt, w-0, n-1), 1 + memoization(wt, w-wt[n - 1], n));
        }
    }
    
    int coinChange(vector<int>& coins, int amount)  {
        memset(dp, -1, sizeof(dp)); 
        int minCoins = memoization(coins, amount, coins.size());
        if(minCoins == INT_MAX - 1) {
            return -1;
        }  
        else {
            return minCoins;  
        }
    }
};