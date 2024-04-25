class Solution {
public:
//APPROACH: Using DP
    int solve(string& s, int index, int prev, int k, vector<vector<int>>& dp){
        // Base case: if index exceeds the size of string s, return 0
        if(index >= s.size()) {
            return 0;
        }
        
        // If the result is already computed, return it from dp table
        if(dp[index][prev] != -1) {
            return dp[index][prev];
        }
        
        int inc = 0, not_inc = 0;
        // Check if the current character can be included in the ideal string
        if(prev == 0 or abs(s[index] - prev) <= k){
            inc = 1 + solve(s, index+1, s[index], k, dp); // Include current character
        }
        // Exclude current character and proceed to the next index
        not_inc = solve(s, index+1, prev, k, dp);
        
        // Store the maximum of included and not included in dp table
        return dp[index][prev] = max(inc, not_inc);
    }
    
    int longestIdealString(string s, int k) {
        // Initialize dp table with -1
        vector<vector<int>> dp (s.size() + 1, vector<int>(150, -1)); // Using 150 as the size of the character array
        
        return solve(s, 0, 0, k, dp);
    }
};
