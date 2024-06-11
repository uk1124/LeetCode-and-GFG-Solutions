class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        vector<int> result;

        // Count the frequency of each element in arr1
        for (int el : arr1) {
            countMap[el]++;
        }

        // Add elements from arr2 in the order they appear, using the frequency count from countMap
        for (int el : arr2) {
            while (countMap[el] > 0) {
                result.push_back(el);
                countMap[el]--;
            }
            countMap.erase(el);
        }

        // Collect remaining elements not in arr2
        vector<int> remainingElements;
        for (auto pair : countMap) {
            for (int i = 0; i < pair.second; i++) {
                remainingElements.push_back(pair.first);
            }
        }

        // Sort the remaining elements in ascending order
        sort(remainingElements.begin(), remainingElements.end());

        // Append the sorted remaining elements to the result
        for(int i=0; i<remainingElements.size(); i++) {
            result.push_back(remainingElements[i]);
        }

        return result;
    }
};