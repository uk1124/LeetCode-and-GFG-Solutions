class Solution {
public:
    /*APPROACH: Using Binary Search.
    The smallest capacity (lo) is the weight of the largest package.
    The largest capacity (hi) we may even need is the sum of weights of all packages.
    Our result is within this interval.
    */
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int w: weights) {
            sum += w;
        }
        int lo = *max_element(weights.begin(), weights.end());
        int hi = sum;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2, need = 1, curr = 0;
            
            for(int w: weights) {
                if(curr + w > mid) {
                    need += 1;
                    curr = 0;
                }
                curr += w;
            }
            if(need > days) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};