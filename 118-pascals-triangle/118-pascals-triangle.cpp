class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0; i<numRows; i++) {
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++) { //1st & last elements will be 1, rest will be sum of two elements from above row
                temp[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};