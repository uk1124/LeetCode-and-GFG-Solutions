class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: Calculate the XOR of all elements in nums with k
        for(int el: nums) {
            k ^= el;
        }

        // Step 2: Count the number of set bits in the XOR result
        int ans = 0;
        while(k) {
            ans += (k&1); // Increment ans if the least significant bit is set
            k >>= 1;      // Shift k to the right to check the next bit
        }
        return ans; // Return the count of set bits, which represents the min operations needed
    }
};
