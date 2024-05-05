class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        int n = s.size();
        unordered_map<string, int> mp;
        int maxFreq = 0;    // To keep track of the maximum frequency of any substring of length k
        int Totalcount = 0; // To count the total number of substrings of length k

        // Iterate through the string with a step of k
        for(int i = 0; i < n; i += k) {
            string t = s.substr(i, k);     // Extract substring of length k
            mp[t]++;      // Count occurrences of this substring
            maxFreq = max(maxFreq, mp[t]); // Update max frequency
            Totalcount++; // Increment total substring count
        }
    
        // Return the difference between the total count and the max frequency
        return Totalcount - maxFreq;
    }
};
