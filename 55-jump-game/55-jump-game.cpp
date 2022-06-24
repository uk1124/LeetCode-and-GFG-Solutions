class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currIdx = 0;
        for(int i=0; currIdx < nums.size() and currIdx <= i; currIdx++) {
            i = max(currIdx + nums[currIdx], i);
        }
        
        if(currIdx == nums.size()) {
            return true;
        }
        return false;
    }
};