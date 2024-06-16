class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < n) {
            if(i+1 < n and nums[i] == nums[i+1]) {
                ans++;
                nums[i+1] += 1;
                sort(nums.begin(), nums.end());
                i -= 1;
            }
            i++;
        }

        return ans;
    }
};