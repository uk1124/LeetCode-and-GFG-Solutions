class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMin(nums), dpMax(nums);
        int ans = nums[0];
        for(int i = 1; i < size(nums); i++) {
            if(nums[i] >= 0) {
                dpMin[i] = min(nums[i], nums[i] * dpMin[i-1]);
                dpMax[i] = max(nums[i], nums[i] * dpMax[i-1]);
            }
            else {
                dpMin[i] = min(nums[i], nums[i] * dpMax[i-1]);
                dpMax[i] = max(nums[i], nums[i] * dpMin[i-1]);
            }
            
            // dpMin[i] = min(nums[i], nums[i] * (nums[i] >= 0 ? dpMin[i-1] : dpMax[i-1]));
            // dpMax[i] = max(nums[i], nums[i] * (nums[i] >= 0 ? dpMax[i-1] : dpMin[i-1]));
            
            ans = max(ans, dpMax[i]);
        }
        return ans;
    }
};