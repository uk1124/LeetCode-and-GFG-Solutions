class Solution {
public:             // APPROACH: Using Binary Search
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minTime = 0;
        sort(time.begin(), time.end());
        long long l = 0;
        long long h = (long long) time.back() * totalTrips;
        
        while(l <= h) {
            long long mid = (l + h) / 2;
            long long count = 0;
            
            for(int i=0; i<time.size(); i++) {
                if(time[i] > mid) {
                    break;
                }
                count += (mid/time[i]);
            }
            if(count >= totalTrips) {
                minTime = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return minTime;
    }
};