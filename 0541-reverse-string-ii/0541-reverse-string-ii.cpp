class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        // Iterate over the string with step size of 2k
        for(int i = 0; i < n; i += 2*k) {
            // Check if there are at least k characters remaining
            if(i + k <= n) {
                // If yes, reverse the first k characters
                reverse(s.begin() + i, s.begin() + i + k);
            } 
            else {
                // If there are fewer than k characters remaining, reverse all of them
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};