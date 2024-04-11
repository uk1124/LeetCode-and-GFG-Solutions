class Solution {
public:
    string removeKdigits(string num, int k) {
        // If k is equal to the length of num, remove all digits
        if(k == num.size()) { 
            return "0";
        }
        stack<char> st; // Use stack to store the digits
        
        for(int i = 0; i < num.size(); i++) {
            // While there's a digit which is less than the previous digit, discard the previous one
            while(k > 0 and !st.empty() and st.top() > num[i]) { 
                st.pop();
                k--;
            }
            st.push(num[i]); // Push the current digit into the stack
        }
        
        while(k > 0){   // For cases like "2222" where k is not fully utilized
            st.pop();
            k--;            
        }
        
        string ans = ""; // Initialize the resulting string
        
        // Construct the resulting string from the stack
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        // Remove leading zeroes
        int j = ans.size() - 1;
        while(ans[j] == '0' and ans.size() > 1) {
            ans.pop_back();
            j--;
        }
        
        reverse(ans.begin(), ans.end()); // Reverse the string to get the correct order
        return ans; 
    }
};
