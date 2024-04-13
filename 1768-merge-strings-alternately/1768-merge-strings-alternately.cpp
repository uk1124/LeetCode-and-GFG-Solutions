class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int count = 0;

        for(int i=0; i<word1.size(); i++) {
            if(word2[i] == '\0') break;
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            count++;
        }

        if(count < word2.size()) {
            for(int i=count; i<word2.size(); i++) {
                ans.push_back(word2[i]);
            }
        }
        else {
            for(int i=word2.size(); i<word1.size(); i++) {
                ans.push_back(word1[i]);
            }
        }
        return ans;
    }
};