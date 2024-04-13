class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = ""; 
        int maxLength = max(word1.size(), word2.size());

        // Iterate through the indices up to the maximum length
        for(int i = 0; i < maxLength; i++) { 
            if(i < word1.size()) {       // If there are more characters in word1
                ans.push_back(word1[i]); // Append the character from word1 to the merged string
            }
            if(i < word2.size()) {       // If there are more characters in word2
                ans.push_back(word2[i]); // Append the character from word2 to the merged string
            }
        }
        return ans; 
    }
};
