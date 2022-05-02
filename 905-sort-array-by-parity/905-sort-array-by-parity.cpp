class Solution {
public:
    //APPROACH: Using two-pointers.
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if(!(nums[i] & 1)) {            // Even first
                i++;
            }
            else {
                if(nums[j] & 1) {           // Both odd
                    j--;
                }
                if (!(nums[j] & 1)) {       // Odd, Even
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                }
            }
        }
        return nums;
    }
};