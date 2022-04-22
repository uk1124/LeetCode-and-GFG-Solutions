class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        
        if(nums[0] > nums[1]) {
            return 0;
        }
        if(nums[n-1] > nums[n-2]) {
            return n-1;
        }
        
        int lo = 1;
        int hi = n-2;
        
        while(lo <= hi) {
            int mid = (lo+hi) / 2;
            if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) {
                return mid;
            }
            else if(nums[mid] < nums[mid-1]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};