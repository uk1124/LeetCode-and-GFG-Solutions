class Solution {
public:
    void findCombinations(int start, int k, int target, vector<int>&ds, vector<vector<int>>&ans) {
         if(k == 0 and target == 0) {
             ans.push_back(ds);
             return;
         }
        // if(target < 0 or ds.size() > k) {
        //     return;
        // }
      
        for(int i=start; i<=10-k and i<=target; i++) {
            ds.push_back(i);
            findCombinations(i+1, k-1, target-i, ds, ans);
            ds.pop_back();
        }
        // findCombinations(i+1,k,target-nums[i],ds,nums);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        vector<vector<int>> ans;
        findCombinations(1, k, n, ds, ans);
        return ans;
    }
};