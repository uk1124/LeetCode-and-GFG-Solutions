class Solution {
public:
    // APPROACH: Direct Implementation of Priority Queue
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int el: nums) {
            pq.push(el);
        }
        
        while(--k) {
            pq.pop();
        }
        return pq.top();
    }
};