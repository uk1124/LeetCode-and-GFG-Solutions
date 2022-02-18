class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) {
            return "0";
        }
        stack<char> st;
        
        for(int i = 0; i < num.size(); i++) {
      // While there's a digit which is less than the previous digit, discard the previous one
            while(k > 0 and !st.empty() and st.top() > num[i]) { 
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k > 0){       // For cases like "2222"
            st.pop();
            k--;            
        }
        
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        int j = ans.size() - 1;
        while(ans[j] == '0' and ans.size() > 1) {
            ans.pop_back();
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};