class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessThanPivot;
        vector<int> greaterThanPivot;
        vector<int> equalThanPivot;

        for(int el: nums) {
            if(el < pivot) {
                lessThanPivot.push_back(el);
            }
            else if(el == pivot) {
                equalThanPivot.push_back(el);
            }
            else {
                 greaterThanPivot.push_back(el);
            }
        }

        vector<int> ans;
        for(int el: lessThanPivot) {
            ans.push_back(el);
        }
        for(int el: equalThanPivot) {
            ans.push_back(el);
        }
        for(int el: greaterThanPivot) {
            ans.push_back(el);
        }

        return ans;
    }
};