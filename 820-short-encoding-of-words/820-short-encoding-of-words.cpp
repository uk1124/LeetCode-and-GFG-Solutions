class Solution {
public:
    /*APPROACH:
    Build a set of words.
    Iterate on all words and remove all suffixes of every word from the set.
    Finally the set will the set of all encoding words.
    Iterate on the set and return sum(word's length + 1 for every word in the set) */
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        for(string t: words) {
            s.insert(t);
        }
        
        for(string w : s)
            for(int i = 1; i < w.size(); ++i) {
                s.erase(w.substr(i));
            }
        
        int ans = 0;
        for(string w : s) {
            ans += w.size() + 1;
        }
        return ans;
    }
};