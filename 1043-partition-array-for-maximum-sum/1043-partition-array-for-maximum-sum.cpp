class Solution {
public:
/*APPROACH; Using DP
- dp[i] represents the max sum for the first i elements of the array.
- For each position i, iterate through the last k elements or less to find the max value in the 
current subarray.
- Update dp[i] by considering the max sum for the previous position plus the current max value 
multiplied by the length of the current subarray.
*/
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int maxVal = 0;
            // Iterate through the last k elements or less
            for (int j = 1; j <= min(k, i); ++j) {
                // Update the maximum value in the current subarray
                maxVal = max(maxVal, arr[i - j]);  
                // Calculate the maximum sum for the current position
                dp[i] = max(dp[i], dp[i - j] + maxVal * j);  
            }
        }
        return dp[n];
    }
};
