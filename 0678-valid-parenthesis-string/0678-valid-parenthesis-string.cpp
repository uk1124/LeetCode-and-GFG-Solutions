class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParentheses; // Stack to store indices of '('
        stack<int> stars;        // Stack to store indices of '*'

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                leftParentheses.push(i);  // Store index of '('
            } 
            else if (s[i] == '*') {
                stars.push(i);      // Store index of '*'
            } 
            else {   // s[i] == ')'
                if (!leftParentheses.empty()) {
                    leftParentheses.pop();   // Match '(' with ')'
                } 
                else if (!stars.empty()) {
                    stars.pop();    // Use '*' as '('
                } 
                else {
                    return false;   // No matching '(' or '*' found
                }
            }
        }

        // Match remaining '*' with '('
        while (!leftParentheses.empty() and !stars.empty()) {
            if (leftParentheses.top() < stars.top()) {
                leftParentheses.pop();
                stars.pop();
            } 
            else {
                break;
            }
        }

        // If there are no remaining '(' to match with '*', stack of '(' should be empty
        return leftParentheses.empty();
    }
};