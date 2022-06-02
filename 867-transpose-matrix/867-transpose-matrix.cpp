class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> tMatrix(N, vector<int> (M, 0));
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                tMatrix[i][j] = matrix[j][i];
            }
        }
        return tMatrix;
    }
};