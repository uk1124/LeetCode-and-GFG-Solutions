class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = nums[0];
        int curr = 0;
        for(int el: nums) {
            curr += el;
            ans = max(ans, curr);
            if(curr < 0) {
                curr = 0;
            }
        }
        return ans;
    }
};