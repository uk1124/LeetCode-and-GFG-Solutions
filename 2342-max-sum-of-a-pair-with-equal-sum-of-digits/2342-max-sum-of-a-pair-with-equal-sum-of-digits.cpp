class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, vector<int>> mp;
        
        for(int i=0; i<n; i++) {
            int t = nums[i];
            int sum = 0;
            while(t) {
                int rem = t%10;
                sum += rem;
                t /= 10;
            }
            mp[sum].push_back(nums[i]);
        }
        
        int ans = INT_MIN;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            int sum = 0;
            if((it->second).size() > 1) {
                for(int i=0; i<(it->second).size()-1; i++) {
                    sum = max(sum, (it->second)[i] + (it->second)[i+1]);
                }
                ans = max(sum, ans);
            }
        }
        return ans == INT_MIN? -1: ans;
    }
};