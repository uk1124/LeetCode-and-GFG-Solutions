class Solution {
public:
    //APPROACH: Using DP 
    int solveMem(vector<int> &values, int i, int j, vector<vector<int>> &dp) {
        if(i+1 == j) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {      //Fix one side of the polygon i, j and move k within (i, j).
            ans = min(ans, values[i]*values[j]*values[k] + solveMem(values, i, k, dp) + solveMem(values, k, j, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solveMem(values, 0, n-1, dp);
    }
};