class Solution {
public:
    /*APPROACH: Greedy
    Looking from the start and selecting the locally optimum in the hope of reaching global optimum */
    // bool canJump(vector<int>& nums) {
    //     int currIdx = 0;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(currIdx < i) {
    //             return false;
    //         }
    //         currIdx = max(i + nums[i], currIdx);
    //     }
    //     return true;
    // }
    
    /*APPROACH: Using DP (Bottom Up)
    Looking from the end and at each point ahead checking the best possible way to reach the end */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump(n, false);
        jump[n-1] = true;
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j <= nums[i] and i+j < n; j++) {
                if(jump[i+j])  {
                    jump[i] = true; 
                    break;
                }
            }
        }
        return jump[0];
    }
};