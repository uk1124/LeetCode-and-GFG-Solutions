class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "";

        for (char ch : s) {
            if (ch == '[' or isalnum(ch)) {
                st.push(string(1, ch));
            }  
            else {
                string temp = "";
                while(st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string num_str = "";
                while (!st.empty() and isdigit(st.top()[0])) {
                    num_str = st.top() + num_str;
                    st.pop();
                }
                int num = stoi(num_str);

                string repeated = "";
                while (num--) {
                    repeated += temp;
                }
                st.push(repeated);
            }
        }

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
