class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0; // Initialize the variable to store the reversed bits

        // Iterate through each bit of the input no (32 bits in total)
        for(int i = 0; i < 32; i++) {
            // Shift the curr result to the left by 1 position and add the rightmost bit of the input no
            ans = (ans << 1) + (n >> i & 1);
        }
        return ans; 
    }
};
