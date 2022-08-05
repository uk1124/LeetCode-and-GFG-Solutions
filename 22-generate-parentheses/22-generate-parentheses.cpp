class Solution {
public:
    void solve(vector<string> &ans, string s, int n, int m) {
        if(n == 0 and m == 0) {
            ans.push_back(s);
            return;
        }
        if(m > 0) {
            solve(ans, s + ')', n, m-1);
        }
        if(n > 0) {
            solve(ans, s + '(', n-1, m+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, 0);
        return ans;
    }
};