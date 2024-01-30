class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"+", "-", "*", "/"};

        for (const string& token : tokens) {
            if (operators.find(token) == operators.end()) {
                // If the token is not an operator, push its integer value to the stack
                st.push(stoi(token));
            } 
            else {
         // If the token is an operator, pop two operands, perform the operation & push the result back
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();

                if (token == "+") st.push(operand1 + operand2);
                else if (token == "-") st.push(operand1 - operand2);
                else if (token == "*") st.push(operand1 * operand2);
                else st.push(operand1 / operand2);
            }
        }
        // The final result is on the top of the stack
        return st.top();
    }
};