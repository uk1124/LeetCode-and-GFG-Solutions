class Solution {
public:
    /*APPROACH: Binary Search to find the minimum k
    if hours > h, that indicates k is too small, then low = k + 1
    if hours < h, that indicates k is too large, then high = k - 1
    if hours == h, we can try a smaller k, then also high = k - 1 
    intuitively, we can initialize low = 1, high = 1000000000 */
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1000000000;
        
        while(lo < hi){
            int mid = (lo + hi) / 2;
            int val = 0;
            for(auto x : piles) {
                val += (x + mid - 1) / mid; 
            }
            if(val <= h) {
                hi = mid; 
            }
            else {
                lo = mid + 1; 
            }
        }
        return lo;
    }
};