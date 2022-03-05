class Solution {
public:
    // APPROACH: Using hashmap and vector
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map <int, vector<int>> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            string s = to_string(nums[i]);
            int t = 0;
            for(int i=0; i<s.size(); i++) {
                int x = s[i] - '0';
                t = t*10 + mapping[x];
            }
            mp[t].push_back(nums[i]);
        }
        
        for(auto it: mp) {
            for(auto el: it.second) {
                ans.push_back(el);
            }
        }
        return ans;
    }
};