class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                for(int j=0; j<nums.size(); j++) {
                    if(nums[i] == -1*nums[j]) {
                        maxi = max(maxi, nums[i]);
                    }
                }
            }
        }
        return maxi;
    }
};