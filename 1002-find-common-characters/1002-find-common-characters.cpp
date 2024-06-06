class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX); // Array to store minimum frequency of each character
        vector<string> result;  
        
        // Iterate over each word in the input vector
        for(string word : words) {
            vector<int> charCount(26, 0); // Array to count the frequency of each character in the current word
            // Count the frequency of each character in the current word
            for (char ch : word) {
                charCount[ch - 'a']++;
            }
            // Update the minimum frequency of each character across all words
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }
        
        // Construct the result vector based on the minimum frequencies
        for (int i = 0; i < 26; ++i) {
            while (minFreq[i] > 0) { // Add character 'a' + i to the result as many times as it appears in all words
                result.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }
        
        return result;
    }
};