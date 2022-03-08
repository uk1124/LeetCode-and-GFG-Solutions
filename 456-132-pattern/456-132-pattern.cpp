class Solution {
public:
    // APPROACH:  Start from end and search for valid (s2,s3) pairs, we just need to remember the largest valid s3 value.
    bool find132pattern(vector<int>& nums) {
        stack <int> s;
        int prev = INT_MIN;
        
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] < prev ) {
                return true;
            }
            while (!s.empty() and nums[i] > s.top()) {
                prev = s.top ();
                s.pop();
            }   
            s.push(nums[i]);
        }
        return false;
    }
};