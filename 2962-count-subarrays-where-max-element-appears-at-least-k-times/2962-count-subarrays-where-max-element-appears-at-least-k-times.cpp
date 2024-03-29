class Solution {
public:
//APPROACH: Using Sliding Window
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0;
        long long ans = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            freq[nums[right]]++;    // Update frequency of current element
            right++;    // Expand the window

            // Shrink the window from the left until the frequency condition is satisfied
            while (freq[maxi] >= k) {
                ans += (n - right + 1);   // Update count
                freq[nums[left]]--;     // Reduce frequency of left element
                left++;     // Shrink the window
            }
        }
        return ans;
    }
};