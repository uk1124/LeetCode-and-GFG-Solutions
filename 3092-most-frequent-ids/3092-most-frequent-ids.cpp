class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<int, long long> mp;        // Initialize a map to store the count of IDs
        priority_queue<pair<long long, int>> pq; // Initialize a priority queue to track the max count of IDs
        vector<long long> ans;                   

        for(int i = 0; i < n; i++) {
            mp[nums[i]] += freq[i];          // Update the count of IDs based on the frequency
            pq.push({mp[nums[i]], nums[i]}); // Push the count and ID pair into the priority queue

            // Adjust the priority queue to ensure it reflects the correct maximum count
            while (!pq.empty()) {
                auto p = pq.top(); 
                if (mp[p.second] != p.first) { // If the count in the map doesn't match the count in the priority queue
                    pq.pop();
                    if (mp[p.second]) {        // If the count is still non-zero
                        pq.push({mp[p.second], p.second}); // Push the updated count and ID pair back into the priority queue
                    }
                } else { // If the count in the map matches the count in the priority queue
                    break; 
                }
            }
            ans.push_back(pq.top().first); // Push the maximum count from the priority queue into the result vector
        }

        return ans;
    }
};