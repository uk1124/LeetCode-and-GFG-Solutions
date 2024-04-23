class Solution {
public:
//APPROACH: Using 2 pointers
    int compress(vector<char>& chars) {
        //Initialize ans to 0 (index of compressed array) and i to 0 (current index of input array)
        int ans = 0, i = 0; 
        
        while(i < chars.size()) {
            char letter = chars[i];
            int count = 0;      //For each character letter, initialize a count to 0

            //While the current character is the same as letter, increment the count and move to the next index
            while(i < chars.size() and chars[i] == letter) {
                count++;
                i++;
            }

            //Set the current position in the output array to letter (representing a single occurrence)
            chars[ans++] = letter;
            
            //If the count is greater than 1, convert the count to a string & add each digit as a separate character
            if(count > 1) {
                for(char ch: to_string(count)) {
                    chars[ans++] = ch;
                }
            }    
        }
        return ans;
    }
};
