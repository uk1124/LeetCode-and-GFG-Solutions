class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st; // Stack to store the previous calculation value & sign before the next bracket ()

        int sum = 0;     // Variable to store the total sum of the expression
        int sign = +1;   // Variable to track the sign of the current number or expression

        // Loop through each character in the string
        for(int i = 0 ; i < s.size() ; ++i) {
            char ch = s[i]; // Current character

            if(isdigit(ch)) { // If the character is a digit
                int num = 0;  // Variable to store the current number

                // Parse the number (potentially multi-digit)
                while(i < s.size() && isdigit(s[i])) {
                    num = (num * 10) + s[i] - '0'; // Calculate the number
                    i++; // Move to the next character
                }
                i--; // Decrement i to account for the loop incrementing it again

                sum += (num * sign); // Add the current number to the total sum with the appropriate sign
                sign = +1; // Reset the sign for the next number or expression
            }
            else if(ch == '(') { // If the character is an opening bracket
                // Save the current state of (sum , sign) in the stack
                st.push(make_pair(sum , sign));

                // Reset sum & sign for the inner bracket calculation
                sum = 0; 
                sign = +1;
            }
            else if(ch == ')') { // If the character is a closing bracket
                // Calculate the sum for the inner bracket & update the current sum
                sum = st.top().first + (st.top().second * sum); // Retrieve previous sum & sign, apply the sign to the current sum
                st.pop(); // Pop the previous state from the stack
            }
            else if(ch == '-') { // If the character is a minus sign
                // Toggle the sign to prepare for the next number or expression
                sign = (-1 * sign);
            }
        }
        return sum;
    }
};
