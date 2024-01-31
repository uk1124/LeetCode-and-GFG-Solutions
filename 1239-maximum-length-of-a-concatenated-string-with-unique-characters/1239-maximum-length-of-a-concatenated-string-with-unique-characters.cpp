/*APPROACH:
- The code utilizes DFS to explore all possible unique character concatenations of strings in the given array arr, while maintaining the maximum length encountered during the exploration. 
- The hasUniqueChars function checks if a string has unique characters, and the dfs function recursively explores different concatenations, updating the maximum length accordingly. 
- The maxLength function initiates the DFS exploration with an empty path.
*/
class Solution {
public:
    // Function to check if a string has unique characters
    bool hasUniqueChars(const string& s) {
        unordered_set<char> charSet;
        for (char ch : s) {
            if (charSet.count(ch)) {
                return false;
            }
            charSet.insert(ch);
        }
        return true;
    }

    // Depth-First Search to explore all possible concatenations
    void dfs(const vector<string>& arr, const string& currentPath, int currentIndex, int& maxLength) {
        // Check if the current path has unique characters
        if (hasUniqueChars(currentPath)) {
            maxLength = max(maxLength, static_cast<int>(currentPath.length()));
        }

        // Stop the recursion if we reached end of arr or if curr path doesn't have unique characters
        if (currentIndex == arr.size() or !hasUniqueChars(currentPath)) {
            return;
        }

        // Continue exploring all possible concatenations
        for (int i = currentIndex; i < arr.size(); i++) {
            dfs(arr, currentPath + arr[i], i + 1, maxLength);
        }
    }

    int maxLength(vector<string>& arr) {
        int maxLengthResult = 0;
        dfs(arr, "", 0, maxLengthResult);
        return maxLengthResult;
    }
};