class Solution {
public:
    /*Important point to note: Subarray need to be consecutive。
      Subsequence don't have to be consecutive. */

    int removePalindromeSub(string s) {
        if(s == "") {
            return 0;
        }
        string t = s;
        reverse(s.begin(), s.end());
        if(t == s) {
            return 1;
        }
        return 2;
    }
};