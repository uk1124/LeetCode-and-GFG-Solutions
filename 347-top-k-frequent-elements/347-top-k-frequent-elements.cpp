class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>> pq;   // pair<first, second>: first is frequency, second is no.
         
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
            if(pq.size() > (int)mp.size() - k) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};