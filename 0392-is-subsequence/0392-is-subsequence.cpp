class Solution {
public:
/*APPROACH: Using 2 Pointers
Simple idea, we traverse both strings from left side to right side. If we find a matching character, 
we move ahead in both strings. Otherwise, we move ahead only in t. 
*/
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while(i < s.size() and j < t.size()) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};