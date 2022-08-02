class Solution {
public:
    bool solveMem(int indx, int sum, vector<int> &A, vector<vector<int>> &dp) {
        if(sum == 0) {
            return true;
        }
        
        if(indx < 0) {
            return false;
        }
        
        if(dp[indx][sum] != -1) {
            return dp[indx][sum];
        }
        
        bool isPossible = solveMem(indx-1, sum, A, dp);
        
        if(sum - A[indx] >= 0) {
            isPossible |= solveMem(indx-1, sum - A[indx], A, dp);
        }
        return dp[indx][sum] = isPossible;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) {
            return 0;
        }
        
        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        return solveMem(nums.size() - 1, sum, nums, dp);
    }

};