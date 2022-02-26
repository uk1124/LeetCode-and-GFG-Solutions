class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int curr = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                stack.push(curr);
                curr = 0;
            }
            else {                                      // If there is a ')'
                curr = stack.top() + max(curr*2, 1);    // The curr score will be doubled at least 1
                stack.pop();
            }
        }
        return curr;
    }
};