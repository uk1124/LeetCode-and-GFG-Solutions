class Solution {
public:
/*APPRAOCH: Perform a binary search over possible candy sizes from 1 to the maximum candy in any pile. 
For each candidate size, sum how many piles of that size we can form by taking floor(candy/candidate) for each pile,
and if that total is at least k, we update our answer and try a larger size; otherwise, we try a smaller size.
*/
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1;
        int hi = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            // Calculate how many piles of size 'mid' we can form
            for (int candy : candies) {
                count += candy / mid;
                if (count >= k) break;   // Early break if we've reached k to save time
            }
            // If it's possible to give each child 'mid' candies
            if (count >= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
