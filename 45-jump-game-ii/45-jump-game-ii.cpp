class Solution {
public:
    long long solve(int currIndx, int dest, vector<int> &nums, vector<int> &dp) {
        if(currIndx >= dest) {
            return 0;
        }
        if(dp[currIndx] != -1) {
            return dp[currIndx];
        }
        
        long long ans = INT_MAX;
        for(int i=1; i<=nums[currIndx]; i++) {
            if(i + currIndx > dest) {
                break;
            }
            ans = min(ans, 1 + solve(currIndx+i, dest, nums, dp));  
        } 
        
        return dp[currIndx] = ans;  
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return solve(0, n-1, nums, dp);
    }
};