class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if (i == 0 or (i > 0 and nums[i] != nums[i-1])) {
                int lo = i+1;
                int hi = nums.size() - 1;
                int sum = -nums[i];         // Fix one and find other two
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        ans.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi and nums[lo] == nums[lo+1]) { // To avoid duplicates
                            lo++;
                        }
                        while (lo < hi and nums[hi] == nums[hi-1]) { // To avoid duplicates
                            hi--;
                        }
                        lo++; 
                        hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum) {
                        lo++;
                    }
                    else {
                        hi--;
                    }
                }
            }
        }
         return ans;
    }
};