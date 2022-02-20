class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp; 
        priority_queue<pair<char,int>> pq;
        string ans = "";
        
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        
        for(auto it: mp){
            pq.push({it.first, it.second});   // Pushing the characters with their frequencies
        }
        
        while(!pq.empty()) {
            char ch1 = pq.top().first;
            int n1 = pq.top().second;
            pq.pop();
            
            int len = min(repeatLimit, n1); // Min'm of repeatLimit & present character count
            for(int i=0; i<len; i++) { 
                ans += ch1;                 // Adding the highest priority element to the ans
            }
            
            char ch2;
            int n2 = 0;
            if(n1 - len > 0){       // If count of present character is more than the limit
                if(!pq.empty()) {   // Getting the next priority character.
                    ch2 = pq.top().first;
                    n2 = pq.top().second;
                    pq.pop();
                }
                else {
                    return ans;   // If there is no another letter to add
                }
                ans += ch2;       // Adding next priority character to ans
                
                        // If elements are left out, push them back into pq for next use
                pq.push({ch1, n1-len});
                if(n2 - 1 > 0) {
                    pq.push({ch2, n2-1});
                } 
            }
        }
        return ans;
    }
};