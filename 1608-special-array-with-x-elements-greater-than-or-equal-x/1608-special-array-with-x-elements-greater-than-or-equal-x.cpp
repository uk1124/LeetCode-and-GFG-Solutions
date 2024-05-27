class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Initialize an array to count the frequency of each number in nums.
        int arr[1001] = {0};  // Given the constraints, we can have numbers from 0 to 1000.
        
        // Count the occurrences of each number in nums.
        for(int num : nums) {
            arr[num]++;
        }
        
        // Total number of elements in nums.
        int total = nums.size();
        
        // Iterate over the possible values of x (from 0 to 1000).
        for(int i = 0; i < 1001; i++) {
            // Check if the current value of i matches the number of elements >= i.
            if(i == total) {
                return i; // Found the special number x.
            }
            // Subtract the count of numbers that are equal to the current i
            // from the total count to update the count of numbers greater than the next value of i.
            total -= arr[i];
        }
        
        // If no such special number x is found, return -1.
        return -1;
    }
};