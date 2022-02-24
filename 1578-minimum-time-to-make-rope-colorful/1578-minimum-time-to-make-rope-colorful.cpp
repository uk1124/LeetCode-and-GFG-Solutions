class Solution {
public:     // APPROACH:  If we have repeated characters, we need to remove all of them except the 'most expensive' character.
    int minCost(string colors, vector<int>& neededTime) {
        int max_cost = 0, ans = 0;
        
        for(int i = 0; i<colors.size(); i++) {
             if(i>0 and colors[i] != colors[i-1]){ // Curr character is diff than previous one,                                                    // so subtract max_cost and set it to zero.
                ans -= max_cost;
                max_cost = 0;
            }                   // Repeating characters, so add time to remove all of them                                       // except the most expensive one.
            ans += neededTime[i];       
            max_cost = max(max_cost, neededTime[i]);
        }
        return ans - max_cost;
    }
};