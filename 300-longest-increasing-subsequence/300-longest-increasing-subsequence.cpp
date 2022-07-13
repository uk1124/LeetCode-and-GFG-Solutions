class Solution {
public:
    //APPROACH: Using DP
    int LIS(int i, vector<int> &a, vector<int> &dp) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for(int j=0; j<i; j++) {
            if(a[i] > a[j]) {
                ans = max(ans, LIS(j, a, dp)+1);
            }
        }
        return dp[i] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, LIS(i, nums, dp));
        }
        return ans;
    }
};