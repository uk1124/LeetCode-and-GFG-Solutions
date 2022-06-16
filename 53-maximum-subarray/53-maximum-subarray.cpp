class Solution {
public:
    //APPROACH: Using Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxel = nums[0];
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxel = max(maxel, sum);
            
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxel;
    }
};