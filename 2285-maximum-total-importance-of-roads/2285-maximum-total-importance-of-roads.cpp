class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> cityConnections;
        
        // Count connections for each city
        for (auto &road : roads) {
            cityConnections[road[0]]++;
            cityConnections[road[1]]++;
        }
        
        // Create a vector of pairs (city, connections) and sort it by connections
        vector<pair<int, int>> cities;
        for (int i = 0; i < n; ++i) {
            cities.push_back({i, cityConnections[i]});
        }
        
        // Sort cities by the number of connections in descending order
        sort(cities.begin(), cities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        // Assign importance values to cities based on their rank
        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[cities[i].first] = n - i;
        }
        
        // Calculate the total importance of all roads
        long long totalImportance = 0;
        for (auto &road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }
        
        return totalImportance;
    }
};
