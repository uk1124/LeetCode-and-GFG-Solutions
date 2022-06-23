class Solution {
public:
    //APPROACH: Using Heap (Min-heap)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n-1; i++) {
            int diff = heights[i+1] - heights[i];
            if(diff > 0) {
                pq.push(diff);
            }
            if(pq.size() > ladders) {           //It means we have to use bricks for one move.
                bricks -= pq.top();             //Pop out the smallest difference, and reduce bricks
                pq.pop();
            }
            if(bricks < 0)                      //We can't make this move, we have to return current index i
                return i;
        }
        return n-1;                             //It means we can reach the last building
    }
};