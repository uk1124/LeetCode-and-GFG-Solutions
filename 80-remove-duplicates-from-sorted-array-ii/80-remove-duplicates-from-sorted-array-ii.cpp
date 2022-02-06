class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        if(n <= 2) {
            return n;
        }
        int index = 2;
        for(int i = 2; i < nums.size(); i++) {      
             if(nums[i] != nums[index-2]) {  
                 nums[index++] = nums[i];
             }
        }
        return index;
    }
};