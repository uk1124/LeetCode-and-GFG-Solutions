class Solution {
public:
    string decodeString(string s) {
        stack<string> st; // Stack to hold characters and strings during processing
        string ans = "";  // String to build the final decoded result

        // Iterate through each character in the input string
        for (char ch : s) {
            // If the character is '[' or an alphanumeric character, push it onto the stack
            if (ch == '[' or isalnum(ch)) {
                st.push(string(1, ch));
            }  
            else {
                // Build the encoded string inside the brackets
                string temp = "";
                // Pop characters from the stack until '[' is encountered
                while(st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                // Remove the '[' from the stack
                st.pop();
                
                // Build the number string which indicates how many times to repeat the temp string
                string num_str = "";
                // Pop characters from the stack until a non-digit character is encountered
                while (!st.empty() and isdigit(st.top()[0])) {
                    num_str = st.top() + num_str;
                    st.pop();
                }
                // Convert the number string to an integer
                int num = stoi(num_str);

                // Repeat the temp string 'num' times
                string repeated = "";
                while (num--) {
                    repeated += temp;
                }
                // Push the repeated string back onto the stack
                st.push(repeated);
            }
        }

        // Build the final answer by combining elements from the stack
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
