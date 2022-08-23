class Solution {
public:
    int solveMem(int currIndx, vector<int> &freq, unordered_map<int, int> &dp) {
        if(currIndx >= freq.size()) {
            return 0;
        }
        
        int key = currIndx;
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        int Delete = currIndx * freq[currIndx] + solveMem(currIndx+2, freq, dp);
        int notDelete = solveMem(currIndx+1, freq, dp);
        
        return dp[key] = max(Delete, notDelete);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0);
        unordered_map<int, int> dp;
        
        for(int el: nums) {
            freq[el]++;
        }
        return solveMem(0, freq, dp);
    }
};