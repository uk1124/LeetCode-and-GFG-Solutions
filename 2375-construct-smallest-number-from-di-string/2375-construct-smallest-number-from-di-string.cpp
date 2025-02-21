class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;
        int num = 1; // Start with the smallest digit

        for (int i = 0; i <= pattern.size(); i++) {
            st.push(num++); // Push the next available number
            
            // If it's the last character or we encounter 'I', pop the stack
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};
