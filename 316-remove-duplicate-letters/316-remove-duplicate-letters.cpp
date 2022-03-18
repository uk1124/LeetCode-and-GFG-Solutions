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
            while(ch < ans.back() and counter[ans.back()] > 0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += ch;
            visited[ch] = true;
        }
        return ans;
    }
};