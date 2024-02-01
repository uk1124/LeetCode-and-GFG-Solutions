class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Sort the input array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        // Check each window of size 3
        for (int i = 0; i < nums.size(); i += 3) {
            // Check the difference between the first and last element in the window
            if (i + 2 < nums.size() and abs(nums[i] - nums[i + 2]) > k) {
                // If the condition is not satisfied, return an empty vector
                return {};
            }
            // Add the current window to the result
            ans.push_back({nums[i], nums[i+1], nums[i + 2]});
        }

        return ans;
    }
};
