class Solution {
public:
/* APPROACH: Use a two-pointer technique to find the minimum number of characters needed from both ends of the 
string to ensure at least k occurrences of 'a', 'b', and 'c'.
*/
    int takeCharacters(string s, int k) {
        int ca = 0, cb = 0, cc = 0;
        int n = s.size();
        int ans = n;

        // Count total occurrences of 'a', 'b', and 'c'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            if (s[i] == 'b') cb++;
            if (s[i] == 'c') cc++;
        }

        // If any character count is less than k, return -1
        if (ca < k or cb < k or cc < k) return -1;

        int i = n-1, j = n-1;

        // Traverse from the end of the string
        while (i >= 0) {
            // Decrement counts as we move left
            if (s[i] == 'a') ca--;
            if (s[i] == 'b') cb--;
            if (s[i] == 'c') cc--;

            // Move the right pointer `j` left until we have enough characters
            while (ca < k or cb < k or cc < k) {
                if (s[j] == 'a') ca++;
                if (s[j] == 'b') cb++;
                if (s[j] == 'c') cc++;
                j--;
            }

            // Update the minimum answer
            ans = min(ans, i+n-1-j);
            i--;
        }

        return ans;
    }
};