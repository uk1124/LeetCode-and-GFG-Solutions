class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, bool> visited;
        unordered_map <char, int> counter;
        string ans = "";
        for(char ch: s) {
            counter[ch]++;
        }
        
        for(char ch: s) {
            counter[ch]--;
            if(visited[ch]) {
                continue;
            }
            while(ch < ans.back() and counter[ans.back()] > 0) {    // ch < result.back() is for making ans as lexicographically small as possible, counter[ans.back()] > 0 ensures that there is at least one such element(ans.back()) left after pop_back(), to be append to ans later (so that each letter would appear at least once)
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += ch;
            visited[ch] = true;
        }
        return ans;
    }
};