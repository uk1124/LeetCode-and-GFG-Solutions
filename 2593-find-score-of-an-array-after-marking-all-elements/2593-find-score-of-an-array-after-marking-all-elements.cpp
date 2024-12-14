class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<bool> marked(n, false);

        // Min-heap with (value, index) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // Push all elements into the heap with their indices
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Process the heap
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            // Skip if the index is already marked
            if (marked[idx]) continue;

            // Add the value to the score
            score += val;

            // Mark the current index and its neighbors
            marked[idx] = true;
            if (idx - 1 >= 0) marked[idx - 1] = true;
            if (idx + 1 < n) marked[idx + 1] = true;
        }

        return score;
    }
};
