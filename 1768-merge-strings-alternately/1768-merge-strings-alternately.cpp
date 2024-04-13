class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int maxLength = max(word1.size(), word2.size()); 

        for(int i = 0; i < maxLength; i++) {
            if(i < word1.size()) {
                ans.push_back(word1[i]);
            }
            if(i < word2.size()) {
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};