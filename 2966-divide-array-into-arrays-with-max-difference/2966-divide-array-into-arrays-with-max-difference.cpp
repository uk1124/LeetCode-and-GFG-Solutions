class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // Check each window of size 3
        for (int i = 0; i < nums.size(); i += 3) {
            // Check the difference between the first and last element in the window
            if (i + 2 < nums.size() and abs(nums[i] - nums[i + 2]) > k) {
                // If the condition is not satisfied, return an empty vector
                return {};
            }
        }

        // If all windows are valid, construct and return the answer
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            vector<int> temp;
            for (int j = i; j < i + 3; j++) {
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
