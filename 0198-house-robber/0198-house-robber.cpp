class Solution {
public:
/*APPROACH: DP (Space-Optimzed) 
Just maintain the values of previous index (prev) and previous-to-previous index (prev2) and we can 
calculate the value for current index (curr) using just these two variables and roll-forward each time.
*/
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = 0, curr = 0;

        for(int el : nums) {
            curr = max(prev, el + prev2);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }

/*APPROACH: DP: (Tabulation)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int> dp(nums);

        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[n-1];
    }
*/

/*APPRAOCH: DP (Memoziation)
We have two choices - 
i) Don't rob the house and move to next house.
ii) Rob the house and move to the house after next house (Can't move directly to next house because we can't rob adjacent houses).
    int func(int i, vector<int> &nums, vector<int> &dp) {
        if(i < 0) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int pickCurr = nums[i] + func(i-2, nums, dp);
        int notPickCurr = 0 + func(i-1, nums, dp);

        return dp[i] = max(pickCurr, notPickCurr);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        int ans = func(nums.size()-1, nums, dp);

        return ans;
    }
*/
};