class Solution {
public:
    // APPROACH: use a stack for checking the validity of parentheses, and later remove the indexes of invalid parentheses from the string
    string minRemoveToMakeValid(string s) {
        stack <int> st;
        string ans = "";
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.empty()) {
                    s[i] = '#';
                    
                }
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '#') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};