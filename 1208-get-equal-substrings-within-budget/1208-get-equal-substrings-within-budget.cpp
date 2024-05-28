class Solution {
public:
//APPROACH: Using Sliding Window
  int equalSubstring(string s, string t, int maxCost) {
    int sum = 0;      // Variable to track the current cost of changing characters
    int i = 0, j = 0; // Initialize two pointers: 'i' for the start and 'j' for the end of the window

    while (j < s.size()) {
      sum += abs(s[j] - t[j]); // Add the cost of changing the character at index 'j' in 's' to 't'
      j++;      // Move the end pointer 'j' to the next character

      if (sum > maxCost) {       // Check if the current cost exceeds the allowed limit
        sum -= abs(s[i] - t[i]); // If yes, remove the cost of the char at index 'i' in 's' from the sum
        i++;    // Move the start pointer 'i' to the next character (shrink the window)
      }
    }

    return j - i; // The length of the window (j - i) represents the maximum valid substring
  }
};
