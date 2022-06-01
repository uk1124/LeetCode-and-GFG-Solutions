class Solution {
public:
    int f(int indx, vector<int> &nums, vector<int> &dp) {
        if(indx == 0) {
            return nums[indx];
        }
        if(indx < 1) {
            return 0;
        }
        if(dp[indx] != -1) {
            return dp[indx];
        }
        
        int pick = nums[indx] + f(indx - 2, nums, dp);
        int notPick = 0 + f(indx - 1, nums, dp);
        
        return dp[indx] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(n-1, nums, dp);
    }
};