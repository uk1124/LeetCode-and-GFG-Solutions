class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(nums[mid] == target) {       // If key is present at middle point
                return mid;
            }
            if(nums[lo] <= nums[mid]) {
                if(target <= nums[mid] and target >= nums[lo])
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            
            else {
                if(target >= nums[mid] and target <= nums[hi])
                   lo = mid+1;
                
                else
                    hi = mid-1;
            }
            
        }
        return -1;
    }
};