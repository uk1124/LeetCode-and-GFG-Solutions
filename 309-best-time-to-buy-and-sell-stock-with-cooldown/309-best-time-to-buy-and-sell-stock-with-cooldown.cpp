class Solution {
public:
    //APPROACH: Using DP
   int getAns(vector<int> Arr, int indx, int buy, int n, vector<vector<int>> &dp ) {
       if(indx >= n) {
           return 0;   
       }
       
       if(dp[indx][buy] != -1) {
           return dp[indx][buy];
       }
       
       int profit;
       if(buy == 0) {              // We can buy the stock
           profit = max(0 + getAns(Arr, indx+1, 0, n, dp), -Arr[indx] + getAns(Arr, indx+1, 1, n, dp));
       }
       
       if(buy == 1) {               // We can sell the stock
           profit = max(0 + getAns(Arr, indx+1, 1, n, dp), Arr[indx] + getAns(Arr, indx+2, 0,n, dp));
       }
       return dp[indx][buy] = profit;
   }
    
    int maxProfit(vector<int> prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int ans = getAns(prices, 0, 0, n, dp);
        return ans;
    }
};