class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result; 
        int n = words.size();     
        int index = 0; // Current index in the words array
        
        while (index < n) {
            int totalChars = words[index].length(); // Total characters in the current line
            int last = index + 1; // Index of the last word in the current line
            
            // Determine the range of words that can fit in the current line
            while (last < n) {
                if (totalChars + words[last].length() + 1 > maxWidth) { // Check if adding the next word exceeds maxWidth
                    break; 
                }
                totalChars += words[last].length() + 1; // Add the length of the next word plus one space
                last++;
            }
            
            string line; // String to store the current line
            int numWords = last - index; // Number of words in the current line
            int numSpaces = maxWidth - totalChars; // Total number of spaces to distribute
            
            // Handle last line or lines with a single word differently
            if (last == n or numWords == 1) {
                // For the last line or lines with a single word, left justify the text
                for (int i = index; i < last; i++) {
                    line += words[i] + " "; // Add the word followed by a space
                }
                //line.pop_back(); // Remove the trailing space
                while (line.length() < maxWidth) {
                    line += " "; // Add spaces to the end until the line length matches maxWidth
                }
            } 
            else { // For other lines, distribute spaces as evenly as possible
                int spacesPerSlot = numSpaces / (numWords - 1); // Minimum number of spaces between words
                int extraSpaces = numSpaces % (numWords - 1); // Number of slots that will get an extra space
                
                for (int i = index; i < last; i++) {
                    line += words[i]; // Add the word to the line
                    if (i < last - 1) {
                        // Add the appropriate number of spaces after each word
                        for (int j = 0; j <= (spacesPerSlot + (i - index < extraSpaces ? 1 : 0)); j++) {
                            line += " ";
                        }
                    }
                }
            }
            result.push_back(line); // Add the current line to the result
            index = last; // Move to the next group of words
        }
        
        return result; 
    }
};
