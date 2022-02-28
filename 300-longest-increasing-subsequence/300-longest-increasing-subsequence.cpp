class Solution {
public:
    int dp[2510];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, LIS(i, nums));
        }
        return ans;
    }
    
    int LIS(int i, vector<int> &a) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for(int j=0; j<i; j++) {
            if(a[i] > a[j]) {
                ans = max(ans, LIS(j, a)+1);
            }
        }
        return dp[i] = ans;
    }
};