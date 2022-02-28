class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            while(!st.empty() and temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);             // Pushing the index of the elements
        }
        
        while(!st.empty()) {        // All the remaining elements in the stack would not have any future day, so assign them to 0.
            ans[st.top()] = 0;
            st.pop();
        }
        
        return ans;
    }
};