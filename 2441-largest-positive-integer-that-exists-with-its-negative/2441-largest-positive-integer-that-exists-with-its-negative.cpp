class Solution {
public:
//APPROACH: Using Binary Search
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size()-1;
        
        while(lo < hi) {
            if(nums[lo] + nums[hi] == 0) {
                return  nums[hi];
            }
            else if(nums[lo] + nums[hi] < 0) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return -1;
    }
};