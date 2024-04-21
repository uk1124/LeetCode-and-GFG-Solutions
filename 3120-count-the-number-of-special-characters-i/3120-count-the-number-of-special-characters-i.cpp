class Solution {
public:
    int numberOfSpecialChars(string s) {
        // Set to store lowercase characters
        set<int> s1;
        // Set to store corresponding uppercase characters
        set<int> s2;

        for(auto ch : s) {
            // If the character is lowercase, insert its position in set s1
            if(ch >= 'a' and ch <= 'z') {
                s1.insert(ch - 'a'); // Convert character to its position in the alphabet
            }
            // If the character is uppercase, insert its position in set s2
            else {
                s2.insert(ch - 'A'); // Convert character to its position in the alphabet
            }
        }
        
        int ans = 0;
        // Iterate through each character in set s1
        for(auto ch : s1) {
            // If the corresponding uppercase character is present in set s2
            if(s2.find(ch) != s2.end())
                ans++; 
        }
        return ans; 
    }
};
