class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        int dp[5010];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1] + 1;                // The AP will grow by 1
                ans += dp[i];
            }
        }
        return ans;
    }
};