class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on their start times
        
        int i = 0; // Initialize a variable to iterate through the intervals
        while (i < intervals.size()) {
            int start = intervals[i][0]; // Store the start time of the current interval
            int end = intervals[i][1];   // Store the end time of the current interval
            
            // Check if there is an overlapping interval
            while (i+1 < intervals.size() and intervals[i+1][0] <= end) {
                // Update the end time if the next interval overlaps with the current one
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            // Push the merged interval [start, end] to the answer vector
            ans.push_back({start, end});
            i++;
        }
        return ans;
    }
};
