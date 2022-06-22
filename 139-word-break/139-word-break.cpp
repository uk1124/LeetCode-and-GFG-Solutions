class Solution {
    public:
    /*APPROACH: Using DP (Bottom Up)
    We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. The optimization
    is to look from current position i back and only substring and do dictionary look up in case the preceding
    position j with dp[j] == true is found. */
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) {
            return false;
        }
        int n = s.size();
        unordered_set<string> dict;
        for(string str: wordDict) {
            dict.insert(str);
        }
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=1; i<=n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(dp[j] != 0) {
                    string word = s.substr(j,i-j);
                    if(dict.find(word) != dict.end()) {
                        dp[i] = true;
                        break; 
                    }
                }
            }
        }
        return dp[n];
    }
};