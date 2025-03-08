class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0, ans = INT_MAX;
        
        // Count white blocks in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount++;
            }
        }
        
        ans = whiteCount; // Initial minimum recolors required

        // Slide the window across the string
        for (int left = 1; left + k - 1 < blocks.size(); left++) {
            if (blocks[left - 1] == 'W') whiteCount--; // Remove the outgoing block
            if (blocks[left + k - 1] == 'W') whiteCount++; // Add the incoming block

            ans = min(ans, whiteCount);
        }

        return ans;
    }
};
