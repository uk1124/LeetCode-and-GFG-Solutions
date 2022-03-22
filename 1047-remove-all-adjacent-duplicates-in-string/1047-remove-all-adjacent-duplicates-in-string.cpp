class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0; i<s.size(); i++) {
            while(!st.empty() and s[i] == st.top()) {
                st.pop();
                i++;
            }
            if(i != s.size()) {
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};