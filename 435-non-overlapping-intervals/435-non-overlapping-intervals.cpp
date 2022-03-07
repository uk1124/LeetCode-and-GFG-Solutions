class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int left = 0, right = 1;
        
       while(right < intervals.size())                           // Unless all intervals are compared
        {
            if(intervals[left][1] <= intervals[right][0]) {      // Non-overlapping case 
                left = right;
                right++;
            }
            else if(intervals[left][1] <= intervals[right][1]) { // Overlapping - Remove right interval
                count++;                                         //   Delete right
                right++;
            }
            else if(intervals[left][1] > intervals[right][1]) {  // Overlapping - Remove left interval
                count++;
                left = right;
                right++;
            }
        }
        return count;
    }
};