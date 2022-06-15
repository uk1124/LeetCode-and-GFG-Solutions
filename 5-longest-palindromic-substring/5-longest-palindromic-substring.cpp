class Solution {
public:
    //APPROACH: Using DP (Bottom Up Approach)
    string longestPalindrome(string s) {
        if(s.size() == 0) {
            return "";
        }
        int i = 0, j = 0;
        int n = s.size();
        vector<vector<int>> P(n, vector<int>(n, 0));
        
        for(int i = 0; i<n; i++){
            P[i][i] = 1;
            if(i == n-1) {
                break;
            }
            P[i][i+1] = (s[i] == s[i+1]);
        }
        
        for(int i = n-3; i>=0; i--) {
            for(int j = i+2; j<n; j++) {
                P[i][j] = (P[i+1][j-1] and s[i] == s[j]);     
            }
        }
        
        int max = 0;
        string ans = "";
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(P[i][j] == 1 and j-i+1 > max) {
                    max = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};