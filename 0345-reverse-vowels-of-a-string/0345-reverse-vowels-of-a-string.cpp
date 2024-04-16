class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vwls = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string vowels = "";
        for(char ch: s) {
            if(vwls.find(ch) != vwls.end()) {
                vowels += ch;
            }
        }
        int j = vowels.size()-1;
        for(int i=0; i<s.size(); i++) {
            if(vwls.find(s[i]) != vwls.end()) {
                s[i] = vowels[j--];
            }
        }
        return s;
    }
};