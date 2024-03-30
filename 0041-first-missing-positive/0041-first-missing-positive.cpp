class Solution {
public:
/*APPROACH:
- Replace the negative values with n+1 values so that they will be out of the range
- Make the index negative if we found that value in the array
- Identify the index which is not negative and it will be the missing number
*/
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Replace non-positive integers with (n + 1)
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        
        // Mark present integers by making corresponding indices negative
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n and nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        // Find the smallest positive integer missing
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        // If all positive integers are present, return n + 1
        return n + 1;
    }
};
