class Solution {
public:
//APPROACH: Similar to Next Greater Element
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Initialize the result vector with zeros
        stack<int> st;             // Stack to store the indices of temperatures

        for(int i = 0; i < n; ++i) {
            // Check if the current temperature is higher than the temperature at the top of the stack
            while(!st.empty() and temperatures[i] > temperatures[st.top()]) {
                // Update the result for the index at the top of the stack
                result[st.top()] = i - st.top();  
                st.pop();  // Pop the index from the stack as it is no longer needed
            }
            st.push(i);    // Push the current index onto the stack
        }

        return result;
    }
};