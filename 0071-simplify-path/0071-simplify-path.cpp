class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;           // Stack to keep track of valid components
        vector<string> components;  // Vector to store individual components of the path

        for(int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                continue;       // Ignore consecutive slashes
            }
            string temp = "";
            while(i < path.size() and path[i] != '/') {
                temp += path[i++];
            }
            // Process different cases
            if(temp == "..") {
                if (!st.empty()) {
                    st.pop();   // Move up one level if '..' encountered
                }
            } 
            else if (temp != ".") {
                st.push(temp);  // Push valid components onto the stack
            }
        }

        // Reconstruct the simplified path from the stack
        while(!st.empty()) {
            components.insert(components.begin(), st.top());
            st.pop();
        }

        string ans = "/";
        for(const auto& comp : components) {
            ans += comp + "/";  // Add '/' between components
        }

        if(ans.size() > 1) {
            ans.pop_back();     // Remove the trailing '/'
        }

        return ans;
    }
};

