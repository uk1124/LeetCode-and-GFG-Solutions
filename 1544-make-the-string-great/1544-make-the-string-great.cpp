class Solution {
public:
    string makeGood(string s) {
        if (s.size() < 2) {
            return s;
        }

        // Flag to keep track if any adjacent characters were removed
        bool removedAdjacent = true;

        // Repeat the process until no adjacent characters are removed
        while (removedAdjacent) {
            removedAdjacent = false; // Reset the flag before each iteration
            int n = s.size();
            for (int i = 0; i < n - 1; i++) {
                // Check if adjacent characters violate the condition
                if (abs(s[i] - s[i + 1]) == 32) { 
                    // Remove the adjacent characters
                    s.erase(i, 2);
                    removedAdjacent = true; // Set the flag to true since characters were removed
                    break;              // Break out of the loop after removing adj characters
                }
            }
        }
        return s;
    }
};

/*EXTRAS:
The condition on line 17 -
The numerical difference between the lowercase and uppercase letters of the same alphabet is always 32.
*/