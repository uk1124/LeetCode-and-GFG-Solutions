class Solution {
public:
    // APPROACH: Break the problem in two BS for the begining and end of the range, respectively
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> ans = {-1, -1};
        
        if(nums.size() == 0) {
            return ans;
        }
        
        while (i < j) {                     // Search for the left one, i.e 1st BS
            int mid = (i + j) /2;
            if (nums[mid] < target) {
                i = mid + 1;
            }
            
            else {
                j = mid;
            }
        }
        
        if (nums[i] != target) {
            return ans;
        }
        else {
            ans[0] = i;
        }
                                            // Search for the right one, i.e 2nd BS
        j = n-1;                            // No need to set i to 0 the second time
        while (i < j) {
            int mid = (i + j) / 2 + 1;	    
            if (nums[mid] > target) {
                j = mid - 1;
            }
            else {                          
                i = mid;
            }
        }
        ans[1] = j;
        return ans; 
    }
};