class Solution {
public:
    int lengthOfLongestSubstring(string s) {        // SOLUTION USING SLIDING WINDOW CONCEPT
        int i = 0, j = 0;
        int n = s.size();
        unordered_set<char> set;
        int ans = 0;
        
        while(i < n and j < n) {
            if(set.find(s[j]) == set.end()) {       // The character doesn't exist in the set
                set.insert(s[j++]);            // Inserting the characetr in the set and moving forward 
                ans = max(ans, j-i);                // Taking the max distance b/w characters
            }
            else {                                  // The character exists in the set
                set.erase(s[i++]);             // Removing the ith character as j has already covered it 
            }                                  // i.e It's a repeating character
        }
        return ans;
    }
};