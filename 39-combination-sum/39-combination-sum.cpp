class Solution {
public:
    
     void sum(vector<int>&candidates,int target, vector<int>&r, vector<vector<int>>&ans,int i){
        if(target == 0) {
            ans.push_back(r);           // Got the answer
            return;
        }
         
         while(i < candidates.size() and target - candidates[i] >= 0) {
             r.push_back(candidates[i]);
             
             sum(candidates, target - candidates[i], r, ans, i);
             ++i;
             
             r.pop_back();          // Backtracking
         }    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());      // Sorting and Removing duplicates
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end()); 
        
        vector<int> r;
        vector<vector<int>> ans;
        
        sum(candidates, target, r, ans, 0);
        return ans;
    }
};