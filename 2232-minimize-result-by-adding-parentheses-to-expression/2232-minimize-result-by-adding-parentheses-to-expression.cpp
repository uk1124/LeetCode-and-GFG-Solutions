class Solution {
public:
    //APPROACH: Brute Force (Check all possible combinations), Heavy Implementation.
    string minimizeResult(string expression) {
        string ans;
        int n = expression.size();
        int plus, res;
        res = INT_MAX;
        
        for(int i=0; i<n; i++) {
            if(expression[i] == '+') {
                plus = i;
                break;
            }
        }
        
        for(int i=0; i<plus; i++) {
            int left = 0;
            for(int j=0; j<i; j++) {
                left = (left*10) + (expression[j] - '0');
            }
            if(left == 0) {
                left = 1;
            }
            for(int k = n-1; k > plus; k--) {
                int right = 0;
                for(int j = k+1; j < n; j++) {
                    right = (right * 10) + (expression[j] - '0'); 
                }
                if(right == 0) {
                    right = 1;
                }
                int midl = 0, midr = 0;
                for(int j=i; j < plus; j++) {
                    midl = (midl * 10) + (expression[j] - '0');
                }
                for(int j=plus+1; j <= k; j++) {
                    midr = (midr * 10) + (expression[j] - '0');
                }
                int value = left * (midl + midr) * right;
                if(value < res) {
                    string s = expression;
                    s.insert(s.begin()+i, '(');
                    s.insert(s.begin()+k+2, ')');
                    ans = s;
                    res = value;
                }
            } 
        }
        return ans;
    }
};