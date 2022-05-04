class Solution {
public:
    //APPROACH: Using Backtracking
    void findCombinations(int start, int k, int target, vector<int>&ds, vector<vector<int>>&ans) {
         if(k == 0 and target == 0) {       // Got the answer
             ans.push_back(ds);
             return;
         }
        
        for(int i=start; i<=10-k and i<=target; i++) {
            ds.push_back(i);
            findCombinations(i+1, k-1, target-i, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        findCombinations(1, k, n, ds, ans);
        return ans;
    }
};