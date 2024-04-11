class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int lo = 0;
        int hi = n;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                 lo = mid+1; 
            }
            else {
                hi = mid-1; 
            }
        }
        return lo;                  // At this point lo > hi, i.e lo >= hi+1, so we can also return hi+1
    }
};