class Solution {
public:
/* (IT'S A VARIANT OF TWO SUM)
APPROACH: Utilize a hash map to count the frequency of each number in the array. Then, iterate 
through the array to find pairs that sum up to the target value k. Then calculate the number of such 
pairs using the complement technique and return the total count of operations performed.
TC: O(N)
*/ 
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Store the frequency of each number
        int operations = 0;           // Initialize the count of operations
        
        // Count the frequency of each number in the array
        for(int num : nums) {
            freq[num]++;
        }
        
        // Iterate through the array to find pairs that sum up to k
        for(auto pair : freq) {
            int num = pair.first;    // Current number
            int count = pair.second; // Frequency of the current number
            
            // If the number is less than or equal to k and there's a complement in the map
            if(num <= k and freq.count(k - num) > 0) {
                // If the complement is the same as the current number
                if (num == k - num) {
                    // Calculate the number of pairs that can be formed
                    operations += count / 2;
                } 
                else {
                    // Otherwise, take the minimum of the frequency of the current number & its complement
                    operations += min(count, freq[k - num]);
                }
                // Mark both the current number and its complement as used
                freq[num] = 0;
                freq[k - num] = 0;
            }
        }
        
        return operations;
    }
};
