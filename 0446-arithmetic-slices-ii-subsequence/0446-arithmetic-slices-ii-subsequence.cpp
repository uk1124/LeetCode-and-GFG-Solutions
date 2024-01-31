class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        // dp vector to store the count of arithmetic subsequences
        // dp[i][diff] represents the count of subsequences ending at index i with the common difference 'diff'
        vector<unordered_map<long long, int>> dp(n);
        
        // Iterate over the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Calculate the difference between nums[i] and nums[j]
                long long diff = (long long) nums[i] - nums[j];
                
                // Retrieve the count of subsequences ending at index j with the common difference 'diff'
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                
                // Update the count of subsequences ending at index i with the common difference 'diff'
                dp[i][diff] += cnt + 1;
                
                // Update the total count of arithmetic subsequences
                ans += cnt;
            }
        }
        return ans;
    }
};
