class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); // Sorting the points based on the starting position

        int arrows = 0; // Initializing the count of arrows
        int i = 0;      // Initializing the index
        
        // Iterating through the points
        while(i < points.size()) {
            int currentEnd = points[i][1]; // Current balloon's end position
            
            int j = i+1; // Incrementing the index
            
            // Checking for overlapping balloons
            while (j < points.size() and points[j][0] <= currentEnd) {
                // Updating the end position
                currentEnd = min(currentEnd, points[j][1]);
                j++;
            }
            
            arrows++; // Incrementing the count of arrows
            i = j;    // Updating the index
        }
        
        return arrows;
    }
};
