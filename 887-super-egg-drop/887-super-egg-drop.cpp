class Solution {
public:
    /*APPROACH: USing DP (Top down approach)
    The dp equation is:
    dp[k][m] = 1 + dp[k-1][m-1] + dp[k][m-1]    (dp[K][M] means that, given K eggs & M moves, what is the max no. of
                                                floor that we can check.)
    which means we take 1 move to a floor,
    if egg breaks, then we can check dp[k-1][m-1] floors.
    if egg doesn't breaks, then we can check dp[k][m-1] floors.
    */
//     int find(int k, int n, vector<vector<int>> &dp) {
//         if(n == 0 or n == 1) {
//             return n;
//         }
//         if(k == 1) {
//             return n;
//         }
//         if(dp[k][n] != -1) {
//             return dp[k][n];
//         }
        
//         int ans = INT_MAX;
//         for(int i=1; i<=n; i++) {
//             int lo, hi;
//             if(dp[k-1][i-1] != -1) {        //Case if egg is broken (Check for lower floors)
//                 lo = dp[k-1][i-1];
//             }
//             else {
//                 lo = find(k-1, i-1, dp);
//                 dp[k-1][i-1] = lo;
//             }
            
//             if(dp[k][n-i] != -1) {          //Case if egg is not broken (Check for higher floors)
//                 hi = dp[k][n-i];
//             }
//             else {
//                 hi = find(k, n-i, dp);
//                 dp[k][n-i] = hi;
//             }
            
//             int temp = 1 + max(lo, hi);
//             ans = min(ans, temp);
//         }
//         return dp[k][n] = ans;
//     }
    
    //Bottom Up Approach
     int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
         for(int i=0; i<=k; i++) {
             dp[i][0] = 0,dp[i][1] = 1;   
         }
         for(int i=0; i<=n; i++) {
             dp[0][i] = 0,dp[1][i] = i;  
         }
         
        for(int i=2; i<k+1; i++) {
            for(int j=2; j<n+1; j++) {    
                int lo = 1, hi = j, temp = 0, ans = INT_MAX;
                while(lo <= hi) {
                     int mid=(lo + hi)/2;
                     int left= dp[i-1][mid-1]; 
                     int right= dp[i][j-mid];  
                     temp = 1 + max(left, right);     
                     if(left < right) {                  
                        lo = mid+1;                      
                    }
                     else {                         
                        hi = mid-1;
                    }
                     ans = min(ans, temp);              
                 }
                dp[i][j] = ans;
            }
        }
         return dp[k][n];   
     }
};