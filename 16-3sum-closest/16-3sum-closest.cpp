class Solution {
public:
    /*APPROACH: Using two pointers.
    Sort nums in increasing order.
    Fix nums[i] by iterating i in range [0..n-2], we use 2 pointers to find 2 elements in range [i+1..n-1], so that
    nums[i] + nums[l] + nums[r] will have minimum difference with the target. */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n-2; ++i) {
            int l = i+1, r = n-1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) >= abs(sum3 - target)) {   //Update better ans
                    ans = sum3;
                }
                if (sum3 == target) {
                    break;
                }
                if (sum3 > target) {
                    --r;    //Sum3 is greater than the target, to minimize the difference decrease our sum3
                }
                else {
                    ++l;    //Sum3 is lesser than the target, to minimize the difference increase our sum3
                }
            }
        }
        return ans;
    }
};