class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int indx, vector<int>& dp) {
        if(indx >= n) {
            return 0;
        }
        
        if(dp[indx] != -1) {
            return dp[indx];
        }
        
        int option1 = costs[0] + solve(n, days, costs, indx+1, dp);     //For 1 day pass
        
        int i;
        
        for(i=indx; i < n and days[i] < days[indx] + 7; i++);           //For 7 day pass
        int option2 = costs[1] + solve(n, days, costs, i, dp);
        
        for(i=indx; i < n and days[i] < days[indx] + 30; i++);          //For 30 days pass
        int option3 = costs[2] + solve(n, days, costs, i, dp);
        
        return dp[indx] = min(option1, min(option2, option3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        
        return solve(n, days, costs, 0, dp);
    }
};