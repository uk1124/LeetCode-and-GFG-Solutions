class Solution {
public:
    /*APPROACH: Using DP (Bottom Up)
     Use dpMax and dpMin arrays where dpMax[i] denotes maximum subarray product ending at i and dpMin[i] denotes
     minimum subarray product ending at i.
     At each index i, we will update dpMin[i] as minimum of A[i] (denotes forming new subarray by choosing current
     element) and min(A[i] * dpMin[i-1], A[i] * dpMax[i-1]) (denotes expanding previous subarray product by 
     current element). We do it similarly for dpMax[i] as well. Finally, the maximum product subarray will be the
     maximum value in dpMax array. */
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
            ans = max(ans, dpMax[i]);
        }
        return ans;
    }
};