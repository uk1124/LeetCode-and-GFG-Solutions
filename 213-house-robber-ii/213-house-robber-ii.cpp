class Solution {
public:
    //APPROACH: USing DP (Bottom Up)
   int solve(vector<int> &nums) {
       int n = nums.size();
       int prev = nums[0];
       int prev2 = 0;
    
    for(int i=1; i<n; i++) {
        int pick = nums[i];
        if(i > 1) {
            pick += prev2;
        }
        int nonPick = 0 + prev;
        int cur_i = max(pick, nonPick);
        
        prev2 = prev;
        prev= cur_i;
    }
       return prev;
   }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return n ? nums[0] : 0;
        }
        
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0; i<n; i++) { /*It is evident that we can't include first & last houses together in the answer as                                    they are adjacent, so in v1 include the first & in v2 include the last house */
            if(i != 0) {
                v1.push_back(nums[i]);
            }
            if(i != n-1) {
                v2.push_back(nums[i]);
            }
        }
        int ans1 = solve(v1);
        int ans2 = solve(v2);
        return max(ans1, ans2);
    }
};