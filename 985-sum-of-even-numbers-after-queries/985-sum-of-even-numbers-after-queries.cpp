class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0, N = queries.size();
        for(int el : nums) {
            if(el % 2 == 0) {
                sum += el;
            }
        }
        vector<int> ans(N, 0);
        
        //Four cases to handle.
        for(int i = 0; i < N; i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            int oldValue = nums[index];
            nums[index] += val;
            
            bool wasEven = (oldValue % 2) == 0;
            bool nowEven = (nums[index] % 2) == 0;
            
            if(wasEven and nowEven) {
                ans[i] = sum + val;
                sum += val;
            } 
            else if(!wasEven and nowEven) {
                ans[i] = sum + nums[index];
                sum += nums[index];
            } 
            else if(wasEven and !nowEven) {
                ans[i] = sum - oldValue;
                sum -= oldValue;
            } 
            else {
                ans[i] = sum;
            }
        }
        return ans;
    }
};