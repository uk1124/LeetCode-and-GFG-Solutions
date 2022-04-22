class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        
        while(lo < hi) {
            int mid1 = (lo+hi) / 2;
            int mid2 = mid1+1;
            if(nums[mid1] < nums[mid2]) {
                lo = mid2;
            }
            else {
                hi = mid1;
            }
        }
        return lo;
    }
};