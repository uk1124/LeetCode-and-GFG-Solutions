class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m*n - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int mid_value = matrix[mid/n][mid%n];
            if(mid_value == target) {
                return true;
            }
            else if(target < mid_value) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return false;
    }
};