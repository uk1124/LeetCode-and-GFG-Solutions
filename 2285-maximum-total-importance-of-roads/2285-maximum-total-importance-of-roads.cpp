class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> connections(n, 0);
        
        // Count connections for each city
        for (auto &road : roads) {
            connections[road[0]]++;
            connections[road[1]]++;
        }
        
        // Create a vector of pairs (connections, index)
        vector<pair<int, int>> connIndex(n);
        for (int i = 0; i < n; ++i) {
            connIndex[i] = {connections[i], i};
        }
        
        // Sort the vector of pairs based on connections in descending order
        sort(connIndex.rbegin(), connIndex.rend());
        
        // Assign importance values to cities
        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[connIndex[i].second] = n - i;
        }
        
        // Calculate the total importance of all roads
        long long totalImportance = 0;
        for (auto &road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }
        
        return totalImportance;
    }
};