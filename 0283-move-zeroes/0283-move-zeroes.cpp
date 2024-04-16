class Solution {
public:
//APPROACH: Move through the array, placing non-zero elements at the front and filling the remaining positions with zeros.
    void moveZeroes(vector<int>& nums) {
        // Initialize nonZeroIndex to track the position where non-zero elements should be moved
        int nonZeroIndex = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Move the non-zero element to the nonZeroIndex position
                nums[nonZeroIndex] = nums[i];
                // Increment nonZeroIndex to the next position
                nonZeroIndex++;
            }
        }

        // Fill the remaining positions to the right with zeros
        while(nonZeroIndex < nums.size()) {
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
        }
    }
};
