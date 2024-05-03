class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;     // If there are 2 or fewer points, they all lie on the same line
        
        int maxPointsOnLine = 2;  // At least 2 points will lie on the same line
        
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> slopeCount; // Map to store slope frequency for each point
            
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int dx = points[j][0] - points[i][0];  // Change in x-coordinate
                    int dy = points[j][1] - points[i][1];  // Change in y-coordinate
                    
                    double slope;
                    if (dx == 0) {
                        slope = INT_MAX; // Vertical line, slope is infinity
                    } 
                    else {
                        slope = (double)dy / dx; // Calculate slope
                    }
                    
                    slopeCount[slope]++;         // Increment slope count
                }
            }
            
            // Find the maximum number of points that lie on the same line
            for (auto &[slope, count] : slopeCount) {
                maxPointsOnLine = max(maxPointsOnLine, count + 1); // Add 1 to count for the current point
            }
        }
        
        return maxPointsOnLine;
    }
};
