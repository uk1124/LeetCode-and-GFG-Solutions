class Solution {
public:
    //APPROACH: Using Stack.
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char,int> symbols = { {'{',1}, {'[',2}, {'(',3}, {'}',-1}, {']',-2}, {')',-3} };
        
        for(char ch : s) {
            if(symbols[ch]>0) {
                st.push(ch);
            }
            
            else {
                if(st.empty()) {
                    return false ;
                }
                
                char top = st.top();
                st.pop();
                
                if(symbols[top] + symbols[ch] !=0) {
                    return false ;
                }
            }
        }
        
        if(st.empty()) {
            return true;
        }
        return false ;
    }
};

