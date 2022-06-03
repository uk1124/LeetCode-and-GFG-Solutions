class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 and j >= 0) {  //Go from the back by A & B and compare and put to the A element which is larger
            if(A[i] > B[j]) { 
                A[k--] = A[i--];
            } 
            else {
                A[k--] = B[j--];
            }
        }
        while(j >= 0) { //If B is longer than A copy the rest of B to A location, otherwise no need to do anything
            A[k--] = B[j--];
        }
    }
};