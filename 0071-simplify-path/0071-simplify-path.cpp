class Solution {
public:
    string simplifyPath(std::string path) {
        stack<string> st;
        vector<string> components;

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                continue;  // Ignore consecutive slashes
            }

            string temp = "";
            while (i < path.size() and path[i] != '/') {
                temp += path[i++];
            }
            
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } 
            else if (temp != ".") {
                st.push(temp);
            }
        }

        while (!st.empty()) {
            components.insert(components.begin(), st.top());
            st.pop();
        }

        string ans = "/";
        for (const auto& comp : components) {
            ans += comp + "/";
        }

        if (ans.size() > 1) {
            ans.pop_back();  // Remove the trailing '/'
        }

        return ans;
    }
};
