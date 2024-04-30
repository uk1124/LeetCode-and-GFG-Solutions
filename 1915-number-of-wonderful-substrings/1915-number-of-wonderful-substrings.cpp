class Solution {
public:
/*APPROACH: Use a bitmask and a map to efficiently count the no of wonderful substrings in the given 
string. It iterates through each character in the string, updating the bitmask to track the count of 
each letter encountered so far. It then uses the bitmask to calculate the count of wonderful substrings
and updates the result accordingly. Finally, it increments the count of substrings with the current 
bitmask in the map.
*/
    long long wonderfulSubstrings(string word) {
        // Map to store the count of substrings with odd count of each letter
        unordered_map<int, long long> count; 
        count[0] = 1; // Initialize with an empty substring
        
        int mask = 0;         // Initialize mask to track the count of each letter
        long long result = 0; // Initialize the result
        
        for(char c : word) {
            int index = c - 'a'; // Calculate the index of the current letter
            
            // Toggle the corresponding bit in the mask to update the count of the current letter
            mask ^= (1 << index);
            
            // Add the count of substrings with odd count of each letter to the result
            result += count[mask];
            
            // Update the count map
            for(int i = 0; i < 10; ++i) {
                int updated_mask = mask ^ (1 << i); // Toggle the bit for each possible letter
                
                // Add the count of substrings with odd count of each letter to the result
                result += count[updated_mask];
            }
            
            // Increment the count of substrings with the current mask
            count[mask]++;
        }
        
        return result;
    }
};
