class Solution {
public:
    /*APPROACH: Using Min heap.
    Since each of the rows in matrix are already sorted, we can understand the problem as finding the kth smallest
    element from amongst M sorted rows.
    We start the pointers to point to the beginning of each rows, then we iterate k times, for each time ith, the
    top of the minHeap is the ith smallest element in the matrix. We pop the top from the minHeap then add the next
    element which has the same row with that top to the minHeap.*/
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int m = matrix.size(), n = matrix[0].size(), ans;
        
        for(int i=0; i<min(m, n); i++) {
            pq.push({matrix[i][0], i, 0});
        }
        
        while(k--) {
            auto top = pq.top(); 
            pq.pop();
            int r = top[1];
            int c = top[2];
            ans = top[0];
            if(c+1 < n) {
                pq.push({matrix[r][c+1], r, c+1});
            }
        }
        return ans;
    }
    // TC: O(K*logK)  SC: O(K)
};