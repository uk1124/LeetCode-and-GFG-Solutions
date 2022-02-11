// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string ans = "";
        if(s.size() == 0) {
            return ans;
        }

        stack<string>st;
        string x = "";
        stack<string>temp;
        
        for(int i =0; i < s.size(); i++) {
            if(s[i] == '.') {
                st.push(x);
                x = "";
            }
            else {
                x += s[i];
            }
        }
        st.push(x);
        
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        while(!temp.empty()) {
            string y = temp.top();
            temp.pop();
            int indx = y.find_first_not_of('0');
            if(indx == -1) {
                ans += '0';
                ans += '.';
            }
            else {
                string m = y.substr(indx);
                ans += m;
                ans += '.';   
            }   
        }
        ans.pop_back();
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends