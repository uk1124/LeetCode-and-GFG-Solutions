class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        
        while(ss>>s) {
            ans = s + " " + ans;
        }
        ans.pop_back();                 // Removing the space at the end
        return ans;
    }
};