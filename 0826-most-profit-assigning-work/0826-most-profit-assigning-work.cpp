class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Combine difficulty and profit into a single vector of pairs
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // Sort the jobs based on difficulty
        sort(jobs.begin(), jobs.end());

        // Sort the worker abilities
        sort(worker.begin(), worker.end());

        int maxProfit = 0;      // To track the maximum profit
        int maxProfitSoFar = 0; // To track the maximum profit for any
                                // difficulty encountered so far
        int jobIndex = 0;       // To iterate through the jobs

        // Iterate through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // For the current worker, check which jobs they can complete
            while (jobIndex < jobs.size() and
                   worker[i] >= jobs[jobIndex].first) {
                // Update the maximum profit so far for any job difficulty
                maxProfitSoFar = max(maxProfitSoFar, jobs[jobIndex].second);
                jobIndex++;
            }
            // Add the maximum profit the current worker can achieve
            maxProfit += maxProfitSoFar;
        }

        return maxProfit;
    }
};