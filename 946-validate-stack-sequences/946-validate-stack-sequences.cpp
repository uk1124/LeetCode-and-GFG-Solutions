class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> st;
        int i = 0;
        for(int el: pushed) {
            st.push(el);
            
            while(!st.empty() and st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};