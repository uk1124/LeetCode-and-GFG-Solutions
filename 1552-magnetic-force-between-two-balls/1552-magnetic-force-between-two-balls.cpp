class Solution {
public:
//APPROACH: Using Binary Search
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // Sort the positions of the baskets

        // Binary search initialization
        int lo = 1; // Minimum possible distance
        int hi = position.back() - position.front(); // Maximum possible distance

        // Binary search for the maximum minimum distance
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlaceBalls(mid, m, position)) {
                lo = mid + 1; // Try for a larger distance
            } 
            else {
                hi = mid - 1; // Try for a smaller distance
            }
        }

        return hi; // The largest possible minimum distance
    }

    // Helper function to check if we can place m balls with at least 'dist' apart
    bool canPlaceBalls(int dist, int m, vector<int>& position) {
            int count = 1; // Place the first ball in the first basket
            int last_position = position[0];

            for (int i = 1; i < position.size(); ++i) {
                if (position[i] - last_position >= dist) {
                    count++; // Place another ball
                    last_position = position[i]; // Update the position of the last placed ball
                    if (count == m) {
                        return true; // Successfully placed all m balls
                    }
                }
            }
            return false; // Couldn't place all m balls with at least 'dist' apart
        };
};
