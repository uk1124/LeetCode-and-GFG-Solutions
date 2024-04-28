class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        // Sort both arrays for easier comparison
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n = nums1.size();
        int ans = INT_MAX; // Stores the final result
        // Calculate potential differences between nums2[0] and elements of nums1
        vector<int> diffs = { nums2[0] - nums1[0], nums2[0] - nums1[1], nums2[0] - nums1[2] };
        
        // Loop through potential differences
        for (auto diff : diffs) {
            int j = 0;       // Index for nums2
            int deleted = 0; // Count of elements deleted from nums1
            
            // Compare nums1 and nums2
            for (int i = 0; i < n and j < n-2; i++) {
                // If the difference b/w corresponding elements is not equal to diff, increment deleted count
                if (nums2[j] - nums1[i] != diff) {
                    deleted++;
                } 
                else {
                    // Move to the next element in nums2
                    j++;
                }
                // If more than two elements are deleted, break the loop
                if (deleted > 2) {
                    break;
                }
            }
            
            // If j reaches n-2, it indicates a match between nums1 and nums2 after removal of two elements, update ans accordingly
            if (j == n-2) {
                ans = min(ans, diff);
            }
        }
        
        // Return the minimum valid diff as the minimum added integer x
        return ans;
    }
};
