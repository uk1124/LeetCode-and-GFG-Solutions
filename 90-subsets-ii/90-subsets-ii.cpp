class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0; i<(1<<n); i++) {
            vector<int> temp;
            
            for(int j=0; j<n; j++) {
                if(i & (1<<j))
                    temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        
        for(auto it: s) {
            ans.push_back(it);
        }
        return ans;
    }
};