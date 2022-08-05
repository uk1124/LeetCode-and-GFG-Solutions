class Solution {
public:
    /*APPROACH: Using Recursion.
    'left', represents how many left parentheses remains; 'right' represents how many right parentheses remains. The
    remaining right parentheses should be larger than left ones. */
    void solve(vector<string> &ans, string s, int left, int right) {
        if(left == 0 and right == 0) {
            ans.push_back(s);
            return;
        }
        if(left > 0) {
            solve(ans, s + "(", left-1, right);
        }
        if(right > left) {
            solve(ans, s + ")", left, right-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, n);
        return ans;
    }
};