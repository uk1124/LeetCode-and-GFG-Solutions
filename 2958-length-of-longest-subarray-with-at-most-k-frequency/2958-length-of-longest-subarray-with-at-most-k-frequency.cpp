class Solution {
public:
//APPROACH: Using Sliding Window
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> count; // Map to store the counts of elements
        int ans = 0, temp_ans = 0;
        
        while (right < n) {
            // Increment the count of nums[right]
            count[nums[right]]++;
            temp_ans++;
            
            // Shrink the window if the count of any element exceeds k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                temp_ans--;
                left++;
            }
            // Update the answer
            ans = max(ans, temp_ans);
            right++;
        }
        return ans;
    }
};
